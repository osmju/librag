//! \file 				  rank_aggregator_median.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Sep 23, 2015


#ifndef RANK_AGGREGATOR_MEDIAN_H_
#define RANK_AGGREGATOR_MEDIAN_H_

#include "types.h"

namespace rag {
	template <class T> class RankAggregator;

	template <class T>
	class AggregatorMedian : public RankAggregator<T> {
		public:
			typedef RankAggregator<T> Base;

			AggregatorMedian();

			virtual ~AggregatorMedian();

			virtual void aggregate();

			float median(const ivectptr ranks) const;

	};

#define _LIB_RAG_RANK_AGGREATOR_MEDIAN_T_
#include "aggregators/rank_aggregator_median.t"
#undef _LIB_RAG_RANK_AGGREATOR_MEDIAN_T_
}

#endif /* RANK_AGGREGATOR_MEDIAN_H_ */
