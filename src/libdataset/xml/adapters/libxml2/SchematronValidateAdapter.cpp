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
#include "libdataset/xml/adapters/libxml2/SchematronValidateAdapter.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * SchematronValidateAdapter                                                  *
 * ========================================================================== */

SchematronValidateAdapter::SchematronValidateAdapter() {}

/******************************************************************************/

SchematronValidateAdapter::~SchematronValidateAdapter() {}

/******************************************************************************/

void SchematronValidateAdapter::validate(
  xmlSchematronValidCtxtPtr validator,
  xmlDocPtr document
) {
  int validationCode;

  if (
    (validationCode =
      xmlSchematronValidateDoc(
        validator,
        document
      )
    ) < 0
  ) {
    /* TODO To catch by higher level adapter. */
    throw LibXML2InternalErrorException(
      __LINE__,
      __FILE__
    );
  }

  if (validationCode > 0) {
    /* TODO To catch by higher level adapter. */
    throw InvalidXMLDocumentException(
      __LINE__,
      __FILE__
    );
  }
}

/******************************************************************************/
#include <iostream>
void SchematronValidateAdapter::validate(
  xmlSchematronValidCtxtPtr validator,
  XMLDocument& document
) {
  try {
    validate(
      validator,
      document.getDocPtr()
    );
  }
  catch (LibXML2InternalErrorException& e) {
    stringstream ss;
    ss << "An internal error of the libxml2 Schematron parser prevent to ";
    ss << "validate the " << document.getFile() << " file";

    throw LibXML2InternalErrorException(
      __LINE__,
      __FILE__,
      ss.str()
    );
  }
  catch (InvalidXMLDocumentException& e) {
    stringstream ss;
    ss << "The " << document.getFile() << " file is not valid according to ";
    ss << "the given Schematron grammar";

    throw InvalidXMLDocumentException(
      __LINE__,
      __FILE__,
      ss.str()
    );
  }
}
