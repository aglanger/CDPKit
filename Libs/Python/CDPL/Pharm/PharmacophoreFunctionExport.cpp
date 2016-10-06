/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * PharmacophoreFunctionExport.cpp 
 *
 * This file is part of the Chemical Data Processing Toolkit
 *
 * Copyright (C) 2003-2010 Thomas A. Seidel <thomas.seidel@univie.ac.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; see the file COPYING. If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#include <boost/python.hpp>

#include "CDPL/Pharm/PharmacophoreFunctions.hpp"
#include "CDPL/Pharm/Pharmacophore.hpp"
#include "CDPL/Chem/AtomContainer.hpp"

#include "FunctionExports.hpp"
#include "FunctionWrapper.hpp"


#define MAKE_PHARM_FUNC_WRAPPERS(TYPE, FUNC_SUFFIX)                 \
TYPE get##FUNC_SUFFIX##Wrapper(CDPL::Pharm::Pharmacophore& pharm)   \
{                                                                   \
	return get##FUNC_SUFFIX(pharm);                                 \
}                                                                   \
                                                                    \
bool has##FUNC_SUFFIX##Wrapper(CDPL::Pharm::Pharmacophore& pharm)   \
{                                                                   \
	return has##FUNC_SUFFIX(pharm);                                 \
}

#define EXPORT_PHARM_FUNCS_COPY_REF(FUNC_SUFFIX, ARG_NAME)                                                    \
python::def("get"#FUNC_SUFFIX, &get##FUNC_SUFFIX##Wrapper, python::arg("pharm"),                              \
            python::return_value_policy<python::copy_const_reference>());                                     \
python::def("has"#FUNC_SUFFIX, &has##FUNC_SUFFIX##Wrapper, python::arg("pharm"));                             \
python::def("clear"#FUNC_SUFFIX, &Pharm::clear##FUNC_SUFFIX, python::arg("pharm"));                           \
python::def("set"#FUNC_SUFFIX, &Pharm::set##FUNC_SUFFIX, (python::arg("pharm"), python::arg(#ARG_NAME))); 


namespace
{

	MAKE_PHARM_FUNC_WRAPPERS(const std::string&, Name)
	MAKE_FUNCTION_WRAPPER5(bool, checkExclusionVolumeClash, const CDPL::Pharm::Pharmacophore&, CDPL::Chem::AtomContainer&,
						   const CDPL::Chem::Atom3DCoordinatesFunction&, const CDPL::Math::Matrix4D&, bool);
}


void CDPLPythonPharm::exportPharmacophoreFunctions()
{
    using namespace boost;
    using namespace CDPL;
	
	python::def("getFeatureCount", static_cast<std::size_t (*)(const Pharm::Pharmacophore&)>(&Pharm::getFeatureCount), 
				python::arg("pharm"));
	python::def("getFeatureCount", static_cast<std::size_t (*)(const Pharm::Pharmacophore&, unsigned int)>(&Pharm::getFeatureCount), 
				(python::arg("pharm"), python::arg("type")));
	python::def("buildFeatureTypeHistogram", &Pharm::buildFeatureTypeHistogram, 
				(python::arg("pharm"), python::arg("hist")));
	python::def("buildInteractionPharmacophore", &Pharm::buildInteractionPharmacophore, 
				(python::arg("pharm"), python::arg("iactions")));
	python::def("checkExclusionVolumeClash", &checkExclusionVolumeClashWrapper5, 
				(python::arg("pharm"), python::arg("cntnr"), python::arg("coords_func"), python::arg("xform"), python::arg("vdw") = true));

	EXPORT_PHARM_FUNCS_COPY_REF(Name, name)
}
