//! \file 				  rank_aggregation_visitor.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Sep 29, 2015

#ifndef RANK_AGGREGATION_VISITOR_H_
#define RANK_AGGREGATION_VISITOR_H_

#include <vector>
#include "libdataset/xml/XMLVisitor.h"
#include "aggregators/rank_aggregator.h"

namespace BGS_Platform {
  namespace libdataset {
    class RankAggregationVisitor : public XMLVisitor {
    		typedef rag::RankAggregator<int> RAggregator;

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

        void add_input_list(const RAggregator::rlist* input_list) {
        	inputs_.push_back(input_list);
        }

        std::vector<const RAggregator::rlist*>& get_inputs_ptrs() {
        	return inputs_;
        }

        void cleanup();

      protected:
        void closeLastElement(size_t level);

      private:
        std::vector<RAggregator::rlist*> list_pointers_;
        std::vector<const RAggregator::rlist*> inputs_;

    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* RANK_AGGREGATION_VISITOR_H_ */
