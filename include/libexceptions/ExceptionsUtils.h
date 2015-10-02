/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBEXCEPTIONS_EXCEPTIONS_UTILS_H_
#define _BGS_PLATFORM_LIBEXCEPTIONS_EXCEPTIONS_UTILS_H_

#include <cstddef>
#include <sstream>
#include <string>

namespace BGS_Platform {
  namespace libexceptions {
    class ExceptionsUtils {
      public:

        static std::string formatWhat(
          const size_t& line,
          const std::string& file,
          const std::string& message
        ) throw();
    };

#define _BGS_PLATFORM_LIBEXCEPTIONS_EXCEPTIONS_UTILS_T_
#include "libexceptions/ExceptionsUtils.t"
#undef  _BGS_PLATFORM_LIBEXCEPTIONS_EXCEPTIONS_UTILS_T_
  }
}

#endif /* _BGS_PLATFORM_LIBEXCEPTIONS_EXCEPTIONS_UTILS_H_ */
