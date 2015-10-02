/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_VALIDATE_H_
#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_VALIDATE_H_

#include <libxml/schematron.h>

#include "libdataset/xml/XMLDocument.h"

namespace BGS_Platform {
  namespace libdataset {
    class SchematronValidateAdapter {
      private:

        SchematronValidateAdapter();

        virtual ~SchematronValidateAdapter();

      public:

        static void validate(
          xmlSchematronValidCtxtPtr validator,
          xmlDocPtr document
        );

        static void validate(
          xmlSchematronValidCtxtPtr validator,
          XMLDocument& document
        );
    };
  } /* libdataset */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_VALIDATE_H_ */
