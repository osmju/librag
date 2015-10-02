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

			virtual ~Aggregator();

			void add_ranking(rag::RankAggregator<T>::rlist* list, std::string name);

			virtual void run() = 0;


	};
}



#endif /* AGGREGATOR_H_ */
