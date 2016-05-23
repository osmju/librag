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
#ifndef _BGS_PLATFORM_LIBDATASET_EXCEPTIONS_EXCEPTIONS_H_
#define _BGS_PLATFORM_LIBDATASET_EXCEPTIONS_EXCEPTIONS_H_

#include "libexceptions/macros.h"

#include "libdataset/exceptions/LibDatasetException.h"

#define BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(X)                               \
  class X##Exception : public LibDatasetException {                            \
    public:                                                                    \
                                                                               \
      X##Exception(                                                            \
        BGS_PLATFORM_LIBEXCEPTIONS_CONS_PARAMS_H(X##Exception)                 \
      ) :                                                                      \
        BGS_PLATFORM_LIBEXCEPTIONS_CONS_BASE_CALL(LibDatasetException) {}      \
                                                                               \
      virtual ~X##Exception() throw() {}                                       \
  };

namespace BGS_Platform {
  namespace libdataset {
    /* ====================================================================== *
     * CannotAllocateParserCtxException                                       *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(CannotAllocateParserCtx)

    /* ====================================================================== *
     * CannotInstantiateRelaxNGValidatorException                             *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(CannotInstantiateRelaxNGValidator)

    /* ====================================================================== *
     * CannotInstantiateSchematronValidatorException                          *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(CannotInstantiateSchematronValidator)

    /* ====================================================================== *
     * CannotReadRelaxNGGrammarException                                      *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(CannotReadRelaxNGGrammar)

    /* ====================================================================== *
     * CannotReadSchematronRulesException                                     *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(CannotReadSchematronRules)

    /* ====================================================================== *
     * IncorrectRelaxNGGrammarException                                       *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(IncorrectRelaxNGGrammar)

    /* ====================================================================== *
     * IncorrectSchematronGrammarException                                    *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(IncorrectSchematronGrammar)

    /* ====================================================================== *
     * InvalidXMLDocumentException                                            *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(InvalidXMLDocument)

    /* ====================================================================== *
     * LibXML2InternalErrorException                                          *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(LibXML2InternalError)

    /* ====================================================================== *
     * NullSentinelAttributeException                                         *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(NullSentinelAttribute)

    /* ====================================================================== *
     * NullSentinelNodeException                                              *
     * ====================================================================== */

    BGS_PLATFORM_LIBDATASET_NEW_EXCEPTION(NullSentinelNode)
  }
}

#endif /* _BGS_PLATFORM_LIBDATASET_EXCEPTIONS_EXCEPTIONS_H_ */
