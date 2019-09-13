/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * DGStructureGeneratorExport.cpp 
 *
 * This file is part of the Utilical Data Processing Toolkit
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

#include "CDPL/ConfGen/DGStructureGenerator.hpp"
#include "CDPL/Chem/MolecularGraph.hpp"
#include "CDPL/ForceField/MMFF94InteractionData.hpp"

#include "Base/ObjectIdentityCheckVisitor.hpp"
#include "Base/CopyAssOp.hpp"

#include "ClassExports.hpp"


void CDPLPythonConfGen::exportDGStructureGenerator()
{
    using namespace boost;
    using namespace CDPL;

	python::class_<ConfGen::DGStructureGenerator>("DGStructureGenerator", python::no_init)
		.def(python::init<>(python::arg("self")))
		.def(python::init<const ConfGen::DGStructureGenerator&>((python::arg("self"), python::arg("gen"))))
		.def(CDPLPythonBase::ObjectIdentityCheckVisitor<ConfGen::DGStructureGenerator>())
		.def("assign", CDPLPythonBase::copyAssOp(&ConfGen::DGStructureGenerator::operator=), 
			 (python::arg("self"), python::arg("gen")), python::return_self<>())
		.def("setBoxSize", &ConfGen::DGStructureGenerator::setBoxSize, 
			 (python::arg("self"), python::arg("size")))
		.def("getBoxSize", &ConfGen::DGStructureGenerator::getBoxSize, python::arg("self"))
		.def("excludeHydrogens", &ConfGen::DGStructureGenerator::excludeHydrogens, 
			 (python::arg("self"), python::arg("exclude")))
		.def("hydrogensExcluded", &ConfGen::DGStructureGenerator::hydrogensExcluded, python::arg("self"))
		.def("enablePlanarityConstraints", &ConfGen::DGStructureGenerator::enablePlanarityConstraints, 
			 (python::arg("self"), python::arg("exclude")))
		.def("planarityConstraintsEnabled", &ConfGen::DGStructureGenerator::planarityConstraintsEnabled, python::arg("self"))
		.def("regardAtomConfiguration", &ConfGen::DGStructureGenerator::regardAtomConfiguration, 
			 (python::arg("self"), python::arg("regard")))
		.def("atomConfigurationRegarded", &ConfGen::DGStructureGenerator::atomConfigurationRegarded, python::arg("self"))
		.def("regardBondConfiguration", &ConfGen::DGStructureGenerator::regardBondConfiguration, 
			 (python::arg("self"), python::arg("regard")))
		.def("bondConfigurationRegarded", &ConfGen::DGStructureGenerator::bondConfigurationRegarded, python::arg("self"))
		.def("getExcludedHydrogenMask", &ConfGen::DGStructureGenerator::getExcludedHydrogenMask, python::arg("self"), 
			 python::return_internal_reference<>())
		.def("setup", static_cast<void (ConfGen::DGStructureGenerator::*)(const Chem::MolecularGraph&)>
			 (&ConfGen::DGStructureGenerator::setup), (python::arg("self"), python::arg("molgraph")))
		.def("setup", static_cast<void (ConfGen::DGStructureGenerator::*)(const Chem::MolecularGraph&, const ForceField::MMFF94InteractionData&)>
			 (&ConfGen::DGStructureGenerator::setup), 
			 (python::arg("self"), python::arg("molgraph"), python::arg("ia_data")))
		.def("generate", &ConfGen::DGStructureGenerator::generate, (python::arg("self"), python::arg("coords")))
		.def("checkAtomConfigurations", &ConfGen::DGStructureGenerator::checkAtomConfigurations,
			 (python::arg("self"), python::arg("coords")))
		.def("checkBondConfigurations", &ConfGen::DGStructureGenerator::checkBondConfigurations,
			 (python::arg("self"), python::arg("coords")))
		.add_property("exclHydrogenMask", python::make_function(&ConfGen::DGStructureGenerator::getExcludedHydrogenMask, 
																python::return_internal_reference<>())) 
		.add_property("boxSize", &ConfGen::DGStructureGenerator::getBoxSize, 
					  &ConfGen::DGStructureGenerator::setBoxSize)
		.add_property("planarityConstraints", &ConfGen::DGStructureGenerator::planarityConstraintsEnabled, 
					  &ConfGen::DGStructureGenerator::enablePlanarityConstraints)
		.add_property("exclHydrogens", &ConfGen::DGStructureGenerator::hydrogensExcluded, 
					  &ConfGen::DGStructureGenerator::excludeHydrogens)
		.add_property("regardAtomConfig", &ConfGen::DGStructureGenerator::atomConfigurationRegarded, 
					  &ConfGen::DGStructureGenerator::regardAtomConfiguration)
		.add_property("regardBondConfig", &ConfGen::DGStructureGenerator::bondConfigurationRegarded, 
					  &ConfGen::DGStructureGenerator::regardBondConfiguration);
}
