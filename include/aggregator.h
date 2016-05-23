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

			void add_ranking(const RList* list, std::string name = "");

			virtual RList_ptr get_result();

			virtual void run() = 0;

			void cleanup();

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
