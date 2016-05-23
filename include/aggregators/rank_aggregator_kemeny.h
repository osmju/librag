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

#ifndef RANK_AGGREGATOR_KEMENY_H_
#define RANK_AGGREGATOR_KEMENY_H_

#include "types.h"

namespace rag {
	template <class T> class RankAggregator;

	template <class T>
	class AggregatorKemeny : public RankAggregator<T> {
		public:
			typedef RankAggregator<T> Base;

			AggregatorKemeny();
			virtual ~AggregatorKemeny();

			virtual void aggregate();
			virtual void set_initial_aggregation(std::string initial_aggregation = "median");

		private:
			bool is_preferred(T item1, T item2);
			void swap(typename Base::rlist& list, int index1, int index2);

			bool is_mapping_built_;
			std::string initial_aggregation_;
	};

#define _LIB_RAG_RANK_AGGREGATOR_KEMENY_T_
#include "aggregators/rank_aggregator_kemeny.t"
#undef _LIB_RAG_RANK_AGGREGATOR_KEMENY_T_
}

#endif /* RANK_AGGREGATOR_KEMENY_H_ */
