/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * MMFF94TorsionInteractionDataExport.cpp 
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

#include "CDPL/ForceField/MMFF94TorsionInteractionData.hpp"

#include "Util/ArrayVisitor.hpp"

#include "ClassExports.hpp"


void CDPLPythonForceField::exportMMFF94TorsionInteractionData()
{
    using namespace boost;
    using namespace CDPL;

    python::class_<ForceField::MMFF94TorsionInteractionData, ForceField::MMFF94TorsionInteractionData::SharedPointer>("MMFF94TorsionInteractionData", python::no_init)
		.def(python::init<>(python::arg("self")))
		.def(python::init<const ForceField::MMFF94TorsionInteractionData&>((python::arg("self"), python::arg("ia_data"))))
		.def(CDPLPythonUtil::ArrayVisitor<ForceField::MMFF94TorsionInteractionData, 
			 python::return_internal_reference<>, python::default_call_policies, python::default_call_policies, 
			 python::default_call_policies>());
}
