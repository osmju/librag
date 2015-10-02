/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_XML_NODE_H_
#define _BGS_PLATFORM_LIBDATASET_XML_XML_NODE_H_

#include <cstddef>
#include <string>

#include <libxml/tree.h>

#include "libdataset/exceptions/exceptions.h"
#include "libdataset/xml/adapters/libxml2/AllocatorAdapter.h"
#include "libdataset/xml/adapters/libxml2/CharAdapter.h"

namespace BGS_Platform {
  namespace libdataset {
    class XMLAttr;
    class XMLVisitor;

    class XMLNode {
      protected:

        xmlNodePtr node;

      public:

        XMLNode(xmlNodePtr node = NULL);

        virtual ~XMLNode();

        xmlNodePtr getMember() const;

        void setMember(xmlNodePtr node);

        bool exists() const;

        static bool exists(const XMLNode& node);

        static bool exists(const xmlNodePtr node);

        long int getLine() const;

        static long int getLine(const XMLNode& node);

        static long int getLine(xmlNodePtr node);

        std::string getName() const;

        static std::string getName(const XMLNode& node);

        static std::string getName(xmlNodePtr node);

        void* getPrivate() const;

        static void* getPrivate(const XMLNode& node);

        static void* getPrivate(xmlNodePtr node);

        void setPrivate(void* _private);

        static void setPrivate(const XMLNode& node, void* _private);

        static void setPrivate(xmlNodePtr node, void* _private);

        std::string getContent() const;

        static std::string getContent(const XMLNode& node);

        static std::string getContent(xmlNodePtr node);

        XMLNode getChild() const;

        static XMLNode getChild(const XMLNode& node);

        static XMLNode getChild(xmlNodePtr node);

        xmlNodePtr getRawChild() const;

        static xmlNodePtr getRawChild(const XMLNode& node);

        static xmlNodePtr getRawChild(xmlNodePtr node);

        void goToChild();

        static void goToChild(XMLNode& node);

        bool hasChild() const;

        static bool hasChild(const XMLNode& node);

        static bool hasChild(xmlNodePtr node);

        XMLNode getLastChild() const;

        static XMLNode getLastChild(const XMLNode& node);

        static XMLNode getLastChild(xmlNodePtr node);

        xmlNodePtr getRawLastChild() const;

        static xmlNodePtr getRawLastChild(const XMLNode& node);

        static xmlNodePtr getRawLastChild(xmlNodePtr node);

        void goToLastChild();

        static void goToLastChild(XMLNode& node);

        bool hasLastChild() const;

        static bool hasLastChild(const XMLNode& node);

        static bool hasLastChild(xmlNodePtr node);

        XMLNode getParent() const;

        static XMLNode getParent(const XMLNode& node);

        static XMLNode getParent(xmlNodePtr node);

        xmlNodePtr getRawParent() const;

        static xmlNodePtr getRawParent(const XMLNode& node);

        static xmlNodePtr getRawParent(xmlNodePtr node);

        void goToParent();

        static void goToParent(XMLNode& node);

        bool hasParent() const;

        static bool hasParent(const XMLNode& node);

        static bool hasParent(xmlNodePtr node);

        XMLNode getNextSibling() const;

        static XMLNode getNextSibling(const XMLNode& node);

        static XMLNode getNextSibling(xmlNodePtr node);

        xmlNodePtr getRawNextSibling() const;

        static xmlNodePtr getRawNextSibling(const XMLNode& node);

        static xmlNodePtr getRawNextSibling(xmlNodePtr node);

        void goToNextSibling();

        static void goToNextSibling(XMLNode& node);

        bool hasNextSibling() const;

        static bool hasNextSibling(const XMLNode& node);

        static bool hasNextSibling(xmlNodePtr node);

        XMLNode getPrevious() const;

        static XMLNode getPrevious(const XMLNode& node);

        static XMLNode getPrevious(xmlNodePtr node);

        xmlNodePtr getRawPrevious() const;

        static xmlNodePtr getRawPrevious(const XMLNode& node);

        static xmlNodePtr getRawPrevious(xmlNodePtr node);

        void goToPrevious();

        static void goToPrevious(XMLNode& node);

        bool hasPrevious() const;

        static bool hasPrevious(const XMLNode& node);

        static bool hasPrevious(xmlNodePtr node);

        XMLAttr getAttributes() const;

        static XMLAttr getAttributes(const XMLNode& node);

        static XMLAttr getAttributes(xmlNodePtr node);

        xmlAttrPtr getRawAttributes() const;

        static xmlAttrPtr getRawAttributes(const XMLNode& node);

        static xmlAttrPtr getRawAttributes(xmlNodePtr node);

        void goToAttributes(XMLAttr& attr) const;

