/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_RELAXNG_VALIDATE_H_
#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_RELAXNG_VALIDATE_H_

#include <libxml/relaxng.h>

#include "libdataset/xml/XMLDocument.h"

namespace BGS_Platform {
  namespace libdataset {
    class RelaxNGValidateAdapter {
      private:

        RelaxNGValidateAdapter();

        virtual ~RelaxNGValidateAdapter();

      public:

        static void validate(
          xmlRelaxNGValidCtxtPtr validator,
          xmlDocPtr document
        );

        static void validate(
          xmlRelaxNGValidCtxtPtr validator,
          XMLDocument& document
        );
    };
  } /* libdataset */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_RELAXNG_VALIDATE_H_ */
