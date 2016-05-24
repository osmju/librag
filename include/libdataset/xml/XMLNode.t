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
#ifdef _BGS_PLATFORM_LIBDATASET_XML_XML_NODE_T_

/* ========================================================================== *
 * XMLNode                                                                    *
 * ========================================================================== */

inline bool XMLNode::exists(const XMLNode& node) {
  return exists(node.node);
}

/******************************************************************************/

inline bool XMLNode::exists(const xmlNodePtr node) {
  return (node != NULL);
}

/******************************************************************************/

inline long int XMLNode::getLine(const XMLNode& node) {
  return getLine(node.node);
}

/******************************************************************************/

inline long int XMLNode::getLine(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the line of a NULL sentinel node"
    );
  }

  return xmlGetLineNo(node);
}

/******************************************************************************/

inline std::string XMLNode::getName(const XMLNode& node) {
  return getName(node.node);
}

/******************************************************************************/

inline std::string XMLNode::getName(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the name of a NULL sentinel node"
    );
  }

  return CharAdapter::xmlCharToString(node->name);
}

/******************************************************************************/

inline void* XMLNode::getPrivate(const XMLNode& node) {
  return getPrivate(node.node);
}

/******************************************************************************/

inline void* XMLNode::getPrivate(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the name of a NULL sentinel node"
    );
  }

  return node->_private;
}

/******************************************************************************/

inline void XMLNode::setPrivate(const XMLNode& node, void* _private) {
  setPrivate(node.node, _private);
}

/******************************************************************************/

inline void XMLNode::setPrivate(xmlNodePtr node, void* _private) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot set the private field of a NULL sentinel node"
    );
  }

  node->_private = _private;
}

/******************************************************************************/

inline std::string XMLNode::getContent(const XMLNode& node) {
  return getContent(node.node);
}

/******************************************************************************/

inline std::string XMLNode::getContent(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the content of a NULL sentinel node"
    );
  }

  xmlChar* content = xmlNodeGetContent(node);
  std::string toReturn = CharAdapter::xmlCharToString(content);
  AllocatorAdapter::freeChar(content);

  return toReturn;
}

/******************************************************************************/

inline XMLNode XMLNode::getChild(const XMLNode& node) {
  return getChild(node.node);
}

/******************************************************************************/

inline XMLNode XMLNode::getChild(xmlNodePtr node) {
  return XMLNode(getRawChild(node));
}

/******************************************************************************/

inline xmlNodePtr XMLNode::getRawChild(const XMLNode& node) {
  return getRawChild(node.node);
}

/******************************************************************************/

inline xmlNodePtr XMLNode::getRawChild(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the children of a NULL sentinel node"
    );
  }

  return node->children;
}

/******************************************************************************/

inline void XMLNode::goToChild(XMLNode& node) {
  node.node = getRawChild(node);
}

/******************************************************************************/

inline bool XMLNode::hasChild(const XMLNode& node) {
  return hasChild(node.node);
}

/******************************************************************************/

inline bool XMLNode::hasChild(xmlNodePtr node) {
  return (exists(node)) ? (node->children != NULL) : false;
}

/******************************************************************************/

inline XMLNode XMLNode::getLastChild(const XMLNode& node) {
  return getLastChild(node.node);
}

/******************************************************************************/

inline XMLNode XMLNode::getLastChild(xmlNodePtr node) {
  return XMLNode(getRawLastChild(node));
}

/******************************************************************************/

inline xmlNodePtr XMLNode::getRawLastChild(const XMLNode& node) {
  return getRawLastChild(node.node);
}

/******************************************************************************/

inline xmlNodePtr XMLNode::getRawLastChild(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the line of a NULL sentinel node"
    );
  }

  return xmlGetLastChild(node);
}

/******************************************************************************/

inline void XMLNode::goToLastChild(XMLNode& node) {
  node.node = getRawLastChild(node);
}

/******************************************************************************/

inline bool XMLNode::hasLastChild(const XMLNode& node) {
  return hasLastChild(node.node);
}

/******************************************************************************/

inline bool XMLNode::hasLastChild(xmlNodePtr node) {
  return (exists(node)) ? (xmlGetLastChild(node) != NULL) : false;
}

/******************************************************************************/

