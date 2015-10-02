/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_EXCEPTIONS_LIBDATASET_XML_EXCEPTION_H_
#define _BGS_PLATFORM_LIBDATASET_EXCEPTIONS_LIBDATASET_XML_EXCEPTION_H_

#include <string>

#include "libdataset/exceptions/LibDatasetException.h"

#include "libexceptions/macros.h"

namespace BGS_Platform {
  namespace libdataset {
    class LibDatasetXMLException : public LibDatasetException {
      public:

        typedef LibDatasetException                                       Base;

      public:

        LibDatasetXMLException(
          BGS_PLATFORM_LIBEXCEPTIONS_CONS_PARAMS_H(LibDatasetXMLException)
        ) :
          BGS_PLATFORM_LIBEXCEPTIONS_CONS_BASE_CALL(LibDatasetException) {}

        virtual ~LibDatasetXMLException() throw() {}
    };
  }
}

#endif /* _BGS_PLATFORM_LIBDATASET_EXCEPTIONS_LIBDATASET_XML_EXCEPTION_H_ */
