/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_RELAXNG_ALLOC_H_
#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_RELAXNG_ALLOC_H_

#include <string>

#include <libxml/relaxng.h>

#include "libdataset/xml/XMLDocument.h"

namespace BGS_Platform {
  namespace libdataset {
    class RelaxNGAllocatorAdapter {
      private:

        RelaxNGAllocatorAdapter();

        virtual ~RelaxNGAllocatorAdapter();

      public:

        static xmlRelaxNGParserCtxtPtr newParser(std::string file);

        static xmlRelaxNGValidCtxtPtr newValidator(xmlRelaxNGPtr schema);

      protected:

        static xmlRelaxNGParserCtxtPtr newParser(const char* file);

      public:

        static void free(xmlRelaxNGPtr schema);

        static void freeParser(xmlRelaxNGParserCtxtPtr parser);

        static void freeValidator(xmlRelaxNGValidCtxtPtr validator);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform _ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_RELAXNG_ALLOC_H_ */
