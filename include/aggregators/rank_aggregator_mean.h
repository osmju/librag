//! \file rank_aggregator_mean.h
//! \brief Replace by short description
//!
//! \author Julien Osmalskyj
//! \date   22 sept. 2015
#ifndef RANK_AGGREGATOR_MEAN_H_
#define RANK_AGGREGATOR_MEAN_H_

#include "aggregators/rank_aggregator.h"

namespace rag {

	template <class T>
	class AggregatorMean : public RankAggregator<T> {
		public:
			typedef RankAggregator<T> Base;

			AggregatorMean();
			virtual ~AggregatorMean();

			virtual void aggregate();
	};

}

#include "aggregators/rank_aggregator_mean.t"


#endif /* RANK_AGGREGATOR_MEAN_H_ */
