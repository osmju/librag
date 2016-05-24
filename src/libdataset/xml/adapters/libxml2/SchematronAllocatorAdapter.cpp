// Copyright (C) 2016   Benjamin Laugraud
//
// This file is part of LibDataset.
//
// LibDataset is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LibDataset is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with LibDataset.  If not, see http://www.gnu.org/licenses.
#include <cstddef>
#include <sstream>

#include "libdataset/exceptions/exceptions.h"
#include "libdataset/xml/adapters/libxml2/SchematronAllocatorAdapter.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * SchematronAllocatorAdapter                                                 *
 * ========================================================================== */

SchematronAllocatorAdapter::SchematronAllocatorAdapter() {}

/******************************************************************************/

SchematronAllocatorAdapter::~SchematronAllocatorAdapter() {}

/******************************************************************************/

xmlSchematronParserCtxtPtr SchematronAllocatorAdapter::newParser(string file) {
  return newParser(file.c_str());
}

/******************************************************************************/

xmlSchematronValidCtxtPtr SchematronAllocatorAdapter::newValidator(
  xmlSchematronPtr schema
) {
  xmlSchematronValidCtxtPtr validator;

  // TODO Better options support.
  if ((validator = xmlSchematronNewValidCtxt(schema, 8)) == NULL) {
    throw CannotInstantiateSchematronValidatorException(
      __LINE__,
      __FILE__,
      "Cannot instantiate a Schematron validator"
    );
  }

  return validator;
}

/******************************************************************************/

xmlSchematronParserCtxtPtr SchematronAllocatorAdapter::newParser(
  const char* file
) {
  xmlSchematronParserCtxtPtr parser;

  if ((parser = xmlSchematronNewParserCtxt(file)) == NULL) {
    stringstream ss;
    ss << "Cannot read Schematron rules from " << file << " file. Either it ";
    ss << "is absent or it is corrupted.";

    throw CannotReadSchematronRulesException(
      __LINE__,
      __FILE__,
      ss.str()
    );
  }

  return parser;
}

/******************************************************************************/

void SchematronAllocatorAdapter::free(xmlSchematronPtr schema) {
  xmlSchematronFree(schema);
}

/******************************************************************************/

void SchematronAllocatorAdapter::freeParser(
  xmlSchematronParserCtxtPtr parser
) {
  xmlSchematronFreeParserCtxt(parser);
}

/******************************************************************************/

void SchematronAllocatorAdapter::freeValidator(
  xmlSchematronValidCtxtPtr validator
) {
  xmlSchematronFreeValidCtxt(validator);
}
