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
