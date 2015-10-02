/**
 * Copyright - Benjamin Laugraud - 2015
 */
#include <libxml/parser.h>
#include <libxml/dict.h>

#include "libdataset/ThirdPartyLibManager.h"

using namespace BGS_Platform::libdataset;

/* ========================================================================== *
 * ThirdPartyLibManager                                                       *
 * ========================================================================== */

ThirdPartyLibManager::ThirdPartyLibManager() {
  xmlInitParser();
}

/******************************************************************************/

ThirdPartyLibManager::~ThirdPartyLibManager() {
  xmlCleanupParser();
  xmlDictCleanup();
}
