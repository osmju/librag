/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_VALIDATOR_H_
#define _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_VALIDATOR_H_

#include <string>
#include <vector>

#include "libdataset/xml/XMLDocument.h"
#include "libdataset/xml/XMLErrorMessage.h"

namespace BGS_Platform {
  namespace libdataset {
    class Validator {
      public:

        typedef std::vector<XMLErrorMessage*>                        ErrorsVec;

      protected:

        std::string file;
        ErrorsVec errors;

      protected:

        Validator(const std::string& file);

        virtual ~Validator();

      public:

        virtual void validate(XMLDocument& document) = 0;

        const std::string& getFile() const;

        const ErrorsVec& getErrors() const;

      protected:

        void clearErrors();

        static void errorHandler(void* ctx, xmlErrorPtr handler);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_VALIDATORS_VALIDATOR_H_ */
