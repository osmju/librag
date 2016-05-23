// Copyright (C) 2016   Julien Osmalskyj
//
// This file is part of LibRAG.
//
// LibRAG is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LibRAG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with LibRAG.  If not, see http://www.gnu.org/licenses.

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


