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

#ifndef AGGREGATOR_LIST_H_
#define AGGREGATOR_LIST_H_

namespace rag {
	template <class T> class Aggregator;

	template <class T>
	class AggregatorList : public Aggregator<T> {
		public:
			typedef Aggregator<T>	Base;

			AggregatorList(std::string rule = "mean");

			virtual ~AggregatorList();

			void set_rule(std::string rule);

			void run();
	};

#define _LIB_RAG_AGGREGATOR_LIST_T_
#include "aggregator_list.t"
#undef _LIB_RAG_AGGREGATOR_LIST_T_
}

#endif /* AGGREGATOR_LIST_H_ */