inline XMLNode XMLNode::getParent(const XMLNode& node) {
  return getParent(node.node);
}

/******************************************************************************/

inline XMLNode XMLNode::getParent(xmlNodePtr node) {
  return XMLNode(getRawParent(node));
}

/******************************************************************************/

inline xmlNodePtr XMLNode::getRawParent(const XMLNode& node) {
  return getRawParent(node.node);
}

/******************************************************************************/

inline xmlNodePtr XMLNode::getRawParent(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the parent of a NULL sentinel node"
    );
  }

  return node->parent;
}

/******************************************************************************/

inline void XMLNode::goToParent(XMLNode& node) {
  node.node = getRawParent(node);
}

/******************************************************************************/

inline bool XMLNode::hasParent(const XMLNode& node) {
  return hasParent(node.node);
}

/******************************************************************************/

inline bool XMLNode::hasParent(xmlNodePtr node) {
  return (exists(node)) ? (node->parent != NULL) : false;
}

/******************************************************************************/

inline XMLNode XMLNode::getNextSibling(const XMLNode& node) {
  return getNextSibling(node.node);
}

/******************************************************************************/

inline XMLNode XMLNode::getNextSibling(xmlNodePtr node) {
  return XMLNode(getRawNextSibling(node));
}

/******************************************************************************/

inline xmlNodePtr XMLNode::getRawNextSibling(const XMLNode& node) {
  return getRawNextSibling(node.node);
}

/******************************************************************************/

inline xmlNodePtr XMLNode::getRawNextSibling(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the next sibling node of a NULL sentinel node"
    );
  }

  return node->next;
}

/******************************************************************************/

inline void XMLNode::goToNextSibling(XMLNode& node) {
  node.node = getRawNextSibling(node);
}

/******************************************************************************/

inline bool XMLNode::hasNextSibling(const XMLNode& node) {
  return hasNextSibling(node.node);
}

/******************************************************************************/

inline bool XMLNode::hasNextSibling(xmlNodePtr node) {
  return (exists(node)) ? (node->next != NULL) : false;
}

/******************************************************************************/

inline XMLNode XMLNode::getPrevious(const XMLNode& node) {
  return getPrevious(node.node);
}

/******************************************************************************/

inline XMLNode XMLNode::getPrevious(xmlNodePtr node) {
  return XMLNode(getRawPrevious(node));
}

/******************************************************************************/

inline xmlNodePtr XMLNode::getRawPrevious(const XMLNode& node) {
  return getRawPrevious(node.node);
}

/******************************************************************************/

inline xmlNodePtr XMLNode::getRawPrevious(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the previous sibling node of a NULL sentinel node"
    );
  }

  return node->prev;
}

/******************************************************************************/

inline void XMLNode::goToPrevious(XMLNode& node) {
  node.node = getRawPrevious(node);
}

/******************************************************************************/

inline bool XMLNode::hasPrevious(const XMLNode& node) {
  return hasParent(node.node);
}

/******************************************************************************/

inline bool XMLNode::hasPrevious(xmlNodePtr node) {
  return (exists(node)) ? (node->prev != NULL) : false;
}

/******************************************************************************/

inline xmlAttrPtr XMLNode::getRawAttributes(const XMLNode& node) {
  return getRawAttributes(node.node);
}

/******************************************************************************/

inline xmlAttrPtr XMLNode::getRawAttributes(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the attr of a NULL sentinel node"
    );
  }

  return node->properties;
}

/******************************************************************************/

inline void XMLNode::goToAttributes(
  const XMLNode& node,
  XMLAttr& attr
) {
  goToAttributes(node.node, attr);
}

/******************************************************************************/

inline bool XMLNode::hasAttributes(const XMLNode& node) {
  return hasAttributes(node.node);
}

/******************************************************************************/

inline bool XMLNode::hasAttributes(xmlNodePtr node) {
  return (exists(node)) ? (node->properties != NULL) : false;
}

/******************************************************************************/

inline xmlElementType XMLNode::getType(const XMLNode& node) {
  return getType(node.node);
}

/******************************************************************************/

inline xmlElementType XMLNode::getType(xmlNodePtr node) {
  if (!(exists(node))) {
    throw NullSentinelNodeException(
      __LINE__,
      __FILE__,
      "Cannot get the type of a NULL sentinel node"
    );
  }

  return node->type;
}

