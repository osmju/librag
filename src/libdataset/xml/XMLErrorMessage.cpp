/**
 * Copyright - Benjamin Laugraud - 2015
 */
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
