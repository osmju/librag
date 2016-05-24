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
#include "libdataset/xml/adapters/libxml2/SchematronAllocatorAdapter.h"
#include "libdataset/xml/adapters/libxml2/SchematronParseAdapter.h"
#include "libdataset/xml/adapters/libxml2/SchematronValidateAdapter.h"
#include "libdataset/xml/validators/SchematronValidator.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * SchematronValidator                                                        *
 * ========================================================================== */

SchematronValidator::SchematronValidator(const std::string& file) :
  Base(file),
  parser(SchematronAllocatorAdapter::newParser(file)),
  schema(SchematronParseAdapter::parse(parser)),
  validator(SchematronAllocatorAdapter::newValidator(schema)) {

  xmlSchematronSetValidStructuredErrors(validator, errorHandler, &errors);
}

/******************************************************************************/

SchematronValidator::~SchematronValidator() {
  SchematronAllocatorAdapter::freeValidator(validator);
  SchematronAllocatorAdapter::free(schema);
  SchematronAllocatorAdapter::freeParser(parser);
}

/******************************************************************************/

void SchematronValidator::validate(XMLDocument& document) {
  clearErrors();

  SchematronValidateAdapter::validate(
    validator,
    document
  );
}
