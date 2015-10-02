/**
 * Copyright - Benjamin Laugraud - 2015
 */
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
