#ifdef _LIB_RAG_RANK_AGGREGATOR_MEAN_T_

/*=============================================================================*/

template <class T>
AggregatorMean<T>::AggregatorMean()
: RankAggregator<T>() {}

/*=============================================================================*/

template <class T>
AggregatorMean<T>::~AggregatorMean() {}

/*=============================================================================*/

template <class T>
void AggregatorMean<T>::aggregate() {
	Base::build_ranking_map();
	Base::aggregated_list_->clear();
	typename Base::rating mean_scores;
	int nb_objects = Base::lists_max_size();

	for (auto item : Base::objects_ranks_) {
		T key = item.first;
		ivectptr ranks = item.second;
		int nb_ranks = ranks->size();
		float mean = 0;

		for (int i = 0; i < nb_ranks; ++i) {
			mean += static_cast<float>(ranks->at(i));
		}

		mean /= static_cast<float>(nb_ranks);


		typename Base::object_score current_item_score(mean, key);
		mean_scores.push_back(current_item_score);
	}

	sort(mean_scores.begin(), mean_scores.end());

	// now build final list
	for (int i = 0; i < nb_objects; ++i) {
		T object = std::get<1>(mean_scores[i]);
		Base::aggregated_list_->push_back(object);
	}
}

/*=============================================================================*/

#else  /* _LIB_RAG_RANK_AGGREGATOR_MEAN_T_ */
#error
#endif /* _LIB_RAG_RANK_AGGREGATOR_MEAN_T_ */
