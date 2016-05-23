// Copyright (C) 2016   Julien Osmalskyj
//
// This file is part of LibRAG.
//
// LibRAG is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LibRAG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with LibRAG.  If not, see http://www.gnu.org/licenses.

#ifndef TYPES_H_
#define TYPES_H_

#include <memory>
#include <vector>
#include <string>

namespace rag {

	typedef std::vector<int>										ivect;
	typedef std::vector<float>  								fvect;
	typedef std::vector<double> 								dvect;
	typedef std::vector<std::string>						svect;
	typedef std::vector<fvect>  								fvect2d;

	typedef std::shared_ptr<ivect> 						ivectptr;
	typedef std::shared_ptr<fvect> 						fvectptr;
	typedef std::shared_ptr<dvect> 						dvectptr;
	typedef std::shared_ptr<svect> 						svectptr;

} /* namespace rag */

#endif /* TYPES_H_ */
