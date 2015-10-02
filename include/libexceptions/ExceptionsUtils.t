/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifdef _BGS_PLATFORM_LIBEXCEPTIONS_EXCEPTIONS_UTILS_T_

/* ========================================================================== *
 * ExceptionsUtils                                                            *
 * ========================================================================== */

inline std::string ExceptionsUtils::formatWhat(
  const size_t& line,
  const std::string& file,
  const std::string& message
) throw() {
  std::stringstream ss;
  ss << file << ":" << line << " - " << message;

  return ss.str();
}

#endif /* _BGS_PLATFORM_LIBEXCEPTIONS_EXCEPTIONS_UTILS_T_ */
