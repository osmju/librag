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
#ifndef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_PARSE_H_
#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_PARSE_H_

#include <libxml/schematron.h>

namespace BGS_Platform {
  namespace libdataset {
    class SchematronParseAdapter {
      private:

        SchematronParseAdapter();

        virtual ~SchematronParseAdapter();

      public:

        static xmlSchematronPtr parse(xmlSchematronParserCtxtPtr parser);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform_ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_PARSE_H_ */
