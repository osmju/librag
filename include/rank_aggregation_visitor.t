#ifdef _LIB_RAG_RANK_AGGREGATION_VISITOR_T_

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::startVisit() {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::endVisit() {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::cleanup() {
	int nb_pointers = list_pointers_.size();

  for (int i = 0; i < nb_pointers; ++i) {
  	delete(list_pointers_[i]);
  }
}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitElementNode(XMLNode& node, size_t) {
  if (node.getName() == "rule") {
    XMLAttr attr = node.getAttributes();
    std::string aggregation_rule = attr.getContent();

    // create new rank aggregator
    typename RAggregator::ptr aggregator = RAggregator::create(aggregation_rule);
    typename RAggregator::rlist* node_list = new typename RAggregator::rlist;

    // push pointer to list so that it can be easily deleted later
    list_pointers_.push_back(node_list);

    XMLNode currentChild = node.getChild();

    while (true) {
      if (currentChild.getName() == "list") {
      	int list_number = boost::lexical_cast<int>(currentChild.getContent());

      	aggregator->add_ranking(inputs_[list_number]);
      }

      if (currentChild.getName() == "rule") {
        typename RAggregator::rlist* child_list =
        		(typename RAggregator::rlist*)(currentChild.getPrivate());

        aggregator->add_ranking(child_list);
      }

      if (currentChild.hasNextSibling())
      	currentChild.goToNextSibling();
      else
      	break;
    }

    aggregator->aggregate();

    const typename RAggregator::rlist_ptr result = aggregator->get_aggregation();
    int result_size = result->size();

    for (int i = 0; i < result_size; ++i) {
    	node_list->push_back(result->at(i));
    }

    node.setPrivate((void*)(node_list));
  }
}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitAttributeNode(XMLAttr&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitTextNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitCDATASectionNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitEntityRefNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitEntityNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitPINode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitCommentNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitDocumentNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitDocumentTypeNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitDocumentFragNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitNotationNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitHTMLDocumentNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitDTDNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitElementDecl(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitAttributeDecl(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitEntityDecl(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitNamespaceDecl(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitXIncludeStart(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitXIncludeEnd(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::visitDOCBDocumentNode(XMLNode&, size_t) {}

/*=============================================================================*/

template <class T>
void RankAggregationVisitor<T>::add_input_list(const typename RAggregator::rlist* input_list) {
	inputs_.push_back(input_list);
}

/*=============================================================================*/

#else		/* _LIB_RAG_RANK_AGGREGATION_VISITOR_T_ */
#error
#endif /* _LIB_RAG_RANK_AGGREGATION_VISITOR_T_ */
