//! \file 				  aggregator_xml.t
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Oct 5, 2015

#ifdef _LIB_RAG_AGGREGATOR_XML_T_

template <class T>
AggregatorXML<T>::AggregatorXML(string path_xml)
: xml_rules_(path_xml) {}

/*=============================================================================*/

template <class T>
AggregatorXML<T>::~AggregatorXML() {}

/*=============================================================================*/

template <class T>
void AggregatorXML<T>::run() {
	/* create XML aggregator visitor */
	BGS_Platform::libdataset::RankAggregationVisitor visitor;

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
		Base::final_aggregation_.push_back(result->at(i));
	}
}

/*=============================================================================*/

#else		/* _LIB_RAG_AGGREGATOR_XML_T_ */
#error
#endif	/* _LIB_RAG_AGGREGATOR_XML_T_ */




