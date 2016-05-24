// Copyright (C) 2016   Julien Osmalskyj
//
// This file is part of LibRAG.
//
// LibRAG is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LibRAG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with LibRAG.  If not, see http://www.gnu.org/licenses.

#ifdef _LIB_RAG_RANK_AGGREGATOR_T_

/*=============================================================================*/

template <class T>
RankAggregator<T>::RankAggregator()
: nb_rankings_(0) {
	aggregated_list_ = rlist_ptr(new rlist);
}

/*=============================================================================*/

template <class T>
RankAggregator<T>::~RankAggregator() {}

/*=============================================================================*/

template <class T>
void RankAggregator<T>::add_ranking(const rlist* ranking) {
	rankings_.push_back(ranking);
	++nb_rankings_;
}

/*=============================================================================*/

template <class T>
const typename RankAggregator<T>::rlist* RankAggregator<T>::get_ranking(int ranking_id) const {
	if (ranking_id > nb_rankings_)
		throw std::runtime_error("Ranking index is out of bounds.");

	return rankings_[ranking_id];
}

/*=============================================================================*/

template <class T>
int RankAggregator<T>::nb_rankings() const {
		return nb_rankings_;
}

/*=============================================================================*/

template <class T>
typename RankAggregator<T>::ptr RankAggregator<T>::create(std::string name) {
	if (name == "borda") {
		return typename RankAggregator<T>::ptr(new AggregatorBorda<T>());
	}
	else if (name == "mean") {
		return typename RankAggregator<T>::ptr(new AggregatorMean<T>());
	}
	else if (name == "median") {
		return typename RankAggregator<T>::ptr(new AggregatorMedian<T>());
	}
	else if (name == "min") {
		return typename RankAggregator<T>::ptr(new AggregatorMin<T>());
	}
	else if (name == "kemeny-median" ||
					  name == "kemeny-mean"   ||
					  name == "kemeny-borda"  ||
					  name == "kemeny-min") {

		typename RankAggregator<T>::ptr aggregator =
				typename RankAggregator<T>::ptr(new AggregatorKemeny<T>());

		if (name == "kemeny-median")
			aggregator->set_initial_aggregation("median");
		else if (name == "kemeny-mean")
			aggregator->set_initial_aggregation("mean");
		else if (name == "kemeny-borda")
			aggregator->set_initial_aggregation("borda");
		else if (name == "kemeny-min")
			aggregator->set_initial_aggregation("min");

		return aggregator;
	}
	else {
		throw std::runtime_error("Wrong aggregator identifier.");
	}
}

/*=============================================================================*/

template <class T>
int RankAggregator<T>::lists_max_size() const {
	ivect lists_sizes;

	for (int i = 0; i < nb_rankings_; ++i) {
		const rlist* current_list = rankings_[i];
		lists_sizes.push_back(current_list->size());
	}

	return *max_element(lists_sizes.begin(), lists_sizes.end());
}

/*=============================================================================*/

template <class T>
void RankAggregator<T>::build_ranking_map() {
	objects_ranks_.clear();

	for (int i = 0; i < nb_rankings_; ++i) {
		// browse current list and update objects_ranks
		const rlist* current_ranking = rankings_[i];
		int ranking_size = current_ranking->size();

		// browse current ranking
		for (int j = 0; j < ranking_size; ++j) {
			int current_rank = j + 1;
			T key = current_ranking->at(j);

			// try to access the element with key in objects_ranks
			try {
				// if the key exists, update its ranks list
				ivectptr ranks = objects_ranks_.at(key);
				ranks->push_back(current_rank);
			}
			catch (std::out_of_range& err) {
				// if the key does not exist, create an entry with that key
				ivectptr ranks = ivectptr(new ivect);

				ranks->push_back(current_rank);

				objects_ranks_[key] = ranks;
			}
		}
	}

	// DEBUG
//	cout << objects_ranks_.size() << endl;
//
//	for (auto item : objects_ranks_) {
//		T key = item.first;
//		ivectptr ranks = item.second;
//
//		cout << key << " :: [";
//
//		for (int i = 0; i < ranks->size(); ++i) {
//			cout << ranks->at(i) << ", ";
//		}
//
//		cout << "]\n";
//	}
}

/*=============================================================================*/

template <class T>
typename RankAggregator<T>::rlist_ptr RankAggregator<T>::get_aggregation() const {
	RankAggregator<T>::rlist_ptr result = aggregated_list_;
	return result;
}

/*=============================================================================*/

template <class T>
typename RankAggregator<T>::rlist_ptr RankAggregator<T>::new_rlist() {
	return typename RankAggregator<T>::rlist_ptr(new typename RankAggregator<T>::rlist);
}

/*=============================================================================*/

#else  /* _LIB_RAG_RANK_AGGREGATOR_T_ */
#error
#endif /* _LIB_RAG_RANK_AGGREGATOR_T_ */
