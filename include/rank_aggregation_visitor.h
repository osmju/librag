//! \file 				  rank_aggregation_visitor.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Sep 29, 2015

#ifndef RANK_AGGREGATION_VISITOR_H_
#define RANK_AGGREGATION_VISITOR_H_

#include <iostream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include "libdataset/xml/XMLVisitor.h"
#include "aggregators/rank_aggregator.h"

namespace BGS_Platform {
  namespace libdataset {

  	template <class T>
    class RankAggregationVisitor : public XMLVisitor {
    		typedef rag::RankAggregator<T> RAggregator;

      public:
        typedef XMLVisitor                                                Base;

      public:
        RankAggregationVisitor() : Base(POST_ORDER) {}

        virtual ~RankAggregationVisitor() {}

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

        void add_input_list(const typename RAggregator::rlist* input_list);

        void cleanup();

      protected:
        void closeLastElement(size_t level);

      private:
        std::vector<typename RAggregator::rlist*> list_pointers_;
        std::vector<const typename RAggregator::rlist*> inputs_;

    };

#define _LIB_RAG_RANK_AGGREGATION_VISITOR_T_
#include "rank_aggregation_visitor.t"
#undef _LIB_RAG_RANK_AGGREGATION_VISITOR_T_
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* RANK_AGGREGATION_VISITOR_H_ */
