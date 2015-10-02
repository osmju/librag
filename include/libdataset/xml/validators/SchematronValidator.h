/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_SCHEMATRON_VALIDATOR_H_
#define _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_SCHEMATRON_VALIDATOR_H_

#include <string>

#include <libxml/schematron.h>

#include "libdataset/xml/validators/Validator.h"

namespace BGS_Platform {
  namespace libdataset {
    class SchematronValidator : public Validator {
      protected:

        typedef Validator                                                 Base;

      protected:

        xmlSchematronParserCtxtPtr parser;
        xmlSchematronPtr schema;
        xmlSchematronValidCtxtPtr validator;

      public:

        SchematronValidator(const std::string& file);

        virtual ~SchematronValidator();

        virtual void validate(XMLDocument& document);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_SCHEMATRON_VALIDATOR_H_ */
