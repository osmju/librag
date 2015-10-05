//! \file types.h
//! \brief Replace by short description
//!
//! \author Julien Osmalskyj
//! \date   19 juin 2015
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
