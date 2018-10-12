/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * UtilityFunctions.cpp 
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

#include "CDPL/ConfGen/UtilityFunctions.hpp"
#include "CDPL/ConfGen/FragmentType.hpp"
#include "CDPL/Chem/Atom.hpp"
#include "CDPL/Chem/Bond.hpp"
#include "CDPL/Chem/MolecularGraph.hpp"
#include "CDPL/Chem/BondFunctions.hpp"
#include "CDPL/Chem/AtomFunctions.hpp"
#include "CDPL/Chem/AtomType.hpp"


using namespace CDPL; 


namespace
{

    bool isSplitHeteroAtom(unsigned int type)
    {
		using namespace Chem;

		switch (type) {

			case AtomType::N:
			case AtomType::O:
			case AtomType::S:
			case AtomType::Se:
			case AtomType::P:
				return true;

			default: 
				break;
		}

		return false;
    }

    bool hasOnlyCarbonOrHydrogenNeighbors(const Chem::Atom& atom, const Chem::MolecularGraph& molgraph, const Chem::Bond& x_bond)
    {
		using namespace Chem;

		Atom::ConstBondIterator b_it = atom.getBondsBegin();

		for (Atom::ConstAtomIterator a_it = atom.getAtomsBegin(), a_end = atom.getAtomsEnd(); a_it != a_end; ++a_it, ++b_it) {
			const Bond& nbr_bond = *b_it;

			if (&nbr_bond == &x_bond)
				continue;

			if (!molgraph.containsBond(nbr_bond))
				continue;

			const Atom& nbr_atom = *a_it;

			if (!molgraph.containsAtom(nbr_atom))
				continue;
 
			switch (getType(nbr_atom)) {

				case AtomType::H:
				case AtomType::C:
					continue;

				default:
					return false;
			}
		}

		return true;
    }
}


bool ConfGen::isFragmentLinkBond(const Chem::Bond& bond, const Chem::MolecularGraph& molgraph)
{
    using namespace Chem;

    if (getRingFlag(bond))
		return false;

    const Atom& atom1 = bond.getBegin();
	unsigned int atom1_type = getType(atom1);

	if (atom1_type == AtomType::H)
		return false;

    const Atom& atom2 = bond.getEnd();
    unsigned int atom2_type = getType(atom2);
 
	if (atom2_type == AtomType::H)
		return false;

    if (getRingFlag(atom1)) 
		return (getBondCount(atom2, molgraph) > 1);

    if (getRingFlag(atom2))
		return (getBondCount(atom1, molgraph) > 1);

    if (getOrder(bond) != 1)
		return false;
 
    if (atom1_type == AtomType::C) {
		if (!isSplitHeteroAtom(atom2_type))
			return false;

		return hasOnlyCarbonOrHydrogenNeighbors(atom1, molgraph, bond);
    }

    if (atom2_type == AtomType::C) {
		if (!isSplitHeteroAtom(atom1_type))
			return false;

		return hasOnlyCarbonOrHydrogenNeighbors(atom2, molgraph, bond);
	}

    return false;
} 

unsigned int ConfGen::perceiveFragmentType(const Chem::BondContainer& cntnr)
{
    using namespace Chem;

	bool has_arom_ring_bonds = false;

	for (BondContainer::ConstBondIterator it = cntnr.getBondsBegin(), end = cntnr.getBondsEnd(); it != end; ++it) {
		const Bond& bond = *it;

		if (getRingFlag(bond)) {
			if (getAromaticityFlag(bond))
				has_arom_ring_bonds = true;
			else
				return FragmentType::FLEXIBLE_RING_SYSTEM;
		}
	}

	if (has_arom_ring_bonds)
		return FragmentType::RIGID_RING_SYSTEM;
	
	return FragmentType::CHAIN;
}