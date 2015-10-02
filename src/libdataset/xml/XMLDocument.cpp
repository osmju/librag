/**
 * Copyright - Benjamin Laugraud - 2015
 */
#include "libdataset/xml/XMLDocument.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * XMLDocument                                                                *
 * ========================================================================== */

XMLDocument::XMLDocument(std::string file) :
  file(file),
  document(xmlParseFile(file.c_str())) {}

/******************************************************************************/

XMLDocument::~XMLDocument() {
  xmlFreeDoc(document);
}

/******************************************************************************/

const string& XMLDocument::getFile() const {
  return file;
}

/******************************************************************************/

xmlDocPtr XMLDocument::getDocPtr() const {
  return document;
}

/******************************************************************************/

XMLNode XMLDocument::getRoot() const {
  return XMLNode(xmlDocGetRootElement(document));
}

/******************************************************************************/

void XMLDocument::goToRoot(XMLNode& node) const {
  node.setMember(xmlDocGetRootElement(document));
}

/******************************************************************************/

void XMLDocument::visit(XMLVisitor& visitor) {
  getRoot().visit(visitor);
}
