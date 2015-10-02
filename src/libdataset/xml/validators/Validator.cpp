/**
 * Copyright - Benjamin Laugraud - 2015
 */
#include "libdataset/xml/validators/Validator.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * Validator                                                                  *
 * ========================================================================== */

Validator::Validator(const string& file) :
  file(file) {

  if (file.empty()) {
    throw; // TODO throw
  }
}

/******************************************************************************/

Validator::~Validator() {
  clearErrors();
}

/******************************************************************************/

const string& Validator::getFile() const {
  return file;
}

/******************************************************************************/

const Validator::ErrorsVec& Validator::getErrors() const {
  return errors;
}

/******************************************************************************/

void Validator::clearErrors() {
  for (
    ErrorsVec::iterator it = errors.begin(), end = errors.end();
    it != end;
    ++it
  )
    delete *it;

  errors.clear();
}

/******************************************************************************/

void Validator::errorHandler(void* ctx, xmlErrorPtr handler) {
  ErrorsVec* errors = static_cast<ErrorsVec*>(ctx);

  errors->push_back(
    new XMLErrorMessage(
      handler->line,
      handler->file,
      handler->message,
      static_cast<xmlNodePtr>(handler->node)
    )
  );
}
