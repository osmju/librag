/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _CREATIS_EXCEPTIONS_CREATIS_EXCEPTION_H_
#define _CREATIS_EXCEPTIONS_CREATIS_EXCEPTION_H_

#include <cstddef>
#include <exception>
#include <sstream>
#include <string>

#include "libexceptions/ExceptionsUtils.h"
#include "libexceptions/macros.h"

namespace BGS_Platform {
  namespace libexceptions {
    class BGSPlatformException : public std::exception {
      typedef std::exception                                              Base;

      protected:

        size_t line;
        std::string file;
        std::string message;
        std::string _what;

      public:

        BGSPlatformException(
          BGS_PLATFORM_LIBEXCEPTIONS_CONS_PARAMS_H(BGSPlatformException)
        ) :
          Base(),
          line(line),
          file(file),
          message(message),
          _what(ExceptionsUtils::formatWhat(line, file, message)) {}

        virtual ~BGSPlatformException() throw () {}

        virtual const char* what() const throw() {
          return _what.c_str();
        }
    };
  }
}

#endif /* _CREATIS_EXCEPTIONS_CREATIS_EXCEPTION_H_ */
