/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_XML_VISITOR_H_
#define _BGS_PLATFORM_LIBDATASET_XML_XML_VISITOR_H_

#include <cstddef>

#include "libdataset/xml/XMLAttr.h"
#include "libdataset/xml/XMLNode.h"

namespace BGS_Platform {
  namespace libdataset {
    class XMLVisitor {

        friend class XMLNode;

      public:

        enum Traversal {
          PRE_ORDER,
          POST_ORDER
        };

      protected:

        Traversal traversal;

      private:

        XMLVisitor() {}

      protected:

        XMLVisitor(Traversal traversal) : traversal(traversal) {}

        virtual ~XMLVisitor() {}

      public:

        virtual void startVisit() = 0;

        virtual void endVisit() = 0;

        virtual void visitElementNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitAttributeNode(XMLAttr& attr, size_t level = 0) = 0;

        virtual void visitTextNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitCDATASectionNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitEntityRefNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitEntityNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitPINode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitCommentNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitDocumentNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitDocumentTypeNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitDocumentFragNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitNotationNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitHTMLDocumentNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitDTDNode(XMLNode& node, size_t level = 0) = 0;

        virtual void visitElementDecl(XMLNode& node, size_t level = 0) = 0;

        virtual void visitAttributeDecl(XMLNode& node, size_t level = 0) = 0;

        virtual void visitEntityDecl(XMLNode& node, size_t level = 0) = 0;

        virtual void visitNamespaceDecl(XMLNode& node, size_t level = 0) = 0;

        virtual void visitXIncludeStart(XMLNode& node, size_t level = 0) = 0;

        virtual void visitXIncludeEnd(XMLNode& node, size_t level = 0) = 0;

        virtual void visitDOCBDocumentNode(XMLNode& node, size_t level = 0) = 0;

      protected:

        Traversal getTraversal() {
          return traversal;
        }
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_XML_VISITOR_H_ */
