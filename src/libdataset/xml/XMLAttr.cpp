/**
 * Copyright - Benjamin Laugraud - 2015
 */
#include "libdataset/xml/XMLAttr.h"
#include "libdataset/xml/XMLNode.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * XMLAttr                                                                    *
 * ========================================================================== */

XMLAttr::XMLAttr(xmlAttrPtr attr) :
  attr(attr) {}

/******************************************************************************/

XMLAttr::~XMLAttr() {}

/******************************************************************************/

xmlAttrPtr XMLAttr::getMember() const {
  return attr;
}

/******************************************************************************/

void XMLAttr::setMember(xmlAttrPtr attr) {
  this->attr = attr;
}

/******************************************************************************/

bool XMLAttr::exists() const {
  return exists(attr);
}

/******************************************************************************/

string XMLAttr::getName() const {
  return getName(attr);
}

/******************************************************************************/

string XMLAttr::getContent() const {
  return getContent(attr);
}

/******************************************************************************/

string XMLAttr::getContent(xmlAttrPtr attr) {
  if (!(exists(attr))) {
    throw NullSentinelAttributeException(
      __LINE__,
      __FILE__,
      "Cannot get the content of a NULL sentinel node"
    );
  }

  return XMLNode::getContent(attr->children);
}

/******************************************************************************/

XMLNode XMLAttr::getParent() const {
  return getParent(attr);
}

/******************************************************************************/

XMLNode XMLAttr::getParent(const XMLAttr& attr) {
  return getParent(attr.attr);
}

/******************************************************************************/

XMLNode XMLAttr::getParent(xmlAttrPtr attr) {
  return XMLNode(getRawParent(attr));
}

/******************************************************************************/

void XMLAttr::goToParent(XMLNode& node) {
  goToParent(attr, node);
}

/******************************************************************************/

void XMLAttr::goToParent(
  xmlAttrPtr attr,
  XMLNode& node
) {
  node.setMember(getRawParent(attr));
}

/******************************************************************************/

bool XMLAttr::hasParent() const {
  return hasParent(attr);
}

/******************************************************************************/

XMLAttr XMLAttr::getNextSibling() const {
  return getNextSibling(attr);
}

/******************************************************************************/

xmlAttrPtr XMLAttr::getRawNextSibling() const {
  return getRawNextSibling(attr);
}

/******************************************************************************/

void XMLAttr::goToNextSibling() {
  goToNextSibling(*this);
}

/******************************************************************************/

bool XMLAttr::hasNextSibling() const {
  return hasNextSibling(attr);
}

/******************************************************************************/

XMLAttr XMLAttr::getPreviousSibling() const {
  return getPreviousSibling(attr);
}

/******************************************************************************/

xmlAttrPtr XMLAttr::getRawPreviousSibling() const {
  return getRawPreviousSibling(attr);
}

/******************************************************************************/

void XMLAttr::goToPreviousSibling() {
  goToPreviousSibling(*this);
}

/******************************************************************************/

bool XMLAttr::hasPreviousSibling() const {
  return hasPreviousSibling(attr);
}
