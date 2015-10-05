//! \file 				  aggregator_xml.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Oct 5, 2015

#ifndef AGGREGATOR_XML_H_
#define AGGREGATOR_XML_H_

#include "aggregator.h"

namespace rag {

	template <class T>
	class AggregatorXML : public Aggregator<T> {
		public:
			typedef Aggregator<T>	Base;

			AggregatorXML(std::string path_xml);

			virtual ~AggregatorXML();
	};
}



#endif /* AGGREGATOR_XML_H_ */
