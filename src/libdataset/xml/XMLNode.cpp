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
#include "libdataset/xml/XMLAttr.h"
#include "libdataset/xml/XMLNode.h"
#include "libdataset/xml/XMLVisitor.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * XMLNode                                                                    *
 * ========================================================================== */

XMLNode::XMLNode(xmlNodePtr node) :
  node(node) {}

/******************************************************************************/

XMLNode::~XMLNode() {}

/******************************************************************************/

xmlNodePtr XMLNode::getMember() const {
  return node;
}

/******************************************************************************/

void XMLNode::setMember(xmlNodePtr node) {
  this->node = node;
}

/******************************************************************************/

bool XMLNode::exists() const {
  return exists(node);
}

/******************************************************************************/

long int XMLNode::getLine() const {
  return getLine(node);
}

/******************************************************************************/

string XMLNode::getName() const {
  return getName(node);
}

/******************************************************************************/

void* XMLNode::getPrivate() const {
  return getPrivate(node);
}

/******************************************************************************/

void XMLNode::setPrivate(void* _private) {
  setPrivate(node, _private);
}

/******************************************************************************/

string XMLNode::getContent() const {
  return getContent(node);
}

/******************************************************************************/

XMLNode XMLNode::getChild() const {
  return getChild(node);
}

/******************************************************************************/

xmlNodePtr XMLNode::getRawChild() const {
  return getRawChild(node);
}

/******************************************************************************/

void XMLNode::goToChild() {
  goToChild(*this);
}

/******************************************************************************/

bool XMLNode::hasChild() const {
  return hasChild(node);
}

/******************************************************************************/

XMLNode XMLNode::getLastChild() const {
  return getLastChild(node);
}

/******************************************************************************/

xmlNodePtr XMLNode::getRawLastChild() const {
  return getRawLastChild(node);
}

/******************************************************************************/

void XMLNode::goToLastChild() {
  goToLastChild(*this);
}

/******************************************************************************/

bool XMLNode::hasLastChild() const {
  return hasLastChild(node);
}

/******************************************************************************/

XMLNode XMLNode::getParent() const {
  return getParent(node);
}

/******************************************************************************/

xmlNodePtr XMLNode::getRawParent() const {
  return getRawParent(node);
}

/******************************************************************************/

void XMLNode::goToParent() {
  return goToParent(*this);
}

/******************************************************************************/

bool XMLNode::hasParent() const {
  return hasParent(node);
}

/******************************************************************************/

XMLNode XMLNode::getNextSibling() const {
  return getNextSibling(node);
}

/******************************************************************************/

xmlNodePtr XMLNode::getRawNextSibling() const {
  return getRawNextSibling(node);
}

/******************************************************************************/

void XMLNode::goToNextSibling() {
  goToNextSibling(*this);
}

/******************************************************************************/

bool XMLNode::hasNextSibling() const {
  return hasNextSibling(node);
}

/******************************************************************************/

XMLNode XMLNode::getPrevious() const {
  return getPrevious(node);
}

/******************************************************************************/

xmlNodePtr XMLNode::getRawPrevious() const {
  return getRawPrevious(node);
}

/******************************************************************************/

void XMLNode::goToPrevious() {
  goToPrevious(*this);
}

/******************************************************************************/

bool XMLNode::hasPrevious() const {
  return hasPrevious(node);
}

/******************************************************************************/

XMLAttr XMLNode::getAttributes() const {
  return getAttributes(node);
}

/******************************************************************************/

XMLAttr XMLNode::getAttributes(const XMLNode& node) {
  return getAttributes(node.node);
}

/******************************************************************************/

XMLAttr XMLNode::getAttributes(xmlNodePtr node) {
  return XMLAttr(getRawAttributes(node));
}

/******************************************************************************/

xmlAttrPtr XMLNode::getRawAttributes() const {
  return getRawAttributes(node);
}

/******************************************************************************/

void XMLNode::goToAttributes(XMLAttr& attr) const {
  goToAttributes(node, attr);
}

/******************************************************************************/

void XMLNode::goToAttributes(
  xmlNodePtr node,
  XMLAttr& attr
) {
  attr.setMember(getRawAttributes(node));
}

/******************************************************************************/

bool XMLNode::hasAttributes() const {
  return hasAttributes(node);
}

/******************************************************************************/

xmlElementType XMLNode::getType() const {
  return getType(node);
}

/******************************************************************************/

bool XMLNode::isBlankNode() const {
  return isBlankNode(node);
}

