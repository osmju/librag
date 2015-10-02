/**
 * Copyright - Benjamin Laugraud - 2015
 */
#include "libdataset/exceptions/exceptions.h"
#include "libdataset/xml/adapters/libxml2/AllocatorAdapter.h"

using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * AllocatorAdapter                                                           *
 * ========================================================================== */

xmlParserCtxtPtr AllocatorAdapter::allocParserContext() {
  xmlParserCtxtPtr parserContext;

  if ((parserContext = xmlNewParserCtxt()) == NULL) {
    throw CannotAllocateParserCtxException(
      __LINE__,
      __FILE__,
      "Cannot allocate parser context"
    );
  }

  return parserContext;
}

/******************************************************************************/

void AllocatorAdapter::free(void* toFree) {
  if (toFree == NULL)
    return;

  xmlFree(toFree);
}

/******************************************************************************/

void AllocatorAdapter::freeParserContext(xmlParserCtxtPtr parserContext) {
  if (parserContext == NULL)
    return;

  xmlFreeParserCtxt(parserContext);
}

/******************************************************************************/

void AllocatorAdapter::freeDocument(xmlDocPtr document) {
  if (document == NULL)
    return;

  xmlFreeDoc(document);
}

/******************************************************************************/

void AllocatorAdapter::freeChar(xmlChar* _char) {
  free(_char);
}
