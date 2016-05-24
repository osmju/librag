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

#include "libdataset/exceptions/exceptions.h"
#include "libdataset/xml/adapters/libxml2/SchematronParseAdapter.h"

using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * SchematronParseAdapter                                                     *
 * ========================================================================== */

SchematronParseAdapter::SchematronParseAdapter() {}

/******************************************************************************/

SchematronParseAdapter::~SchematronParseAdapter() {}

/******************************************************************************/

xmlSchematronPtr SchematronParseAdapter::parse(
  xmlSchematronParserCtxtPtr parser
) {
  xmlSchematronPtr schema;

  if ((schema = xmlSchematronParse(parser)) == NULL) {
    throw IncorrectSchematronGrammarException(
      __LINE__,
      __FILE__,
      "The Schematron rules are incorrect"
    );
  }

  return schema;
}
