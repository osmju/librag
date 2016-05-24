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

#ifndef AGGREGATOR_XML_H_
#define AGGREGATOR_XML_H_

#include "libdataset/libdataset.h"
#include "rank_aggregation_visitor.h"

namespace rag {
	template <class T> class Aggregator;

	template <class T>
	class AggregatorXML : public Aggregator<T> {
		public:
			typedef Aggregator<T>	Base;

			AggregatorXML(std::string path_xml);

			virtual ~AggregatorXML();

			void run();

		protected:
			BGS_Platform::libdataset::XMLDocument xml_rules_;

	};

#define _LIB_RAG_AGGREGATOR_XML_T_
#include "aggregator_xml.t"
#undef _LIB_RAG_AGGREGATOR_XML_T_
}

#endif /* AGGREGATOR_XML_H_ */
