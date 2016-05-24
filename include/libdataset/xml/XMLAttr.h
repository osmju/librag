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
#ifndef _BGS_PLATFORM_LIBDATASET_XML_XML_ATTR_H_
#define _BGS_PLATFORM_LIBDATASET_XML_XML_ATTR_H_

#include <cstddef>
#include <string>

#include <libxml/tree.h>

#include "libdataset/exceptions/exceptions.h"
#include "libdataset/xml/adapters/libxml2/CharAdapter.h"

namespace BGS_Platform {
  namespace libdataset {
    class XMLNode;

    class XMLAttr {
      protected:

        xmlAttrPtr attr;

      public:

        XMLAttr(xmlAttrPtr attr = NULL);

        virtual ~XMLAttr();

        xmlAttrPtr getMember() const;

        void setMember(xmlAttrPtr attr);

        bool exists() const;

        static bool exists(const XMLAttr& attr);

        static bool exists(const xmlAttrPtr attr);

        std::string getName() const;

        static std::string getName(const XMLAttr& attr);

        static std::string getName(xmlAttrPtr attr);

        std::string getContent() const;

        static std::string getContent(const XMLAttr& attr);

        static std::string getContent(xmlAttrPtr attr);

        XMLNode getParent() const;

        static XMLNode getParent(const XMLAttr& attr);

        static XMLNode getParent(xmlAttrPtr attr);

        xmlNodePtr getRawParent() const;

        static xmlNodePtr getRawParent(const XMLAttr& attr);

        static xmlNodePtr getRawParent(xmlAttrPtr attr);

        void goToParent(XMLNode& node);

        static void goToParent(
          const XMLAttr& attr,
          XMLNode& node
        );

        static void goToParent(
          xmlAttrPtr attr,
          XMLNode& node
        );

        bool hasParent() const;

        static bool hasParent(const XMLAttr& attr);

        static bool hasParent(xmlAttrPtr attr);

        XMLAttr getNextSibling() const;

        static XMLAttr getNextSibling(const XMLAttr& attr);

        static XMLAttr getNextSibling(xmlAttrPtr attr);

        xmlAttrPtr getRawNextSibling() const;

        static xmlAttrPtr getRawNextSibling(const XMLAttr& attr);

        static xmlAttrPtr getRawNextSibling(xmlAttrPtr attr);

        void goToNextSibling();

        static void goToNextSibling(XMLAttr& attr);

        bool hasNextSibling() const;

        static bool hasNextSibling(const XMLAttr& attr);

        static bool hasNextSibling(xmlAttrPtr attr);

        XMLAttr getPreviousSibling() const;

        static XMLAttr getPreviousSibling(const XMLAttr& attr);

        static XMLAttr getPreviousSibling(xmlAttrPtr attr);

        xmlAttrPtr getRawPreviousSibling() const;

        static xmlAttrPtr getRawPreviousSibling(const XMLAttr& attr);

        static xmlAttrPtr getRawPreviousSibling(xmlAttrPtr attr);

        void goToPreviousSibling();

        static void goToPreviousSibling(XMLAttr& attr);

        bool hasPreviousSibling() const;

        static bool hasPreviousSibling(const XMLAttr& attr);

        static bool hasPreviousSibling(xmlAttrPtr attr);
    };

#define _BGS_PLATFORM_LIBDATASET_XML_XML_ATTR_T_
#include "libdataset/xml/XMLAttr.t"
#undef  _BGS_PLATFORM_LIBDATASET_XML_XML_ATTR_T_
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_XML_ATTR_H_ */
