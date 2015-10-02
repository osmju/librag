/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_RELAXNG_VALIDATOR_H_
#define _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_RELAXNG_VALIDATOR_H_

#include <string>

#include <libxml/relaxng.h>

#include "libdataset/xml/validators/Validator.h"

namespace BGS_Platform {
  namespace libdataset {
    class RelaxNGValidator : public Validator {
      protected:

        typedef Validator                                                 Base;

      protected:

        xmlRelaxNGParserCtxtPtr parser;
        xmlRelaxNGPtr schema;
        xmlRelaxNGValidCtxtPtr validator;

      public:

        RelaxNGValidator(const std::string& file);

        virtual ~RelaxNGValidator();

        virtual void validate(XMLDocument& document);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_RELAXNG_VALIDATOR_H_ */
