/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_ALLOC_H_
#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_ALLOC_H_

#include <string>

#include <libxml/schematron.h>

#include "libdataset/xml/XMLDocument.h"

namespace BGS_Platform {
  namespace libdataset {
    class SchematronAllocatorAdapter {
      private:

        SchematronAllocatorAdapter();

        virtual ~SchematronAllocatorAdapter();

      public:

        static xmlSchematronParserCtxtPtr newParser(std::string file);

        static xmlSchematronValidCtxtPtr newValidator(xmlSchematronPtr schema);

      protected:

        static xmlSchematronParserCtxtPtr newParser(const char* file);

      public:

        static void free(xmlSchematronPtr schema);

        static void freeParser(xmlSchematronParserCtxtPtr parser);

        static void freeValidator(xmlSchematronValidCtxtPtr validator);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform _ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_ALLOC_H_ */
