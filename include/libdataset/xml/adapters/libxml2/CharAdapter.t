// Copyright (C) 2016   Benjamin Laugraud
//
// This file is part of LibDataset.
//
// LibDataset is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LibDataset is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with LibDataset.  If not, see http://www.gnu.org/licenses.
#ifdef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_CHAR_ADAPTER_T_

inline const char* CharAdapter::xmlCharToChar(const xmlChar* _xmlChar) {
  return (_xmlChar != NULL) ? reinterpret_cast<const char*>(_xmlChar) : "";
}

/******************************************************************************/

inline std::string CharAdapter::xmlCharToString(const xmlChar* _xmlChar) {
  return std::string(xmlCharToChar(_xmlChar));
}

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_CHAR_ADAPTER_T_ */
