/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * MolecularGraphMMFF94AromaticRingSetFunctions.cpp 
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


#include "StaticInit.hpp"

#include "CDPL/Forcefield/MolecularGraphFunctions.hpp"
#include "CDPL/Forcefield/MolecularGraphProperty.hpp"
#include "CDPL/Forcefield/MMFF94AromaticSSSRSubset.hpp"


using namespace CDPL; 


Chem::FragmentList::SharedPointer Forcefield::perceiveMMFF94AromaticRings(const Chem::MolecularGraph& molgraph)
{
	Chem::FragmentList::SharedPointer rings_ptr(new MMFF94AromaticSSSRSubset(molgraph));

	return rings_ptr;
}

Chem::FragmentList::SharedPointer Forcefield::perceiveMMFF94AromaticRings(Chem::MolecularGraph& molgraph, bool overwrite)
{
	if (!overwrite) {
		Base::Variant prev_rings = molgraph.getProperty(MolecularGraphProperty::MMFF94_AROMATIC_RINGS, false);
	
		if (!prev_rings.isEmpty())
			return prev_rings.getData<Chem::FragmentList::SharedPointer>();
	}

	Chem::FragmentList::SharedPointer rings_ptr(new MMFF94AromaticSSSRSubset(molgraph));

	molgraph.setProperty(MolecularGraphProperty::MMFF94_AROMATIC_RINGS, rings_ptr);

	return rings_ptr;
}