/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_RELAXNG_PARSE_H_
#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_RELAXNG_PARSE_H_

#include <libxml/relaxng.h>

namespace BGS_Platform {
  namespace libdataset {
    class RelaxNGParseAdapter {
      private:

        RelaxNGParseAdapter();

        virtual ~RelaxNGParseAdapter();

      public:

        static xmlRelaxNGPtr parse(xmlRelaxNGParserCtxtPtr parser);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_RELAXNG_PARSE_H_ */
