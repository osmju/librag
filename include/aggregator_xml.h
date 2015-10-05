//! \file 				  aggregator_xml.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Oct 5, 2015

#ifndef AGGREGATOR_XML_H_
#define AGGREGATOR_XML_H_

#include "aggregator.h"
#include "libdataset/libdataset.h"
#include "aggregator.h"
#include "rank_aggregation_visitor.h"

namespace rag {

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
