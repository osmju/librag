// Copyright (C) 2016   Julien Osmalskyj
//
// This file is part of LibRAG.
//
// LibRAG is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LibRAG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with LibRAG.  If not, see http://www.gnu.org/licenses.

#include <iostream>
#include <aggregator.h>

using namespace std;
using namespace rag;

int main(int argc, char** argv) {
	cout << "LibRAG 0.1 -- XML Aggregation Example" << endl;

	// Instantiate a new Aggregator object of type STRING.
	// Here we create an XML aggregator (type "xml") and the path of the input
	// XML file containing the rules is "../xml/rules_example_single.xml".
	//
	// The file "rules_example_single.xml" performs a single Kemeny-Mean aggregation of the
	// 3 input rankings. Rankings identifiers start at 0 and follow the order of insertion into
	// the Aggregator object.
	//
	// For an example of hierarchical aggregation, change the path to
	// "../xml/rules_example_hierarchy.xml".

	//Aggregator<string>::ptr aggregator = Aggregator<string>::create("xml", "../xml/rules_example_hierarchical	.xml");
	Aggregator<string>::ptr aggregator = Aggregator<string>::create("xml", "../xml/rules_example_single.xml");

	// Create 3 rankings containing String values. We want to aggregate all three
	// ranking using the "kemeny-mean" rule.
	Aggregator<string>::RList* list1 = new Aggregator<string>::RList;
	Aggregator<string>::RList* list2 = new Aggregator<string>::RList;
	Aggregator<string>::RList* list3 = new Aggregator<string>::RList;

	// Fill input rankings with values.
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

	// Add ranking to the rank aggregator.
	aggregator->add_ranking(list1);
	aggregator->add_ranking(list2);
	aggregator->add_ranking(list3);

	// run aggregation using the kemeny-mean rule
	aggregator->run();

	// Retrieve final aggregation of the input rankings.
	// The returned object is a RList_ptr, which is a smart pointer to
	// a RList ranking. Use it as a normal pointer. There is no need to
	// delete this object.
	Aggregator<string>::RList_ptr aggregation = aggregator->get_result();
	int rank = 1;

	cout << endl;
	cout << "Final aggregation:\n\n";

	// Display final aggregation in the CLI.
	for (string item : *aggregation) {
		cout << rank++ << " :: " << item << endl;
	}

	// cleanup
	delete(list1);
	delete(list2);
	delete(list3);

	aggregator->cleanup();

	return 0;
}




