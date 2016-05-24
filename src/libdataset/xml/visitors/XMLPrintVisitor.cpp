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
#include <iostream>
#include <string>

#include "libdataset/xml/visitors/XMLPrintVisitor.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * XMLPrintVisitor                                                            *
 * ========================================================================== */

void XMLPrintVisitor::startVisit() {}

/******************************************************************************/

void XMLPrintVisitor::endVisit() {
  cout << "</" << lastElement[0] << ">" << endl;
  cout << flush;
}

/******************************************************************************/

void XMLPrintVisitor::visitElementNode(XMLNode& node, size_t level) {
  closeLastElement(level);
  cout << "<" << node.getName();
  lastElementEmpty[level] = !(node.hasChild());

  if (!(node.hasAttributes()))
    cout << ">";

  lastElement[level] = node.getName();
  closed[level] = false;
  previousLevel = level;
}

/******************************************************************************/

void XMLPrintVisitor::visitAttributeNode(XMLAttr& attr, size_t) {
  cout << " " << attr.getName() << "=\"" << attr.getContent() << "\"";

  if (!(attr.hasNextSibling()))
    cout << ">";
}

/******************************************************************************/

void XMLPrintVisitor::visitTextNode(XMLNode& node, size_t level) {
  if (node.isBlankNode())
    closeLastElement(level);

  cout << node.getContent();
}

/******************************************************************************/

void XMLPrintVisitor::visitCDATASectionNode(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? CDATA" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitEntityRefNode(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? ENTITY_REF" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitEntityNode(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? ENTITY" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitPINode(XMLNode& node, size_t level) {
  closeLastElement(level);
  cout << "<?" << node.getName() << " " << node.getContent() << " ?>";
}

/******************************************************************************/

void XMLPrintVisitor::visitCommentNode(XMLNode& node, size_t level) {
  closeLastElement(level);
  cout << "<!--" << node.getContent() << "-->";
}

/******************************************************************************/

void XMLPrintVisitor::visitDocumentNode(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? DOCUMENT" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitDocumentTypeNode(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? DOCUMENT_TYPE" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitDocumentFragNode(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? DOCUMENT_FRAG" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitNotationNode(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? NOTATION" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitHTMLDocumentNode(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? HTML_DOC" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitDTDNode(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? DTD" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitElementDecl(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? ELEMENT_DECL" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitAttributeDecl(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? ATTRIBUTE_DECL" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitEntityDecl(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? ENTITY_DECL" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitNamespaceDecl(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? NAMESPACE_DECL" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitXIncludeStart(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? XINCLUDE_START" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitXIncludeEnd(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? XINCLUDE_END" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::visitDOCBDocumentNode(XMLNode&, size_t level) {
  cout << string(level * 2, ' ') << "?????? DOCB_DOC" << endl;
}

/******************************************************************************/

void XMLPrintVisitor::closeLastElement(size_t level) {
  if (level != 0 && level <= previousLevel && !(closed[level])) {
    cout << "</" << lastElement[level] << ">";
    closed[level] = true;
  }
}
