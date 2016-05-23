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

#ifdef _LIB_RAG_RANK_AGGREGATOR_BORDA_T_

/*=============================================================================*/

template <class T>
AggregatorBorda<T>::AggregatorBorda()
: RankAggregator<T>() {}

/*=============================================================================*/

template <class T>
AggregatorBorda<T>::~AggregatorBorda() {}

/*=============================================================================*/

template <class T>
void AggregatorBorda<T>::aggregate() {
	Base::build_ranking_map();
	Base::aggregated_list_->clear();
	typename Base::rating borda_scores;
	int nb_objects = Base::lists_max_size();

	for (auto item : Base::objects_ranks_) {
		T key = item.first;
		ivectptr ranks = item.second;
		int nb_ranks = ranks->size();
		int borda_score = 0;

		for (int i = 0; i < nb_ranks; ++i) {
			borda_score += (nb_objects - ranks->at(i));
		}

		typename Base::object_score current_item_score(borda_score, key);
		borda_scores.push_back(current_item_score);
	}

	sort(borda_scores.begin(), borda_scores.end());
	reverse(borda_scores.begin(), borda_scores.end());

	// now build final list
	for (int i = 0; i < nb_objects; ++i) {
		T object = std::get<1>(borda_scores[i]);
		Base::aggregated_list_->push_back(object);
	}
}

/*=============================================================================*/

#else  /* _LIB_RAG_RANK_AGGREGATOR_BORDA_T_ */
#error
#endif /* _LIB_RAG_RANK_AGGREGATOR_BORDA_T_ */
