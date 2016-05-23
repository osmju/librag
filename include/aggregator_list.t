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
