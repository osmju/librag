/**
 * Copyright - Benjamin Laugraud - 2015
 */
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