/******************************************************************************/

bool XMLNode::isElementNode() const {
  return isElementNode(node);
}

/******************************************************************************/

bool XMLNode::isAttributeNode() const {
  return isAttributeNode(node);
}

/******************************************************************************/

bool XMLNode::isTextNode() const {
  return isTextNode(node);
}

/******************************************************************************/

bool XMLNode::isCDATASectionNode() const {
  return isCDATASectionNode(node);
}

/******************************************************************************/

bool XMLNode::isEntityRefNode() const {
  return isEntityRefNode(node);
}

/******************************************************************************/

bool XMLNode::isEntityNode() const {
  return isEntityNode(node);
}

/******************************************************************************/

bool XMLNode::isPINode() const {
  return isPINode(node);
}

/******************************************************************************/

bool XMLNode::isCommentNode() const {
  return isCommentNode(node);
}

/******************************************************************************/

bool XMLNode::isDocumentNode() const {
  return isDocumentNode(node);
}

/******************************************************************************/

bool XMLNode::isDocumentTypeNode() const {
  return isDocumentTypeNode(node);
}

/******************************************************************************/

bool XMLNode::isDocumentFragNode() const {
  return isDocumentFragNode(node);
}

/******************************************************************************/

bool XMLNode::isNotationNode() const {
  return isNotationNode(node);
}

/******************************************************************************/

bool XMLNode::isHTMLDocumentNode() const {
  return isHTMLDocumentNode(node);
}

/******************************************************************************/

bool XMLNode::isDTDNode() const {
  return isDTDNode(node);
}

/******************************************************************************/

bool XMLNode::isElementDecl() const {
  return isElementDecl(node);
}

/******************************************************************************/

bool XMLNode::isAttributeDecl() const {
  return isAttributeDecl(node);
}

/******************************************************************************/

bool XMLNode::isEntityDecl() const {
  return isEntityDecl(node);
}

/******************************************************************************/

bool XMLNode::isNamespaceDecl() const {
  return isNamespaceDecl(node);
}

/******************************************************************************/

bool XMLNode::isXIncludeStart() const {
  return isXIncludeStart(node);
}

/******************************************************************************/

bool XMLNode::isXIncludeEnd() const {
  return isXIncludeEnd(node);
}

/******************************************************************************/

bool XMLNode::isDOCBDocumentNode() const {
  return isDOCBDocumentNode(node);
}

/******************************************************************************/

string XMLNode::typeToString() const {
  return typeToString(getType());
}

/******************************************************************************/

string XMLNode::typeToString(xmlElementType type) {
  switch (type) {
    case XML_ELEMENT_NODE:
      return "XML_ELEMENT_NODE";

    case XML_ATTRIBUTE_NODE:
      return "XML_ATTRIBUTE_NODE";

    case XML_TEXT_NODE:
      return "XML_TEXT_NODE";

    case XML_CDATA_SECTION_NODE:
      return "XML_CDATA_SECTION_NODE";

    case XML_ENTITY_REF_NODE:
      return "XML_ENTITY_REF_NODE";

    case XML_PI_NODE:
      return "XML_PI_NODE";

    case XML_COMMENT_NODE:
      return "XML_COMMENT_NODE";

    case XML_DOCUMENT_NODE:
      return "XML_DOCUMENT_NODE";

    case XML_DOCUMENT_TYPE_NODE:
      return "XML_OCUMENT_TYPE_NODE";

    case XML_DOCUMENT_FRAG_NODE:
      return "XML_DOCUMENT_FRAG_NODE";

    case XML_NOTATION_NODE:
      return "XML_NOTATION_NODE";

    case XML_HTML_DOCUMENT_NODE:
      return "XML_HTML_DOCUMENT_NODE";

    case XML_DTD_NODE:
      return "XML_DTD_NODE";

    case XML_ELEMENT_DECL:
      return "XML_ELEMENT_DECL";

    case XML_ATTRIBUTE_DECL:
      return "XML_ATTRIBUTE_DECL";

    case XML_ENTITY_DECL:
      return "XML_ENTITY_DECL";

    case XML_NAMESPACE_DECL:
      return "XML_NAMESPACE_DECL";

    case XML_XINCLUDE_START:
      return "XML_XINCLUDE_START";

    case XML_XINCLUDE_END:
      return "XML_XINCLUDE_END";

    case XML_DOCB_DOCUMENT_NODE:
      return "XML_DOCB_DOCUMENT_NODE";

    default:
      return "UNKNOWN";
  }
}

