//! \file 				  aggregator_list.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Oct 5, 2015

#ifndef AGGREGATOR_LIST_H_
#define AGGREGATOR_LIST_H_

#include "aggregator.h"

namespace rag {

	template <class T>
	class AggregatorList : public Aggregator<T> {
		public:
			typedef Aggregator<T>	Base;

			AggregatorList(std::string rule = "mean");

			virtual ~AggregatorList();

			void set_rule(std::string rule);

			void run();

		protected:
			typename RankAggregator<T>::ptr rank_aggregator_;

	};

#define _LIB_RAG_AGGREGATOR_LIST_T_
#include "aggregator_list.t"
#undef _LIB_RAG_AGGREGATOR_LIST_T_
}

#endif /* AGGREGATOR_LIST_H_ */
