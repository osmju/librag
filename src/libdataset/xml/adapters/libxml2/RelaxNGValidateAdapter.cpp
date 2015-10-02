/**
 * Copyright - Benjamin Laugraud - 2015
 */
#include <cstddef>
#include <sstream>

#include "libdataset/exceptions/exceptions.h"
#include "libdataset/xml/adapters/libxml2/RelaxNGValidateAdapter.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * RelaxNGValidateAdapter                                                     *
 * ========================================================================== */

RelaxNGValidateAdapter::RelaxNGValidateAdapter() {}

/******************************************************************************/

RelaxNGValidateAdapter::~RelaxNGValidateAdapter() {}

/******************************************************************************/

void RelaxNGValidateAdapter::validate(
  xmlRelaxNGValidCtxtPtr validator,
  xmlDocPtr document
) {
  int validationCode;

  if (
    (validationCode =
      xmlRelaxNGValidateDoc(
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
void RelaxNGValidateAdapter::validate(
  xmlRelaxNGValidCtxtPtr validator,
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
    ss << "An internal error of the libxml2 Relax NG parser prevent to ";
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
    ss << "the given Relax NG grammar";

    throw InvalidXMLDocumentException(
      __LINE__,
      __FILE__,
      ss.str()
    );
  }
}
