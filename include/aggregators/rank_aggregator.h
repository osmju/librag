// Copyright (C) 2016   Julien Osmalskyj
//
// This file is part of LibRAG.
//
// LibRAG is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LibRAG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with LibRAG.  If not, see http://www.gnu.org/licenses.

#ifndef RANK_AGGREGATOR_H_
#define RANK_AGGREGATOR_H_

#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <iostream>
#include <algorithm>

#include "aggregators/rank_aggregator_borda.h"
#include "aggregators/rank_aggregator_mean.h"
#include "aggregators/rank_aggregator_median.h"
#include "aggregators/rank_aggregator_min.h"
#include "aggregators/rank_aggregator_kemeny.h"
#include "types.h"

namespace rag {

	template <class T>
	class RankAggregator {
		public:
			typedef std::shared_ptr<RankAggregator>		ptr;
			typedef std::vector<T> 		   							rlist;
			typedef std::shared_ptr<rlist>							rlist_ptr;
			typedef std::vector<const rlist*>					rmatrix;
			typedef std::unordered_map<T, ivectptr>    rankmap;
			typedef std::tuple<float, T>	 							object_score;
			typedef std::vector<object_score>	 				rating;

			virtual ~RankAggregator();

			void add_ranking(const rlist* ranking);

			const rlist* get_ranking(int ranking_id) const;

			rlist_ptr get_aggregation() const;

			int nb_rankings() const;

			int lists_max_size() const;

			virtual void aggregate() = 0;

			virtual void set_initial_aggregation(std::string initial_aggregation) {
				throw std::runtime_error("Not implemented in this aggregator.");
			}

			// factory method
			static ptr create(std::string name);

			static rlist_ptr new_rlist();

		protected:
			rmatrix rankings_;
			rlist_ptr aggregated_list_;
			rankmap objects_ranks_;
			int nb_rankings_;

			RankAggregator();

			void build_ranking_map();
	};

#define _LIB_RAG_RANK_AGGREGATOR_T_
#include "aggregators/rank_aggregator.t"
#undef _LIB_RAG_RANK_AGGREGATOR_T_

} /* namsepace rag */






#endif /* RANK_AGGREGATOR_H_ */
