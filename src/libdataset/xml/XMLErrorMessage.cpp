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

#include "libdataset/xml/XMLErrorMessage.h"

using namespace std;
using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * XMLErrorMessage                                                            *
 * ========================================================================== */

int XMLErrorMessage::getLine() const {
  return line;
}

/******************************************************************************/

const string& XMLErrorMessage::getFile() const {
  return file;
}

/******************************************************************************/

const string& XMLErrorMessage::getMessage() const {
  return message;
}

/******************************************************************************/

xmlNodePtr XMLErrorMessage::getNode() const {
  return node;
}

/******************************************************************************/

string XMLErrorMessage::getFormattedMessage() const {
  stringstream ss;
  ss << file << ":" << line << " - ";

  if (node != NULL)
    ss << "From element " << node->name << ": ";

  ss << message;
  return ss.str();
}
