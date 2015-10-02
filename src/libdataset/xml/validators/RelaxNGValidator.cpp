/**
 * Copyright - Benjamin Laugraud - 2015
 */
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
