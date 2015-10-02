/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_PARSE_H_
#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_PARSE_H_

#include <libxml/schematron.h>

namespace BGS_Platform {
  namespace libdataset {
    class SchematronParseAdapter {
      private:

        SchematronParseAdapter();

        virtual ~SchematronParseAdapter();

      public:

        static xmlSchematronPtr parse(xmlSchematronParserCtxtPtr parser);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_PARSE_H_ */