/******************************************************************************/

void XMLNode::visit(XMLVisitor& visitor) {
  visitor.startVisit();

  XMLNode root = node;
  XMLAttr attr;

  switch (visitor.getTraversal()) {
    case XMLVisitor::PRE_ORDER:
      visitPreOrder(root, attr, visitor, 0);
      break;

    case XMLVisitor::POST_ORDER:
      visitPostOrder(root, attr, visitor, 0);
      break;

    default:
      throw 1; //TODO Exception
  }

  visitor.endVisit();
}

/******************************************************************************/

void XMLNode::visitPreOrder(
  XMLNode& node,
  XMLAttr& attr,
  XMLVisitor& visitor,
  size_t level
) {
  while (true) {
    visitNode(node, visitor, level);

    if (node.hasAttributes()) {
      attr.setMember(node.getRawAttributes());
      visitAttr(attr, visitor, level);
    }

    if (node.hasChild()) {
      node.goToChild();
      visitPreOrder(node, attr, visitor, level + 1);
      node.goToParent();
    }

    if (!(node.hasNextSibling()))
      break;

    node.goToNextSibling();
  }
}

/******************************************************************************/

void XMLNode::visitPostOrder(
  XMLNode& node,
  XMLAttr& attr,
  XMLVisitor& visitor,
  size_t level
) {
  while (true) {
    if (node.hasChild()) {
      node.goToChild();
      visitPostOrder(node, attr, visitor, level + 1);
      node.goToParent();
    }

    visitNode(node, visitor, level);

    if (node.hasAttributes()) {
      attr.setMember(node.getRawAttributes());
      visitAttr(attr, visitor, level);
    }

    if (!(node.hasNextSibling()))
      break;

    node.goToNextSibling();
  }
}

/******************************************************************************/

void XMLNode::visitNode(
  XMLNode& node,
  XMLVisitor& visitor,
  size_t level
) {
  switch (node.getType()) {
    case XML_ELEMENT_NODE:
      visitor.visitElementNode(node, level);
      break;

    case XML_ATTRIBUTE_NODE:
      throw 1; // TODO Exception

    case XML_TEXT_NODE:
      visitor.visitTextNode(node, level);
      break;

    case XML_CDATA_SECTION_NODE:
      visitor.visitCDATASectionNode(node, level);
      break;

    case XML_ENTITY_REF_NODE:
      visitor.visitEntityRefNode(node, level);
      break;

    case XML_PI_NODE:
      visitor.visitPINode(node, level);
      break;

    case XML_COMMENT_NODE:
      visitor.visitCommentNode(node, level);
      break;

    case XML_DOCUMENT_NODE:
      visitor.visitDocumentNode(node, level);
      break;

    case XML_DOCUMENT_TYPE_NODE:

      visitor.visitDocumentTypeNode(node, level);
      break;

    case XML_DOCUMENT_FRAG_NODE:
      visitor.visitDocumentFragNode(node, level);
      break;

    case XML_NOTATION_NODE:
      visitor.visitNotationNode(node, level);
      break;

    case XML_HTML_DOCUMENT_NODE:
      visitor.visitHTMLDocumentNode(node, level);
      break;

    case XML_DTD_NODE:
      visitor.visitDTDNode(node, level);
      break;

    case XML_ELEMENT_DECL:
      visitor.visitElementDecl(node, level);
      break;

    case XML_ATTRIBUTE_DECL:
      visitor.visitAttributeDecl(node, level);
      break;

    case XML_ENTITY_DECL:
      visitor.visitEntityDecl(node, level);
      break;

    case XML_NAMESPACE_DECL:
      visitor.visitNamespaceDecl(node, level);
      break;

    case XML_XINCLUDE_START:
      visitor.visitXIncludeStart(node, level);
      break;

    case XML_XINCLUDE_END:
      visitor.visitXIncludeEnd(node, level);
      break;

    case XML_DOCB_DOCUMENT_NODE:
      visitor.visitDOCBDocumentNode(node, level);
      break;

    default:
      throw 1; //TODO Exception
  }
}

/******************************************************************************/

void XMLNode::visitAttr(
  XMLAttr& attr,
  XMLVisitor& visitor,
  size_t level
) {
  while (true) {
    visitor.visitAttributeNode(attr, level);

    if (!(attr.hasNextSibling()))
      break;

    attr.goToNextSibling();
  }
}
