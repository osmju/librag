/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_ALLOCATOR_ADAPTER_H_
#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_ALLOCATOR_ADAPTER_H_

#include <libxml/parser.h>
#include <libxml/tree.h>

namespace BGS_Platform {
  namespace libdataset {
    class AllocatorAdapter {
      public:

        static xmlParserCtxtPtr allocParserContext();

        static void free(void* toFree);

        static void freeParserContext(xmlParserCtxtPtr parserContext);

        static void freeDocument(xmlDocPtr document);

        static void freeChar(xmlChar* _char);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_ALLOCATOR_ADAPTER_H_ */
