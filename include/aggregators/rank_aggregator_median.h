//! \file 				  rank_aggregator_median.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Sep 23, 2015


#ifndef RANK_AGGREGATOR_MEDIAN_H_
#define RANK_AGGREGATOR_MEDIAN_H_

#include "rank_aggregator.h"

namespace rag {

	template <class T>
	class AggregatorMedian : public RankAggregator<T> {
		public:
			typedef RankAggregator<T> Base;

			AggregatorMedian();
			virtual ~AggregatorMedian();

			virtual void aggregate();

			float median(const typename Base::ivectptr ranks) const;

	};

}

#include "aggregators/rank_aggregator_median.t"



#endif /* RANK_AGGREGATOR_MEDIAN_H_ */
