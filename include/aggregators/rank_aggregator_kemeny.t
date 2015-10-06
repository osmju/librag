#ifdef _LIB_RAG_RANK_AGGREGATOR_KEMENY_T_

/*=============================================================================*/

template <class T>
AggregatorKemeny<T>::AggregatorKemeny()
: RankAggregator<T>(), is_mapping_built_(false), initial_aggregation_("median") {}

/*=============================================================================*/

template <class T>
AggregatorKemeny<T>::~AggregatorKemeny() {}

/*=============================================================================*/

template <class T>
void AggregatorKemeny<T>::aggregate() {
	Base::build_ranking_map();
	is_mapping_built_ = true;

	// first create initial aggregation
	typename RankAggregator<T>::ptr initial_aggregator = RankAggregator<T>::create(initial_aggregation_);

	//cout << "Running initial rank aggregation: " << initial_aggregation_ << endl;

	for (int i = 0; i < Base::nb_rankings_; ++i) {
		initial_aggregator->add_ranking(Base::rankings_[i]);
	}

	initial_aggregator->aggregate();

	const typename Base::rlist_ptr init_aggregation = initial_aggregator->get_aggregation();

	// copy aggregation in new list
	typename Base::rlist lcopy;

	for (T item : *init_aggregation) {
		lcopy.push_back(item);
	}

	// now local-kemenize the median aggregation to get an optimal ranking
	// with respect to the input lists.
	//cout << "Computing Local-Kemenization.\n";

	int nb_items = lcopy.size();

	for (int i = 1; i < nb_items; ++i) {
		int j = i;

		// bubble sort local kemeny implementation
		// Another implementation is based on graph theory.
		while (j > 0 && is_preferred(lcopy[j], lcopy[j-1])) {
			swap(lcopy, j, j-1);
			--j;
		}
	}

	Base::aggregated_list_->clear();

	for (T item : lcopy) {
		Base::aggregated_list_->push_back(item);
	}
}

/*=============================================================================*/

template <class T>
bool AggregatorKemeny<T>::is_preferred(T item1, T item2) {
	if (!is_mapping_built_) {
		Base::build_ranking_map();
		is_mapping_built_ = true;
	}

	int pref_accumulator = 0;
	ivectptr ranks_item1 = Base::objects_ranks_[item1];
	ivectptr ranks_item2 = Base::objects_ranks_[item2];

	for (int i = 0; i < Base::nb_rankings_; ++i) {
		// check whether item1 is preferred over item2 in each list
		if (ranks_item1->at(i) < ranks_item2->at(i)) ++pref_accumulator;
	}

	if (pref_accumulator > (Base::nb_rankings_ / 2)) // majority prefers item1 over item2
		return true;

	return false;
}

/*=============================================================================*/

template <class T>
void AggregatorKemeny<T>::swap(typename Base::rlist& list, int index1, int index2) {
	int list_size = list.size();

	if (index1 < 0 || index1 >= list_size || index2 < 0 || index2 >= list_size)
		throw std::runtime_error("Out of list bounds");

	T temp = list[index1];
	list[index1] = list[index2];
	list[index2] = temp;
}

/*=============================================================================*/

template <class T>
void AggregatorKemeny<T>::set_initial_aggregation(std::string initial_aggregation) {
		initial_aggregation_ = initial_aggregation;
}

/*=============================================================================*/

#else  /* _LIB_RAG_RANK_AGGREGATOR_KEMENY_T_ */
#error
#endif  /* _LIB_RAG_RANK_AGGREGATOR_KEMENY_T_ */
