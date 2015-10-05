//! \file 				  aggregator.t
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Oct 5, 2015
#ifdef _LIB_RAG_AGGREGATOR_T_

#include <iostream>

using namespace std;

/*=============================================================================*/

template <class T>
Aggregator<T>::~Aggregator() {}

/*=============================================================================*/

template <class T>
inline void Aggregator<T>::add_ranking(const RList* list, string name) {
	inputs_.push_back(list);
	inputs_names_.push_back(name);
}

/*=============================================================================*/

template <class T>
inline typename Aggregator<T>::RList Aggregator<T>::get_result() {
  return rank_aggregator_->get_aggregation();
}

/*=============================================================================*/

#else 	/* _LIB_RAG_AGGREGATOR_T_ */
#error
#endif /* _LIB_RAG_AGGREGATOR_T_ */


