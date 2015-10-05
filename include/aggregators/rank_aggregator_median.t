#include <iostream>
#include "aggregators/rank_aggregator_median.h"

using namespace std;
using namespace rag;

/*=============================================================================*/

template <class T>
AggregatorMedian<T>::AggregatorMedian()
: RankAggregator<T>() {}

/*=============================================================================*/

template <class T>
AggregatorMedian<T>::~AggregatorMedian() {}

/*=============================================================================*/

template <class T>
void AggregatorMedian<T>::aggregate() {
	Base::build_ranking_map();
	Base::aggregated_list_.clear();
	typename Base::rating median_scores;
	int nb_objects = Base::lists_max_size();

	for (auto item : Base::objects_ranks_) {
		T key = item.first;
		ivectptr ranks = item.second;
		float ranks_median = median(ranks);

		typename Base::object_score current_item_score(ranks_median, key);
		median_scores.push_back(current_item_score);
	}

	sort(median_scores.begin(), median_scores.end());

	// now build final list
	for (int i = 0; i < nb_objects; ++i) {
		T object = std::get<1>(median_scores[i]);
		Base::aggregated_list_.push_back(object);
	}
}

/*=============================================================================*/

template <class T>
float AggregatorMedian<T>::median(const ivectptr ranks) const {
	int nb_ranks = ranks->size();
	float final_rank = 0.0;

	sort(ranks->begin(), ranks->end());

	if (nb_ranks % 2 == 0) {
		final_rank = (ranks->at(nb_ranks/2 - 1) + ranks->at(nb_ranks/2)) / 2;
	}
	else {
		final_rank = ranks->at(nb_ranks / 2);
	}

	return final_rank;
}

/*=============================================================================*/
