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

#ifdef _LIB_RAG_AGGREGATOR_XML_T_

template <class T>
AggregatorXML<T>::AggregatorXML(string path_xml)
: Aggregator<T>(), xml_rules_(path_xml) {}

/*=============================================================================*/

template <class T>
AggregatorXML<T>::~AggregatorXML() {}

/*=============================================================================*/

template <class T>
void AggregatorXML<T>::run() {
	/* create XML aggregator visitor */
	BGS_Platform::libdataset::RankAggregationVisitor<T> visitor;

	/* first add inputs lists to Rank Aggregator */
	if (Base::inputs_.size() <= 0) {
		throw runtime_error("No input lists to aggregate.");
	}
	else {
		for (int i = 0; i < Base::inputs_.size(); ++i) {
			visitor.add_input_list(Base::inputs_[i]);
		}
	}

	/* run aggregation */
	xml_rules_.visit(visitor);

	/* retrieve final aggregation */
	BGS_Platform::libdataset::XMLNode root = xml_rules_.getRoot();
	typename Base::RList* result = (typename Base::RList*)(root.getPrivate());

	for (int i = 0; i < result->size(); ++i) {
		Base::final_aggregation_->push_back(result->at(i));
	}

	visitor.cleanup();
}

/*=============================================================================*/

#else		/* _LIB_RAG_AGGREGATOR_XML_T_ */
#error
#endif	/* _LIB_RAG_AGGREGATOR_XML_T_ */




