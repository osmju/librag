// Copyright (C) 2016   Benjamin Laugraud
//
// This file is part of LibDataset.
//
// LibDataset is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LibDataset is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with LibDataset.  If not, see http://www.gnu.org/licenses.
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
