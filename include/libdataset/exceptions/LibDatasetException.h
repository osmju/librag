/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBDATASET_EXCEPTIONS_LIBDATASET_EXCEPTION_H_
#define _BGS_PLATFORM_LIBDATASET_EXCEPTIONS_LIBDATASET_EXCEPTION_H_

#include <string>

#include "libexceptions/BGSPlatformException.h"
#include "libexceptions/macros.h"

namespace BGS_Platform {
  namespace libdataset {
    class LibDatasetException : public libexceptions::BGSPlatformException {
      public:

        typedef libexceptions::BGSPlatformException                       Base;

      public:

        LibDatasetException(
          BGS_PLATFORM_LIBEXCEPTIONS_CONS_PARAMS_H(LibDatasetException)
        ) :
          BGS_PLATFORM_LIBEXCEPTIONS_CONS_DEFAULT_BASE_CALL {}

        virtual ~LibDatasetException() throw() {}
    };
  }
}

#endif /* _BGS_PLATFORM_LIBDATASET_EXCEPTIONS_LIBDATASET_EXCEPTION_H_ */
