/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * Raw3DCoordinatesGenerator.cpp 
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

#include <boost/bind.hpp>

#include "CDPL/ConfGen/Raw3DCoordinatesGenerator.hpp"
#include "CDPL/Chem/MolecularGraph.hpp"
#include "CDPL/Chem/AtomFunctions.hpp"
#include "CDPL/Chem/BondFunctions.hpp"


using namespace CDPL;


ConfGen::Raw3DCoordinatesGenerator::Raw3DCoordinatesGenerator(): 
	molGraph(0), withPlanConstr(true), boxSize(20.0)
{}

void ConfGen::Raw3DCoordinatesGenerator::setBoxSize(double size)
{
    boxSize = size;
}

double ConfGen::Raw3DCoordinatesGenerator::getBoxSize() const
{
    return boxSize;
}

void ConfGen::Raw3DCoordinatesGenerator::regardAtomConfiguration(bool regard)
{
    dgConstraintsGen.regardAtomConfiguration(regard);
}

bool ConfGen::Raw3DCoordinatesGenerator::atomConfigurationRegarded() const
{
    return dgConstraintsGen.atomConfigurationRegarded();
}

void ConfGen::Raw3DCoordinatesGenerator::regardBondConfiguration(bool regard)
{
    dgConstraintsGen.regardBondConfiguration(regard);
}

bool ConfGen::Raw3DCoordinatesGenerator::bondConfigurationRegarded() const
{
    return dgConstraintsGen.bondConfigurationRegarded();
}

void ConfGen::Raw3DCoordinatesGenerator::excludeHydrogens(bool exclude)
{
    dgConstraintsGen.excludeHydrogens(exclude);
}

bool ConfGen::Raw3DCoordinatesGenerator::hydrogensExcluded() const
{
    return dgConstraintsGen.hydrogensExcluded();
}

void ConfGen::Raw3DCoordinatesGenerator::enablePlanarityConstraints(bool enable)
{
	withPlanConstr = enable;
}

bool ConfGen::Raw3DCoordinatesGenerator::planarityConstraintsEnabled() const
{
	return withPlanConstr;
}

const Util::BitSet& ConfGen::Raw3DCoordinatesGenerator::getExcludedHydrogenMask() const
{
	return dgConstraintsGen.getExcludedHydrogenMask();
}

void ConfGen::Raw3DCoordinatesGenerator::setup(const Chem::MolecularGraph& molgraph, 
											   const ForceField::MMFF94InteractionData& ia_data)
{
    setup(molgraph, &ia_data);
}

void ConfGen::Raw3DCoordinatesGenerator::setup(const Chem::MolecularGraph& molgraph) 
{
    setup(molgraph, 0);
}

bool ConfGen::Raw3DCoordinatesGenerator::generate(Math::Vector3DArray& coords)
{
    if (!molGraph)
		return false;

	coords.resize(molGraph->getNumAtoms());

	boost::random::uniform_real_distribution<double> coord_dist(-boxSize * 0.5, boxSize * 0.5);

	for (Math::Vector3DArray::ElementIterator it = coords.getElementsBegin(), end = coords.getElementsEnd(); it != end; ++it) {
		Math::Vector3D& pos = *it;

		pos[0] = coord_dist(randomEngine);
		pos[1] = coord_dist(randomEngine);
		pos[2] = coord_dist(randomEngine);
	}

    phase1CoordsGen.optimize(molGraph->getNumAtoms(), coords.getData());

	if (withPlanConstr) 
		phase2CoordsGen.optimize(molGraph->getNumAtoms(), coords.getData());
	
	if (dgConstraintsGen.atomConfigurationRegarded() && !checkAtomConfigurations(coords))
		return false;

	if (dgConstraintsGen.bondConfigurationRegarded() && !checkBondConfigurations(coords))
		return false;

    return true;
}

void ConfGen::Raw3DCoordinatesGenerator::setup(const Chem::MolecularGraph& molgraph, 
											   const ForceField::MMFF94InteractionData* ia_data)
{
    molGraph = &molgraph;

    if (ia_data)
		dgConstraintsGen.setup(molgraph, *ia_data);
    else
		dgConstraintsGen.setup(molgraph);

	phase1CoordsGen.clearDistanceConstraints();
    phase1CoordsGen.clearVolumeConstraints();
	phase1CoordsGen.setRandomSeed(170375);

    dgConstraintsGen.addBondLengthConstraints(phase1CoordsGen);
    dgConstraintsGen.addBondAngleConstraints(phase1CoordsGen);
    dgConstraintsGen.addBondConfigurationConstraints(phase1CoordsGen);
    dgConstraintsGen.add14DistanceConstraints(phase1CoordsGen);
    dgConstraintsGen.addDefaultDistanceConstraints(phase1CoordsGen);
    dgConstraintsGen.addAtomConfigurationConstraints(phase1CoordsGen);

	if (withPlanConstr) {
		phase2CoordsGen = phase1CoordsGen;

		dgConstraintsGen.addAtomPlanarityConstraints(phase2CoordsGen);	 
		dgConstraintsGen.addBondPlanarityConstraints(phase2CoordsGen);

	} else {
		phase2CoordsGen.clearVolumeConstraints();
		phase2CoordsGen.clearDistanceConstraints();
	}

	randomEngine.seed(170375);
}

bool ConfGen::Raw3DCoordinatesGenerator::checkAtomConfigurations(Math::Vector3DArray& coords) const
{
	for (DGConstraintGenerator::ConstStereoCenterDataIterator it = dgConstraintsGen.getAtomStereoCenterDataBegin(),
			 end = dgConstraintsGen.getAtomStereoCenterDataEnd(); it != end; ++it) {

		const DGConstraintGenerator::StereoCenterData& sc_data = *it;

		if (calcAtomConfiguration(molGraph->getAtom(sc_data.first), *molGraph, sc_data.second, coords) != sc_data.second.getConfiguration())
			return false;
	}

	return true;
}

bool ConfGen::Raw3DCoordinatesGenerator::checkBondConfigurations(Math::Vector3DArray& coords) const
{
	for (DGConstraintGenerator::ConstStereoCenterDataIterator it = dgConstraintsGen.getBondStereoCenterDataBegin(),
			 end = dgConstraintsGen.getBondStereoCenterDataEnd(); it != end; ++it) {

		const DGConstraintGenerator::StereoCenterData& sc_data = *it;

		if (calcBondConfiguration(molGraph->getBond(sc_data.first), *molGraph, sc_data.second, coords) != sc_data.second.getConfiguration())
			return false;
	}

	return true;
}
