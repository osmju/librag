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
#ifndef _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_ALLOC_H_
#define _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_ALLOC_H_

#include <string>

#include <libxml/schematron.h>

#include "libdataset/xml/XMLDocument.h"

namespace BGS_Platform {
  namespace libdataset {
    class SchematronAllocatorAdapter {
      private:

        SchematronAllocatorAdapter();

        virtual ~SchematronAllocatorAdapter();

      public:

        static xmlSchematronParserCtxtPtr newParser(std::string file);

        static xmlSchematronValidCtxtPtr newValidator(xmlSchematronPtr schema);

      protected:

        static xmlSchematronParserCtxtPtr newParser(const char* file);

      public:

        static void free(xmlSchematronPtr schema);

        static void freeParser(xmlSchematronParserCtxtPtr parser);

        static void freeValidator(xmlSchematronValidCtxtPtr validator);
    };
  } /* _NS_libdataset_ */
} /* _NS_BGS_Platform _ */

#endif /* _BGS_PLATFORM_LIBDATASET_XML_ADAPTERS_LIBXML2_SCHEMATRON_ALLOC_H_ */
