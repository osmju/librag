/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_CHAR_ADAPTER_H_
#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_CHAR_ADAPTER_H_

#include <string>

#include <libxml/xmlstring.h>

namespace BGS_Platform {
  namespace libdataset {
    class CharAdapter {
      public:

        static const char* xmlCharToChar(const xmlChar* _xmlChar);

        static std::string xmlCharToString(const xmlChar* _xmlChar);
    };

#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_CHAR_ADAPTER_T_
#include "libdataset/xml/adapters/libxml2/CharAdapter.t"
#undef  _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_CHAR_ADAPTER_T_
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_CHAR_ADAPTER_H_ */
