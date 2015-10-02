/**
 * Copyright - Benjamin Laugraud - 2015
 */
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
