/**
 * Copyright - Benjamin Laugraud - 2015
 */
#ifdef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_CHAR_ADAPTER_T_

inline const char* CharAdapter::xmlCharToChar(const xmlChar* _xmlChar) {
  return (_xmlChar != NULL) ? reinterpret_cast<const char*>(_xmlChar) : "";
}

/******************************************************************************/

inline std::string CharAdapter::xmlCharToString(const xmlChar* _xmlChar) {
  return std::string(xmlCharToChar(_xmlChar));
}

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_CHAR_ADAPTER_T_ */