/******************************************************************************/

inline bool XMLNode::isBlankNode(const XMLNode& node) {
  return isBlankNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isBlankNode(xmlNodePtr node) {
  return (exists(node)) ? xmlIsBlankNode(node) : false;
}

/******************************************************************************/

inline bool XMLNode::isElementNode(const XMLNode& node) {
  return isElementNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isElementNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_ELEMENT_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isAttributeNode(const XMLNode& node) {
  return isAttributeNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isAttributeNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_ATTRIBUTE_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isTextNode(const XMLNode& node) {
  return isTextNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isTextNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_TEXT_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isCDATASectionNode(const XMLNode& node) {
  return isCDATASectionNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isCDATASectionNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_CDATA_SECTION_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isEntityRefNode(const XMLNode& node) {
  return isEntityRefNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isEntityRefNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_ENTITY_REF_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isEntityNode(const XMLNode& node) {
  return isEntityNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isEntityNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_ENTITY_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isPINode(const XMLNode& node) {
  return isPINode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isPINode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_PI_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isCommentNode(const XMLNode& node) {
  return isCommentNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isCommentNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_COMMENT_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isDocumentNode(const XMLNode& node) {
  return isDocumentNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isDocumentNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_DOCUMENT_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isDocumentTypeNode(const XMLNode& node) {
  return isDocumentTypeNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isDocumentTypeNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_DOCUMENT_TYPE_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isDocumentFragNode(const XMLNode& node) {
  return isDocumentFragNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isDocumentFragNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_DOCUMENT_FRAG_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isNotationNode(const XMLNode& node) {
  return isNotationNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isNotationNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_NOTATION_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isHTMLDocumentNode(const XMLNode& node) {
  return isHTMLDocumentNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isHTMLDocumentNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_HTML_DOCUMENT_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isDTDNode(const XMLNode& node) {
  return isDTDNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isDTDNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_DTD_NODE) : false;
}

/******************************************************************************/

inline bool XMLNode::isElementDecl(const XMLNode& node) {
  return isElementDecl(node.node);
}

/******************************************************************************/

inline bool XMLNode::isElementDecl(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_ELEMENT_DECL) : false;
}

/******************************************************************************/

inline bool XMLNode::isAttributeDecl(const XMLNode& node) {
  return isAttributeDecl(node.node);
}

/******************************************************************************/

inline bool XMLNode::isAttributeDecl(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_ATTRIBUTE_DECL) : false;
}

/******************************************************************************/

inline bool XMLNode::isEntityDecl(const XMLNode& node) {
  return isEntityDecl(node.node);
}

/******************************************************************************/

inline bool XMLNode::isEntityDecl(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_ENTITY_DECL) : false;
}

/******************************************************************************/

inline bool XMLNode::isNamespaceDecl(const XMLNode& node) {
  return isNamespaceDecl(node.node);
}

/******************************************************************************/

inline bool XMLNode::isNamespaceDecl(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_NAMESPACE_DECL) : false;
}

/******************************************************************************/

inline bool XMLNode::isXIncludeStart(const XMLNode& node) {
  return isXIncludeStart(node.node);
}

/******************************************************************************/

inline bool XMLNode::isXIncludeStart(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_XINCLUDE_START) : false;
}

/******************************************************************************/

inline bool XMLNode::isXIncludeEnd(const XMLNode& node) {
  return isXIncludeEnd(node.node);
}

/******************************************************************************/

inline bool XMLNode::isXIncludeEnd(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_XINCLUDE_END) : false;
}

/******************************************************************************/

inline bool XMLNode::isDOCBDocumentNode(const XMLNode& node) {
  return isDOCBDocumentNode(node.node);
}

/******************************************************************************/

inline bool XMLNode::isDOCBDocumentNode(xmlNodePtr node) {
  return (exists(node)) ? (getType(node) == XML_DOCB_DOCUMENT_NODE) : false;
}

#else /* _BGS_PLATFORM_LIBDATASET_XML_XML_NODE_T_ */
#error
#endif /* _BGS_PLATFORM_LIBDATASET_XML_XML_NODE_T_ */
