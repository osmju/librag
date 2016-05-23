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

#ifndef RANK_AGGREGATOR_MEAN_H_
#define RANK_AGGREGATOR_MEAN_H_

#include "types.h"

namespace rag {
	template <class T> class RankAggregator;

	template <class T>
	class AggregatorMean : public RankAggregator<T> {
		public:
			typedef RankAggregator<T> Base;

			AggregatorMean();
			virtual ~AggregatorMean();

			virtual void aggregate();
	};

#define _LIB_RAG_RANK_AGGREGATOR_MEAN_T_
#include "aggregators/rank_aggregator_mean.t"
#undef _LIB_RAG_RANK_AGGREGATOR_MEAN_T_
}

#endif /* RANK_AGGREGATOR_MEAN_H_ */
