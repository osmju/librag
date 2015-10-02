//! \file 				  rank_aggregator.h
//! \brief				brief description here
//!
//!	\author		josmalskyj
//! \date				Sep 22, 2015


#ifndef RANK_AGGREGATOR_H_
#define RANK_AGGREGATOR_H_

#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include "types.h"

namespace rag {

	template <class T>
	class RankAggregator {
		public:
			typedef std::shared_ptr<RankAggregator>		ptr;
			typedef std::shared_ptr<ivect>							ivectptr;
			typedef std::vector<T> 		   							rlist;
			typedef std::shared_ptr<rlist>							rlist_ptr;
			typedef std::vector<const rlist*>					rmatrix;
			typedef std::unordered_map<T, ivectptr>    rankmap;
			typedef std::tuple<float, T>	 							object_score;
			typedef std::vector<object_score>	 				rating;


			virtual ~RankAggregator();

			void add_ranking(const rlist* ranking);
			const rlist* get_ranking(int ranking_id) const;
			const rlist get_aggregation() const;
			int nb_rankings() const;
			int lists_max_size() const;
			virtual void aggregate() = 0;


			virtual void set_initial_aggregation(std::string initial_aggregation) {
				throw std::runtime_error("Not implemented in this aggregator.");
			}

			// factory method
			static ptr create(std::string name);

			static rlist_ptr new_rlist();


		protected:
			rmatrix rankings_;
			rlist aggregated_list_;
			rankmap objects_ranks_;
			int nb_rankings_;

			RankAggregator();
			void build_ranking_map();
	};

} /* namsepace rag */

#include "aggregators/rank_aggregator.t"




#endif /* RANK_AGGREGATOR_H_ */
