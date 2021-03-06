/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * StructureView2DExport.cpp 
 *
 * This file is part of the Chemical Data Processing Toolkit
 *
 * Copyright (C) 2003-2020 Thomas A. Seidel <thomas.seidel@univie.ac.at>
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

#include "CDPL/Vis/StructureView2D.hpp"
#include "CDPL/Vis/FontMetrics.hpp"
#include "CDPL/Chem/Fragment.hpp"
#include "CDPL/Chem/Atom.hpp"

#include "ClassExports.hpp"


namespace
{

	void addGraphicsPrimitive(CDPL::Vis::StructureView2D& view, CDPL::Chem::Atom& anchor_atom, 
							  const CDPL::Vis::GraphicsPrimitive2D& prim, 
							  unsigned int alignment, bool front)
	{
		view.addGraphicsPrimitive(anchor_atom, prim, alignment, front);
	}
}


void CDPLPythonVis::exportStructureView2D()
{
	using namespace boost;
	using namespace CDPL;

	python::class_<Vis::StructureView2D, 
		python::bases<Vis::View2D>, boost::noncopyable>("StructureView2D", python::no_init)
		.def(python::init<>(python::arg("self")))
		.def(python::init<const Chem::MolecularGraph*>((python::arg("self"), python::arg("molgraph")))[python::with_custodian_and_ward<1, 2>()])
		.def("setStructure", &Vis::StructureView2D::setStructure, (python::arg("self"), python::arg("molgraph")),
			 python::with_custodian_and_ward<1, 2>())
		.def("getStructure", &Vis::StructureView2D::getStructure, python::arg("self"),
			 python::return_internal_reference<1>())
		.def("getFontMetrics", &Vis::StructureView2D::getFontMetrics, python::arg("self"),
			 python::return_internal_reference<1>())
		.def("addGraphicsPrimitive", static_cast<void (Vis::StructureView2D::*)(const Math::Vector2D&, const Vis::GraphicsPrimitive2D&, unsigned int, bool)>
			 (&Vis::StructureView2D::addGraphicsPrimitive), 
			 (python::arg("self"), python::arg("anchor_pos"), python::arg("prim"), python::arg("alignment"), python::arg("front")))
		.def("addGraphicsPrimitive", &addGraphicsPrimitive, 
			 (python::arg("self"), python::arg("anchor_atom"), python::arg("prim"), python::arg("alignment"), python::arg("front")))
		.def("addGraphicsPrimitive", static_cast<void (Vis::StructureView2D::*)(const Chem::Fragment&, const Vis::GraphicsPrimitive2D&, unsigned int, bool)>
			 (&Vis::StructureView2D::addGraphicsPrimitive), 
			 (python::arg("self"), python::arg("anchor_atoms"), python::arg("prim"), python::arg("alignment"), python::arg("front")))
		.def("clearGraphicsPrimitives", &Vis::StructureView2D::clearGraphicsPrimitives, python::arg("self"))
		.add_property("structure", python::make_function(&Vis::StructureView2D::getStructure,
														 python::return_internal_reference<1>()),
					  python::make_function(&Vis::StructureView2D::setStructure, 
											python::with_custodian_and_ward<1, 2>()))
		.add_property("fontMetrics", python::make_function(&Vis::StructureView2D::getFontMetrics,
														   python::return_internal_reference<1>()),
					  python::make_function(&Vis::StructureView2D::setFontMetrics,	 
											python::with_custodian_and_ward<1, 2>()));
}
