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
