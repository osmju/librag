//! \file 				  aggregator.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Oct 2, 2015


#ifndef AGGREGATOR_H_
#define AGGREGATOR_H_

#include <iostream>
#include "aggregators/rank_aggregator.h"
#include "aggregator_list.h"
#include "aggregator_xml.h"

namespace rag {

	template <class T>
	class Aggregator {
		public:
			typedef std::shared_ptr<Aggregator>									ptr;
			typedef typename rag::RankAggregator<T>::rlist 			RList;
			typedef typename rag::RankAggregator<T>::rlist_ptr 	RList_ptr;

			virtual ~Aggregator();

			void add_ranking(const RList* list, std::string name);

			virtual RList_ptr get_result();

			virtual void run() = 0;

			static ptr create(std::string name, std::string option);

		protected:
			RList_ptr final_aggregation_;
			std::vector<const RList*> inputs_;
			svect inputs_names_;
			typename RankAggregator<T>::ptr rank_aggregator_;

			Aggregator();
	};

#define _LIB_RAG_AGGREGATOR_T_
#include "aggregator.t"
#undef _LIB_RAG_AGGREGATOR_T_
} /* namespace rag */

#endif /* AGGREGATOR_H_ */
