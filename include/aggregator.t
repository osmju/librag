//! \file 				  aggregator.t
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Oct 5, 2015
#ifdef _LIB_RAG_AGGREGATOR_T_

/*=============================================================================*/

template <class T>
Aggregator<T>::Aggregator() {
	final_aggregation_ = RList_ptr(new RList);
}

/*=============================================================================*/

template <class T>
Aggregator<T>::~Aggregator() {}

/*=============================================================================*/

template <class T>
inline void Aggregator<T>::add_ranking(const RList* list, std::string name) {
	inputs_.push_back(list);
	inputs_names_.push_back(name);
}

/*=============================================================================*/

template <class T>
inline typename Aggregator<T>::RList_ptr Aggregator<T>::get_result() {
  return final_aggregation_;
}

/*=============================================================================*/

template <class T>
inline void Aggregator<T>::cleanup() {
	inputs_.clear();
	inputs_names_.clear();
	final_aggregation_->clear();
}

/*=============================================================================*/

template <class T>
typename Aggregator<T>::ptr Aggregator<T>::create(std::string type, std::string option) {
	if (type == "list") {
		return typename Aggregator::ptr(new AggregatorList<T>(option));
	}
	else if (type == "xml") {
		return typename Aggregator::ptr(new AggregatorXML<T>(option));
	}
	else {
		throw std::runtime_error("Wrong Aggregator identifier.");
	}

}

/*=============================================================================*/

#else 	/* _LIB_RAG_AGGREGATOR_T_ */
#error
#endif /* _LIB_RAG_AGGREGATOR_T_ */