        static void goToAttributes(
          const XMLNode& node,
          XMLAttr& attr
        );

        static void goToAttributes(
          xmlNodePtr node,
          XMLAttr& attr
        );

        bool hasAttributes() const;

        static bool hasAttributes(const XMLNode& node);

        static bool hasAttributes(xmlNodePtr node);

        xmlElementType getType() const;

        static xmlElementType getType(const XMLNode& node);

        static xmlElementType getType(xmlNodePtr node);

        bool isBlankNode() const;

        static bool isBlankNode(const XMLNode& node);

        static bool isBlankNode(xmlNodePtr node);

        bool isElementNode() const;

        static bool isElementNode(const XMLNode& node);

        static bool isElementNode(xmlNodePtr node);

        bool isAttributeNode() const;

        static bool isAttributeNode(const XMLNode& node);

        static bool isAttributeNode(xmlNodePtr node);

        bool isTextNode() const;

        static bool isTextNode(const XMLNode& node);

        static bool isTextNode(xmlNodePtr node);

        bool isCDATASectionNode() const;

        static bool isCDATASectionNode(const XMLNode& node);

        static bool isCDATASectionNode(xmlNodePtr node);

        bool isEntityRefNode() const;

        static bool isEntityRefNode(const XMLNode& node);

        static bool isEntityRefNode(xmlNodePtr node);

        bool isEntityNode() const;

        static bool isEntityNode(const XMLNode& node);

        static bool isEntityNode(xmlNodePtr node);

        bool isPINode() const;

        static bool isPINode(const XMLNode& node);

        static bool isPINode(xmlNodePtr node);

        bool isCommentNode() const;

        static bool isCommentNode(const XMLNode& node);

        static bool isCommentNode(xmlNodePtr node);

        bool isDocumentNode() const;

        static bool isDocumentNode(const XMLNode& node);

        static bool isDocumentNode(xmlNodePtr node);

        bool isDocumentTypeNode() const;

        static bool isDocumentTypeNode(const XMLNode& node);

        static bool isDocumentTypeNode(xmlNodePtr node);

        bool isDocumentFragNode() const;

        static bool isDocumentFragNode(const XMLNode& node);

        static bool isDocumentFragNode(xmlNodePtr node);

        bool isNotationNode() const;

        static bool isNotationNode(const XMLNode& node);

        static bool isNotationNode(xmlNodePtr node);

        bool isHTMLDocumentNode() const;

        static bool isHTMLDocumentNode(const XMLNode& node);

        static bool isHTMLDocumentNode(xmlNodePtr node);

        bool isDTDNode() const;

        static bool isDTDNode(const XMLNode& node);

        static bool isDTDNode(xmlNodePtr node);

        bool isElementDecl() const;

        static bool isElementDecl(const XMLNode& node);

        static bool isElementDecl(xmlNodePtr node);

        bool isAttributeDecl() const;

        static bool isAttributeDecl(const XMLNode& node);

        static bool isAttributeDecl(xmlNodePtr node);

        bool isEntityDecl() const;

        static bool isEntityDecl(const XMLNode& node);

        static bool isEntityDecl(xmlNodePtr node);

        bool isNamespaceDecl() const;

        static bool isNamespaceDecl(const XMLNode& node);

        static bool isNamespaceDecl(xmlNodePtr node);

        bool isXIncludeStart() const;

        static bool isXIncludeStart(const XMLNode& node);

        static bool isXIncludeStart(xmlNodePtr node);

        bool isXIncludeEnd() const;

        static bool isXIncludeEnd(const XMLNode& node);

        static bool isXIncludeEnd(xmlNodePtr node);

        bool isDOCBDocumentNode() const;

        static bool isDOCBDocumentNode(const XMLNode& node);

        static bool isDOCBDocumentNode(xmlNodePtr node);

        std::string typeToString() const;

        static std::string typeToString(xmlElementType type);

        void visit(XMLVisitor& visitor);

      protected:

        static void visitPreOrder(
          XMLNode& node,
          XMLAttr& attr,
          XMLVisitor& visitor,
          size_t level = 0
        );

        static void visitPostOrder(
          XMLNode& node,
          XMLAttr& attr,
          XMLVisitor& visitor,
          size_t level = 0
        );

        static void visitNode(
          XMLNode& node,
          XMLVisitor& visitor,
          size_t level
        );

        static void visitAttr(
          XMLAttr& attr,
          XMLVisitor& visitor,
          size_t level
        );
    };

#define _BGS_PLATFORM_LIBDATASET_XML_XML_NODE_T_
#include "libdataset/xml/XMLNode.t"
#undef  _BGS_PLATFORM_LIBDATASET_XML_XML_NODE_T_
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform _ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_XML_NODE_H_ */
