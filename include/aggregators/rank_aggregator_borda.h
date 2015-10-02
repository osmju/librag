//! \file 				  rank_aggregator_borda.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Sep 22, 2015


#ifndef RANK_AGGREGATOR_BORDA_H_
#define RANK_AGGREGATOR_BORDA_H_

#include "aggregators/rank_aggregator.h"

namespace rag {

		template <class T>
		class AggregatorBorda : public RankAggregator<T> {
			public:
				typedef RankAggregator<T>                                     Base;

				AggregatorBorda();
				virtual ~AggregatorBorda();

				virtual void aggregate();

			protected:

		};
}

#include "aggregators/rank_aggregator_borda.t"



#endif /* RANK_AGGREGATOR_BORDA_H_ */
