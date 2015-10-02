/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_VISITORS_XML_PRINT_VISITOR_H_
#define _BGS_PLATFORM_LIBDATASET_XML_VISITORS_XML_PRINT_VISITOR_H_

#include <map>

#include "libdataset/xml/XMLVisitor.h"

namespace BGS_Platform {
  namespace libdataset {
    class XMLPrintVisitor : public XMLVisitor {
      public:

        typedef XMLVisitor                                                Base;

      protected:

        std::map<size_t, bool> lastElementEmpty;
        std::map<size_t, std::string> lastElement;
        std::map<size_t, bool> closed;
        size_t previousLevel;

      public:

        XMLPrintVisitor() : Base(PRE_ORDER), lastElementEmpty(), lastElement(), closed(), previousLevel(0) {}

        virtual ~XMLPrintVisitor() {}

      public:

        virtual void startVisit();

        virtual void endVisit();

        virtual void visitElementNode(XMLNode& node, size_t level = 0);

        virtual void visitAttributeNode(XMLAttr& attr, size_t level = 0);

        virtual void visitTextNode(XMLNode& node, size_t level = 0);

        virtual void visitCDATASectionNode(XMLNode& node, size_t level = 0);

        virtual void visitEntityRefNode(XMLNode& node, size_t level = 0);

        virtual void visitEntityNode(XMLNode& node, size_t level = 0);

        virtual void visitPINode(XMLNode& node, size_t level = 0);

        virtual void visitCommentNode(XMLNode& node, size_t level = 0);

        virtual void visitDocumentNode(XMLNode& node, size_t level = 0);

        virtual void visitDocumentTypeNode(XMLNode& node, size_t level = 0);

        virtual void visitDocumentFragNode(XMLNode& node, size_t level = 0);

        virtual void visitNotationNode(XMLNode& node, size_t level = 0);

        virtual void visitHTMLDocumentNode(XMLNode& node, size_t level = 0);

        virtual void visitDTDNode(XMLNode& node, size_t level = 0);

        virtual void visitElementDecl(XMLNode& node, size_t level = 0);

        virtual void visitAttributeDecl(XMLNode& node, size_t level = 0);

        virtual void visitEntityDecl(XMLNode& node, size_t level = 0);

        virtual void visitNamespaceDecl(XMLNode& node, size_t level = 0);

        virtual void visitXIncludeStart(XMLNode& node, size_t level = 0);

        virtual void visitXIncludeEnd(XMLNode& node, size_t level = 0);

        virtual void visitDOCBDocumentNode(XMLNode& node, size_t level = 0);

      protected:

        void closeLastElement(size_t level);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_XML_VISITOR_H_ */
