//! \file		testing.cpp
//! \brief 	File used for various tests.
//!
//! The only purpose of this file is to perform some basic testing about anything that
//! need to be tested. This is not to be used for production. Only a helper file for
//! developers.
//!
//! \author Julien Osmalskyj
//! \date   24 mars 2015

//! \file patches.cpp
//! \brief Replace by short description
//!
//! \author Julien Osmalskyj
//! \date   16 juin 2015

#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <boost/random.hpp>
#include <boost/program_options.hpp>
#include <aggregators/rank_aggregator.h>

using namespace std;
using namespace rag;

int main(int argc, char** argv) {
	typedef RankAggregator<string>::rlist rk_list;

	RankAggregator<string>::ptr aggregator = RankAggregator<string>::create("median");
	//aggregator->set_initial_aggregation("mean");

	rk_list*  list = new rk_list;

	list->push_back("Melissa");
	list->push_back("Elodie");
	list->push_back("Nathalie");
	list->push_back("Enora");

	rk_list*  list2 = new rk_list;

	list2->push_back("Enora");
	list2->push_back("Melissa");
	list2->push_back("Elodie");
	list2->push_back("Nathalie");
	list2->push_back("Melanie");

	rk_list*  list3 = new rk_list;

	list3->push_back("Elodie");
	list3->push_back("Melanie");
	list3->push_back("Nathalie");
	list3->push_back("Enora");
	list3->push_back("Melissa");

	aggregator->add_ranking(list);
	aggregator->add_ranking(list2);
	aggregator->add_ranking(list3);

	int nb_rankings = aggregator->nb_rankings();

	cout << "Max length: " << aggregator->lists_max_size() << endl;
	cout << "Number of rankings: " << nb_rankings << endl;

	aggregator->aggregate();

	const rk_list& aggregation = aggregator->get_aggregation();
	int rank = 1;

	cout << endl;
	cout << "Final aggregation:\n\n";

	for (string item : aggregation) {
		cout << rank++ << " :: " << item << endl;
	}

	delete(list);
	delete(list2);
	delete(list3);

	return 0;
}




