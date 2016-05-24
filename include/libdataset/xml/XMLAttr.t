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
#ifdef _BGS_PLATFORM_LIBDATASET_XML_XML_ATTR_T_

/* ========================================================================== *
 * XMLAttr                                                                    *
 * ========================================================================== */

inline bool XMLAttr::exists(const XMLAttr& attr) {
  return exists(attr.attr);
}

/******************************************************************************/

inline bool XMLAttr::exists(const xmlAttrPtr attr) {
  return (attr != NULL);
}

/******************************************************************************/

inline std::string XMLAttr::getName(const XMLAttr& attr) {
  return getName(attr.attr);
}

/******************************************************************************/

inline std::string XMLAttr::getName(xmlAttrPtr attr) {
  if (!(exists(attr))) {
    throw NullSentinelAttributeException(
      __LINE__,
      __FILE__,
      "Cannot get the name of a NULL sentinel attribute"
    );
  }

  return CharAdapter::xmlCharToString(attr->name);
}

/******************************************************************************/

inline std::string XMLAttr::getContent(const XMLAttr& attr) {
  return getContent(attr.attr);
}

/******************************************************************************/

inline xmlNodePtr XMLAttr::getRawParent(const XMLAttr& attr) {
  return getRawParent(attr.attr);
}

/******************************************************************************/

inline xmlNodePtr XMLAttr::getRawParent(xmlAttrPtr attr) {
  if (!(exists(attr))) {
    throw NullSentinelAttributeException(
      __LINE__,
      __FILE__,
      "Cannot get the parent of a NULL sentinel attribute"
    );
  }

  return attr->parent;
}

/******************************************************************************/

inline void XMLAttr::goToParent(
  const XMLAttr& attr,
  XMLNode& node
) {
  goToParent(attr.attr, node);
}

/******************************************************************************/

inline bool XMLAttr::hasParent(const XMLAttr& attr) {
  return hasParent(attr.attr);
}

/******************************************************************************/

inline bool XMLAttr::hasParent(xmlAttrPtr attr) {
  return (exists(attr)) ? (attr->parent != NULL) : false;
}

/******************************************************************************/

inline XMLAttr XMLAttr::getNextSibling(const XMLAttr& attr) {
  return getNextSibling(attr.attr);
}

/******************************************************************************/

inline XMLAttr XMLAttr::getNextSibling(xmlAttrPtr attr) {
  return XMLAttr(getRawNextSibling(attr));
}

/******************************************************************************/

inline xmlAttrPtr XMLAttr::getRawNextSibling(const XMLAttr& attr) {
  return getRawNextSibling(attr.attr);
}

/******************************************************************************/

inline xmlAttrPtr XMLAttr::getRawNextSibling(xmlAttrPtr attr) {
  if (!(exists(attr))) {
    throw NullSentinelAttributeException(
      __LINE__,
      __FILE__,
      "Cannot get the next sibling attribute of a NULL sentinel attribute"
    );
  }

  return attr->next;
}

/******************************************************************************/

inline void XMLAttr::goToNextSibling(XMLAttr& attr) {
  attr.attr = getRawNextSibling(attr);
}

/******************************************************************************/

inline bool XMLAttr::hasNextSibling(const XMLAttr& attr) {
  return hasNextSibling(attr.attr);
}

/******************************************************************************/

inline bool XMLAttr::hasNextSibling(xmlAttrPtr attr) {
  return (exists(attr)) ? (attr->next != NULL) : false;
}

/******************************************************************************/

inline XMLAttr XMLAttr::getPreviousSibling(const XMLAttr& attr) {
  return getPreviousSibling(attr.attr);
}

/******************************************************************************/

inline XMLAttr XMLAttr::getPreviousSibling(xmlAttrPtr attr) {
  return XMLAttr(getRawPreviousSibling(attr));
}

/******************************************************************************/

inline xmlAttrPtr XMLAttr::getRawPreviousSibling(const XMLAttr& attr) {
  return getRawPreviousSibling(attr.attr);
}

/******************************************************************************/

inline xmlAttrPtr XMLAttr::getRawPreviousSibling(xmlAttrPtr attr) {
  if (!(exists(attr))) {
    throw NullSentinelAttributeException(
      __LINE__,
      __FILE__,
      "Cannot get the previous sibling attribute of a NULL sentinel attribute"
    );
  }

  return attr->prev;
}

/******************************************************************************/

inline void XMLAttr::goToPreviousSibling(XMLAttr& attr) {
  attr.attr = getRawPreviousSibling(attr);
}

/******************************************************************************/

inline bool XMLAttr::hasPreviousSibling(const XMLAttr& attr) {
  return hasPreviousSibling(attr.attr);
}

/******************************************************************************/

inline bool XMLAttr::hasPreviousSibling(xmlAttrPtr attr) {
  return (exists(attr)) ? (attr->prev != NULL) : false;
}

#else /* _BGS_PLATFORM_LIBDATASET_XML_XML_ATTR_T_ */
#error
#endif /* _BGS_PLATFORM_LIBDATASET_XML_XML_ATTR_T_ */
