#ifdef _LIB_RAG_AGGREGATOR_LIST_T_

#include <iostream>

using namespace std;

/*=============================================================================*/

template <class T>
AggregatorList<T>::~AggregatorList() {}

/*=============================================================================*/

template <class T>
AggregatorList<T>::AggregatorList(string rule) {
	Base::rank_aggregator_ = RankAggregator<T>::create(rule);

	if (rule == "kemeny-median") {
		Base::rank_aggregator_->set_initial_aggregation("median");
	}
	else if (rule == "kemeny-mean") {
		Base::rank_aggregator_->set_initial_aggregation("mean");
	}
	else if (rule == "kemeny-borda") {
		Base::rank_aggregator_->set_initial_aggregation("borda");
	}
}

/*=============================================================================*/

template <class T>
void AggregatorList<T>::run() {
	/* first add inputs lists to Rank Aggregator */
	if (Base::inputs_.size() <= 0) {
		throw runtime_error("No input lists to aggregate.");
	}
	else {
		for (int i = 0; i < Base::inputs_.size(); ++i) {
			Base::rank_aggregator_->add_ranking(Base::inputs_[i]);
		}
	}

	/* run aggregation */
	Base::rank_aggregator_->aggregate();

	Base::final_aggregation_ = Base::rank_aggregator_->get_aggregation();
}

/*=============================================================================*/


#else		/* _LIB_RAG_AGGREGATOR_LIST_T_ */
#error
#endif /* _LIB_RAG_AGGREGATOR_LIST_T_ */
