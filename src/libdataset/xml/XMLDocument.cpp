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
