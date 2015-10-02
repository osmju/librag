/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifndef _BGS_PLATFORM_LIBEXCEPTIONS_MACROS_H_
#define _BGS_PLATFORM_LIBEXCEPTIONS_MACROS_H_

#define BGS_PLATFORM_LIBEXCEPTIONS_DEFAULT_EXCEPTION_STR(X)                    \
  "A " #X " occurred"

#define BGS_PLATFORM_LIBEXCEPTIONS_CONS_PARAMS_H(X)                            \
  const size_t& line,                                                          \
  const std::string& file,                                                     \
  const std::string& message =                                                 \
  BGS_PLATFORM_LIBEXCEPTIONS_DEFAULT_EXCEPTION_STR(X)

#define BGS_PLATFORM_LIBEXCEPTIONS_CONS_BASE_CALL(X)                           \
  X(                                                                           \
    line,                                                                      \
    file,                                                                      \
    message                                                                    \
  )

#define BGS_PLATFORM_LIBEXCEPTIONS_CONS_DEFAULT_BASE_CALL                      \
  BGS_PLATFORM_LIBEXCEPTIONS_CONS_BASE_CALL(BGSPlatformException)

#endif /* _BGS_PLATFORM_LIBEXCEPTIONS_MACROS_H_ */
