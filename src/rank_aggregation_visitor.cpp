//! \file 				  rank_aggregation_visitor.cpp
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Sep 29, 2015
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include "rank_aggregation_visitor.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/*=============================================================================*/

void RankAggregationVisitor::startVisit() {}

/*=============================================================================*/

void RankAggregationVisitor::endVisit() {}

/*=============================================================================*/

void RankAggregationVisitor::cleanup() {
	int nb_pointers = list_pointers_.size();

  for (int i = 0; i < nb_pointers; ++i) {
  	delete(list_pointers_[i]);
  }
}

/*=============================================================================*/

void RankAggregationVisitor::visitElementNode(XMLNode& node, size_t) {
  if (node.getName() == "rule") {
    XMLAttr attr = node.getAttributes();
    string aggregation_rule = attr.getContent();

    // create new rank aggregator
    RAggregator::ptr aggregator = rag::RankAggregator<int>::create(aggregation_rule);
    RAggregator::rlist* node_list = new RAggregator::rlist;

    // push pointer to list so that it can be easily deleted later
    list_pointers_.push_back(node_list);

    XMLNode currentChild = node.getChild();

    while (true) {
      if (currentChild.getName() == "list") {
      	int list_number = boost::lexical_cast<int>(currentChild.getContent());

      	aggregator->add_ranking(inputs_[list_number]);
      }

      if (currentChild.getName() == "rule") {
        RAggregator::rlist* child_list = (RAggregator::rlist*)(currentChild.getPrivate());

        aggregator->add_ranking(child_list);
      }

      if (currentChild.hasNextSibling())
      	currentChild.goToNextSibling();
      else
      	break;
    }

    aggregator->aggregate();

    const RAggregator::rlist result = aggregator->get_aggregation();
    int result_size = result.size();

    for (int i = 0; i < result_size; ++i) {
    	node_list->push_back(result.at(i));
    }

    node.setPrivate((void*)(node_list));
  }
}

/*=============================================================================*/

void RankAggregationVisitor::visitAttributeNode(XMLAttr&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitTextNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitCDATASectionNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitEntityRefNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitEntityNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitPINode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitCommentNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitDocumentNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitDocumentTypeNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitDocumentFragNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitNotationNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitHTMLDocumentNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitDTDNode(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitElementDecl(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitAttributeDecl(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitEntityDecl(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitNamespaceDecl(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitXIncludeStart(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitXIncludeEnd(XMLNode&, size_t) {}

/*=============================================================================*/

void RankAggregationVisitor::visitDOCBDocumentNode(XMLNode&, size_t) {}

/*=============================================================================*/
