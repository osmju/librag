//! \file rank_aggregator_min.h
//! \brief Replace by short description
//!
//! \author Julien Osmalskyj
//! \date   15 Feb. 2016
#ifndef RANK_AGGREGATOR_MIN_H_
#define RANK_AGGREGATOR_MIN_H_

#include "types.h"

namespace rag {
	template <class T> class RankAggregator;

	template <class T>
	class AggregatorMin : public RankAggregator<T> {
		public:
			typedef RankAggregator<T> Base;

			AggregatorMin();
			virtual ~AggregatorMin();

			virtual void aggregate();
	};

#define _LIB_RAG_RANK_AGGREGATOR_MIN_T_
#include "aggregators/rank_aggregator_min.t"
#undef _LIB_RAG_RANK_AGGREGATOR_MIN_T_
}

#endif /* RANK_AGGREGATOR_MEAN_H_ */
