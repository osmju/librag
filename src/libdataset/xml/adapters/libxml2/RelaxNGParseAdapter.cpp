/**
 * Copyright - Benjamin Laugraud - 2015
 */
#include <cstddef>

#include "libdataset/exceptions/exceptions.h"
#include "libdataset/xml/adapters/libxml2/RelaxNGParseAdapter.h"

using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * RelaxNGParseAdapter                                                        *
 * ========================================================================== */

RelaxNGParseAdapter::RelaxNGParseAdapter() {}

/******************************************************************************/

RelaxNGParseAdapter::~RelaxNGParseAdapter() {}

/******************************************************************************/

xmlRelaxNGPtr RelaxNGParseAdapter::parse(xmlRelaxNGParserCtxtPtr parser) {
  xmlRelaxNGPtr schema;

  if ((schema = xmlRelaxNGParse(parser)) == NULL) {
    throw IncorrectRelaxNGGrammarException(
      __LINE__,
      __FILE__,
      "The Relax NG grammar is incorrect"
    );
  }

  return schema;
}
