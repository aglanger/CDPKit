/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * MolecularGraphAromaticSubstructureFunctions.cpp 
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


#include "StaticInit.hpp"

#include "CDPL/Chem/MolecularGraphFunctions.hpp"
#include "CDPL/Chem/Atom.hpp"
#include "CDPL/Chem/Bond.hpp"
#include "CDPL/Chem/MolecularGraphProperty.hpp"
#include "CDPL/Chem/AromaticSubstructure.hpp"


using namespace CDPL; 


Chem::Fragment::SharedPointer Chem::perceiveAromaticSubstructure(const MolecularGraph& molgraph)
{
	Fragment::SharedPointer substruct_ptr(new AromaticSubstructure(molgraph));

	return substruct_ptr;
}

Chem::Fragment::SharedPointer Chem::perceiveAromaticSubstructure(MolecularGraph& molgraph, bool overwrite)
{
	if (!overwrite) {
		Base::Variant prev_substruct = molgraph.getProperty(MolecularGraphProperty::AROMATIC_SUBSTRUCTURE, false);
	
		if (!prev_substruct.isEmpty())
			return prev_substruct.getData<Fragment::SharedPointer>();
	}

	Fragment::SharedPointer substruct_ptr(new AromaticSubstructure(molgraph));

	molgraph.setProperty(MolecularGraphProperty::AROMATIC_SUBSTRUCTURE, substruct_ptr);

	return substruct_ptr;
}
