#include <iostream>
#include <algorithm>
#include "aggregators/rank_aggregator_borda.h"
#include "aggregators/rank_aggregator_mean.h"
#include "aggregators/rank_aggregator_median.h"
#include "aggregators/rank_aggregator_kemeny.h"

using namespace std;
using namespace rag;

/*=============================================================================*/

template <class T>
RankAggregator<T>::RankAggregator()
: nb_rankings_(0) {}

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
		throw runtime_error("Ranking index is out of bounds.");

	return rankings_[ranking_id];
}

/*=============================================================================*/

template <class T>
int RankAggregator<T>::nb_rankings() const {
		return nb_rankings_;
}

/*=============================================================================*/

template <class T>
typename RankAggregator<T>::ptr RankAggregator<T>::create(string name) {
	if (name == "borda") {
		return RankAggregator<T>::ptr(new AggregatorBorda<T>());
	}
	else if (name == "mean") {
		return RankAggregator<T>::ptr(new AggregatorMean<T>());
	}
	else if (name == "median") {
		return RankAggregator<T>::ptr(new AggregatorMedian<T>());
	}
	else if (name == "kemeny") {
		return RankAggregator<T>::ptr(new AggregatorKemeny<T>());
	}
	else {
		throw runtime_error("Wrong aggregator identifier.");
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
			catch (out_of_range& err) {
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
const typename RankAggregator<T>::rlist RankAggregator<T>::get_aggregation() const {
	return aggregated_list_;
}

/*=============================================================================*/

template <class T>
typename RankAggregator<T>::rlist_ptr RankAggregator<T>::new_rlist() {
	return typename RankAggregator<T>::rlist_ptr(new typename RankAggregator<T>::rlist);
}

/*=============================================================================*/
