//! \file 				  aggregator.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Oct 2, 2015


#ifndef AGGREGATOR_H_
#define AGGREGATOR_H_

#include "aggregators/rank_aggregator.h"

namespace rag {

	template <class T>
	class Aggregator {
		public:
			typedef typename rag::RankAggregator<T>::rlist RList;

			virtual ~Aggregator();

			void add_ranking(const RList* list, std::string name);

			RList get_result();

			virtual void run() = 0;

		protected:
			RList final_aggregation_;
			std::vector<const RList*> inputs_;
			svect inputs_names_;
			typename RankAggregator<T>::ptr rank_aggregator_;

	};

#define _LIB_RAG_AGGREGATOR_T_
#include "aggregator.t"
#undef _LIB_RAG_AGGREGATOR_T_
} /* namespace rag */

#endif /* AGGREGATOR_H_ */
