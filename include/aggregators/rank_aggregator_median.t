// Copyright (C) 2016   Julien Osmalskyj
//
// This file is part of LibRAG.
//
// LibRAG is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LibRAG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with LibRAG.  If not, see http://www.gnu.org/licenses.

#ifdef _LIB_RAG_RANK_AGGREATOR_MEDIAN_T_

/*=============================================================================*/

template <class T>
AggregatorMedian<T>::AggregatorMedian()
: RankAggregator<T>() {}

/*=============================================================================*/

template <class T>
AggregatorMedian<T>::~AggregatorMedian() {}

/*=============================================================================*/

template <class T>
void AggregatorMedian<T>::aggregate() {
	Base::build_ranking_map();
	Base::aggregated_list_->clear();
	typename Base::rating median_scores;
	int nb_objects = Base::lists_max_size();

	for (auto item : Base::objects_ranks_) {
		T key = item.first;
		ivectptr ranks = item.second;
		float ranks_median = median(ranks);

		typename Base::object_score current_item_score(ranks_median, key);
		median_scores.push_back(current_item_score);
	}

	sort(median_scores.begin(), median_scores.end());

	// now build final list
	for (int i = 0; i < nb_objects; ++i) {
		T object = std::get<1>(median_scores[i]);
		Base::aggregated_list_->push_back(object);
	}
}

/*=============================================================================*/

template <class T>
float AggregatorMedian<T>::median(const ivectptr ranks) const {
	int nb_ranks = ranks->size();
	float final_rank = 0.0;

	sort(ranks->begin(), ranks->end());

	if (nb_ranks % 2 == 0) {
		final_rank = (ranks->at(nb_ranks/2 - 1) + ranks->at(nb_ranks/2)) / 2;
	}
	else {
		final_rank = ranks->at(nb_ranks / 2);
	}

	return final_rank;
}

/*=============================================================================*/

#else  /* _LIB_RAG_RANK_AGGREATOR_MEDIAN_T_ */
#error
#endif /* _LIB_RAG_RANK_AGGREATOR_MEDIAN_T_ */
