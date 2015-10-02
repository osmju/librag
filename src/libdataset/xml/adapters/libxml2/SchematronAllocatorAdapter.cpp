/**
 * Copyright - Benjamin Laugraud - 2015
 */
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
