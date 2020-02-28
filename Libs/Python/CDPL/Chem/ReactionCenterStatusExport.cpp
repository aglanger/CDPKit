/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * ReactionCenterStatusExport.cpp 
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

#include "CDPL/Chem/ReactionCenterStatus.hpp"

#include "NamespaceExports.hpp"


namespace 
{

	struct ReactionCenterStatus {};
}


void CDPLPythonChem::exportReactionCenterStates()
{
	using namespace boost;
	using namespace CDPL;

	python::class_<ReactionCenterStatus, boost::noncopyable>("ReactionCenterStatus", python::no_init)
		.def_readonly("NONE", &Chem::ReactionCenterStatus::NONE)
		.def_readonly("BOND_BROKEN", &Chem::ReactionCenterStatus::BOND_BROKEN)
		.def_readonly("BOND_MADE", &Chem::ReactionCenterStatus::BOND_MADE)
		.def_readonly("BOND_ORDER_CHANGE", &Chem::ReactionCenterStatus::BOND_ORDER_CHANGE)
		.def_readonly("EXACT_CHANGE", &Chem::ReactionCenterStatus::EXACT_CHANGE)
		.def_readonly("IS_CENTER", &Chem::ReactionCenterStatus::IS_CENTER)
		.def_readonly("NO_CENTER", &Chem::ReactionCenterStatus::NO_CENTER)
		.def_readonly("NO_CHANGE", &Chem::ReactionCenterStatus::NO_CHANGE)
		.def_readonly("STEREO_INVERSION", &Chem::ReactionCenterStatus::STEREO_INVERSION)
		.def_readonly("STEREO_RETENTION", &Chem::ReactionCenterStatus::STEREO_RETENTION);
}
