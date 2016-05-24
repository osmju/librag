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
#include "libdataset/xml/adapters/libxml2/RelaxNGAllocatorAdapter.h"
#include "libdataset/xml/adapters/libxml2/RelaxNGParseAdapter.h"
#include "libdataset/xml/adapters/libxml2/RelaxNGValidateAdapter.h"
#include "libdataset/xml/validators/RelaxNGValidator.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * RelaxNGValidator                                                           *
 * ========================================================================== */

RelaxNGValidator::RelaxNGValidator(const std::string& file) :
  Base(file),
  parser(RelaxNGAllocatorAdapter::newParser(file)),
  schema(RelaxNGParseAdapter::parse(parser)),
  validator(RelaxNGAllocatorAdapter::newValidator(schema)) {

  xmlRelaxNGSetValidStructuredErrors(validator, errorHandler, &errors);
}

/******************************************************************************/

RelaxNGValidator::~RelaxNGValidator() {
  RelaxNGAllocatorAdapter::freeValidator(validator);
  RelaxNGAllocatorAdapter::free(schema);
  RelaxNGAllocatorAdapter::freeParser(parser);
}

/******************************************************************************/

void RelaxNGValidator::validate(XMLDocument& document) {
  RelaxNGValidateAdapter::validate(
    validator,
    document
  );
}
