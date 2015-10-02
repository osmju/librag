//! \file 				  rank_aggregator_kemeny.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Sep 23, 2015


#ifndef RANK_AGGREGATOR_KEMENY_H_
#define RANK_AGGREGATOR_KEMENY_H_

#include "aggregators/rank_aggregator.h"

namespace rag {

	template <class T>
	class AggregatorKemeny : public RankAggregator<T> {
		public:
			typedef RankAggregator<T> Base;

			AggregatorKemeny();
			virtual ~AggregatorKemeny();

			virtual void aggregate();
			virtual void set_initial_aggregation(std::string initial_aggregation = "median");

		private:
			bool is_preferred(T item1, T item2);
			void swap(typename Base::rlist& list, int index1, int index2);

			bool is_mapping_built_;
			std::string initial_aggregation_;
	};

}

#include "aggregators/rank_aggregator_kemeny.t"


#endif /* RANK_AGGREGATOR_KEMENY_H_ */
