/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * FeatureGeneratorExport.cpp 
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

#include "CDPL/Pharm/FeatureGenerator.hpp"
#include "CDPL/Pharm/Pharmacophore.hpp"
#include "CDPL/Chem/MolecularGraph.hpp"
#include "CDPL/Chem/Atom.hpp"

#include "Base/CallableObjectAdapter.hpp"
#include "Base/ObjectIdentityCheckVisitor.hpp"

#include "ClassExports.hpp"


namespace
{

	struct FeatureGeneratorWrapper : CDPL::Pharm::FeatureGenerator, boost::python::wrapper<CDPL::Pharm::FeatureGenerator> 
	{

		void generate(const CDPL::Chem::MolecularGraph& molgraph, CDPL::Pharm::Pharmacophore& pharm) {	
			this->get_override("generate")(boost::ref(molgraph), boost::ref(pharm));
		}      
	};

    void set3DCoordsFunc(CDPL::Pharm::FeatureGenerator& gen, const boost::python::object& callable)
    {
		if (callable.ptr() == Py_None)
			gen.setAtom3DCoordinatesFunction(CDPL::Pharm::FeatureGenerator::Atom3DCoordinatesFunction());
		else
			gen.setAtom3DCoordinatesFunction(CDPLPythonBase::UnaryFunctionAdapter<const CDPL::Math::Vector3D&, CDPL::Chem::Atom>(callable)); 
    }
}


void CDPLPythonPharm::exportFeatureGenerator()
{
    using namespace boost;
    using namespace CDPL;

    python::class_<FeatureGeneratorWrapper, boost::noncopyable>("FeatureGenerator", python::no_init)
		.def(python::init<>(python::arg("self")))
		.def(CDPLPythonBase::ObjectIdentityCheckVisitor<Pharm::FeatureGenerator>())	
		.def("setAtom3DCoordinatesFunction", &set3DCoordsFunc, 
			 (python::arg("self"), python::arg("func")))
		.def("getAtom3DCoordinatesFunction", &Pharm::FeatureGenerator::getAtom3DCoordinatesFunction, 
			 python::arg("self"), python::return_internal_reference<>())
		.def("generate", python::pure_virtual(&Pharm::FeatureGenerator::generate),
			 (python::arg("self"), python::arg("molgraph"), python::arg("pharm")));
}
