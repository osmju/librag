/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_XML_DOCUMENT_H_
#define _BGS_PLATFORM_LIBDATASET_XML_XML_DOCUMENT_H_

#include <string>

#include <libxml/tree.h>

#include "libdataset/xml/XMLNode.h"
#include "libdataset/xml/XMLVisitor.h"

namespace BGS_Platform {
  namespace libdataset {
    class XMLDocument {
      protected:

        std::string file;
        xmlDocPtr document;

      public:

        XMLDocument(std::string file);

        virtual ~XMLDocument();

        const std::string& getFile() const;

        xmlDocPtr getDocPtr() const;

        XMLNode getRoot() const;

        void goToRoot(XMLNode& node) const;

        void visit(XMLVisitor& visitor);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_XML_DOCUMENT_H_ */
