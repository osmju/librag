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
#include "libdataset/xml/adapters/libxml2/RelaxNGAllocatorAdapter.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * RelaxNGAllocatorAdapter                                                    *
 * ========================================================================== */

RelaxNGAllocatorAdapter::RelaxNGAllocatorAdapter() {}

/******************************************************************************/

RelaxNGAllocatorAdapter::~RelaxNGAllocatorAdapter() {}

/******************************************************************************/

xmlRelaxNGParserCtxtPtr RelaxNGAllocatorAdapter::newParser(string file) {
  return newParser(file.c_str());
}

/******************************************************************************/

xmlRelaxNGValidCtxtPtr RelaxNGAllocatorAdapter::newValidator(
  xmlRelaxNGPtr schema
) {
  xmlRelaxNGValidCtxtPtr validator;

  if ((validator = xmlRelaxNGNewValidCtxt(schema)) == NULL) {
    throw CannotInstantiateRelaxNGValidatorException(
      __LINE__,
      __FILE__,
      "Cannot instantiate a RelaxNG validator"
    );
  }

  return validator;
}

/******************************************************************************/

xmlRelaxNGParserCtxtPtr RelaxNGAllocatorAdapter::newParser(const char* file) {
  xmlRelaxNGParserCtxtPtr parser;

  if ((parser = xmlRelaxNGNewParserCtxt(file)) == NULL) {
    stringstream ss;
    ss << "Cannot read Relax NG grammar from " << file << " file. Either it ";
    ss << "is absent or it is corrupted.";

    throw CannotReadRelaxNGGrammarException(
      __LINE__,
      __FILE__,
      ss.str()
    );
  }

  return parser;
}

/******************************************************************************/

void RelaxNGAllocatorAdapter::free(xmlRelaxNGPtr schema) {
  xmlRelaxNGFree(schema);
}

/******************************************************************************/

void RelaxNGAllocatorAdapter::freeParser(xmlRelaxNGParserCtxtPtr parser) {
  xmlRelaxNGFreeParserCtxt(parser);
}

/******************************************************************************/

void RelaxNGAllocatorAdapter::freeValidator(xmlRelaxNGValidCtxtPtr validator) {
  xmlRelaxNGFreeValidCtxt(validator);
}
