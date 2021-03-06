/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * ReactionSubstructSearchInitializationFunctions.cpp 
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

#include <algorithm>

#include <boost/bind.hpp>

#include "CDPL/Chem/ReactionFunctions.hpp"
#include "CDPL/Chem/Reaction.hpp"
#include "CDPL/Chem/MolecularGraphFunctions.hpp"


using namespace CDPL; 


void Chem::initSubstructureSearchQuery(Reaction& rxn, bool overwrite)
{
	perceiveComponentGroups(rxn, overwrite);
	perceiveAtomMapping(rxn, overwrite);

	std::for_each(rxn.getComponentsBegin(), rxn.getComponentsEnd(),
				  boost::bind(static_cast<void (*)(MolecularGraph&, bool)>(&initSubstructureSearchQuery),
							  _1, overwrite));

	buildMatchExpressions(rxn ,overwrite);
}

void Chem::initSubstructureSearchTarget(Reaction& rxn, bool overwrite)
{
	std::for_each(rxn.getComponentsBegin(), rxn.getComponentsEnd(),
				  boost::bind(static_cast<void (*)(MolecularGraph&, bool)>(&initSubstructureSearchTarget),
							  _1, overwrite));
}
