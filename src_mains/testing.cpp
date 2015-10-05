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
#include <aggregator.h>

using namespace std;
using namespace rag;

int main(int argc, char** argv) {
	cout << "LibRAG 0.1 Testing" << endl;

	Aggregator<string>::ptr aggregator = Aggregator<string>::create("list", "kemeny-median");
	Aggregator<string>::RList* list1 = new Aggregator<string>::RList;
	Aggregator<string>::RList* list2 = new Aggregator<string>::RList;
	Aggregator<string>::RList* list3 = new Aggregator<string>::RList;

	list1->push_back("Melissa");
	list1->push_back("Elodie");
	list1->push_back("Nathalie");
	list1->push_back("Enora");
	list1->push_back("Melanie");

	list2->push_back("Enora");
	list2->push_back("Melissa");
	list2->push_back("Elodie");
	list2->push_back("Nathalie");
	list2->push_back("Melanie");

	list3->push_back("Elodie");
	list3->push_back("Melanie");
	list3->push_back("Nathalie");
	list3->push_back("Enora");
	list3->push_back("Melissa");

	aggregator->add_ranking(list1, "list1");
	aggregator->add_ranking(list2, "list2");
	aggregator->add_ranking(list3, "list3");
	aggregator->run();

	Aggregator<string>::RList aggregation = aggregator->get_result();
	int rank = 1;

	cout << endl;
	cout << "Final aggregation:\n\n";

	for (string item : aggregation) {
		cout << rank++ << " :: " << item << endl;
	}

	delete(list1);
	delete(list2);
	delete(list3);

	return 0;
}




