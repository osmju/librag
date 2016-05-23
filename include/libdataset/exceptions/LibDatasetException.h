// Copyright (C) 2016   Benjamin Laugraud
//
// This file is part of LibDataset.
//
// LibDataset is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LibDataset is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with LibDataset.  If not, see http://www.gnu.org/licenses.

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
