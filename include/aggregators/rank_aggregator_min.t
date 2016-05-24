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

#ifdef _LIB_RAG_RANK_AGGREGATOR_MIN_T_

/*=============================================================================*/

template <class T>
AggregatorMin<T>::AggregatorMin()
: RankAggregator<T>() {}

/*=============================================================================*/

template <class T>
AggregatorMin<T>::~AggregatorMin() {}

/*=============================================================================*/

template <class T>
void AggregatorMin<T>::aggregate() {
	Base::build_ranking_map();
	Base::aggregated_list_->clear();
	typename Base::rating min_scores;
	int nb_objects = Base::lists_max_size();

	for (auto item : Base::objects_ranks_) {
		T key = item.first;
		ivectptr ranks = item.second;
		int nb_ranks = ranks->size();
		float min = ranks->at(0);

		for (int i = 1; i < nb_ranks; ++i) {
			if (ranks->at(i) < min) min = ranks->at(i);
		}

		typename Base::object_score current_item_score(min, key);
		min_scores.push_back(current_item_score);
	}

	sort(min_scores.begin(), min_scores.end());

	// now build final list
	for (int i = 0; i < nb_objects; ++i) {
		T object = std::get<1>(min_scores[i]);
		Base::aggregated_list_->push_back(object);
	}
}

/*=============================================================================*/

#else  /* _LIB_RAG_RANK_AGGREGATOR_MIN_T_ */
#error
#endif /* _LIB_RAG_RANK_AGGREGATOR_MIN_T_ */
