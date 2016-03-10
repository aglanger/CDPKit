/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * Chem.hpp 
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

/**
 * \file
 * \brief A convenience header including everything that is defined in namespace CDPL::Chem.
 */

#ifndef CDPL_CHEM_HPP
#define CDPL_CHEM_HPP

#include "CDPL/Chem/AtomContainer.hpp"
#include "CDPL/Chem/BondContainer.hpp"
#include "CDPL/Chem/MolecularGraph.hpp"
#include "CDPL/Chem/Molecule.hpp"
#include "CDPL/Chem/Atom.hpp"
#include "CDPL/Chem/Bond.hpp"
#include "CDPL/Chem/Reaction.hpp"
#include "CDPL/Chem/BasicReaction.hpp"
#include "CDPL/Chem/BasicMolecule.hpp"
#include "CDPL/Chem/BasicAtom.hpp"
#include "CDPL/Chem/BasicBond.hpp"
#include "CDPL/Chem/Fragment.hpp"
#include "CDPL/Chem/Pharmacophore.hpp"
#include "CDPL/Chem/PharmacophoreFeature.hpp"
#include "CDPL/Chem/BasicPharmacophore.hpp"
#include "CDPL/Chem/BasicPharmacophoreFeature.hpp"

#include "CDPL/Chem/FragmentList.hpp"
#include "CDPL/Chem/AtomMapping.hpp"
#include "CDPL/Chem/BondMapping.hpp"
#include "CDPL/Chem/AtomBondMapping.hpp"
#include "CDPL/Chem/MDLDataBlock.hpp"
#include "CDPL/Chem/PDBData.hpp"
#include "CDPL/Chem/ElementHistogram.hpp"
#include "CDPL/Chem/MassComposition.hpp"
#include "CDPL/Chem/MatchConstraintList.hpp"
#include "CDPL/Chem/StereoDescriptor.hpp"
#include "CDPL/Chem/MultiConfMoleculeInputProcessor.hpp"
#include "CDPL/Chem/DefaultMultiConfMoleculeInputProcessor.hpp"

#include "CDPL/Chem/MatchExpression.hpp"
#include "CDPL/Chem/MatchExpressionList.hpp"
#include "CDPL/Chem/ANDMatchExpressionList.hpp"
#include "CDPL/Chem/ORMatchExpressionList.hpp"
#include "CDPL/Chem/NOTMatchExpression.hpp"
#include "CDPL/Chem/PropertyMatchExpression.hpp"
#include "CDPL/Chem/AtomTypeMatchExpression.hpp"
#include "CDPL/Chem/AtomEnvironmentMatchExpression.hpp"
#include "CDPL/Chem/AtomConfigurationMatchExpression.hpp"
#include "CDPL/Chem/AtomSSSRRingSizeMatchExpression.hpp"
#include "CDPL/Chem/BondConfigurationMatchExpression.hpp"
#include "CDPL/Chem/BondDirectionMatchExpression.hpp"
#include "CDPL/Chem/BondSubstituentDirectionMatchExpression.hpp"
#include "CDPL/Chem/BondReactionCenterStatusMatchExpression.hpp"
#include "CDPL/Chem/MolecularGraphComponentGroupingMatchExpression.hpp"
#include "CDPL/Chem/ReactionAtomMappingMatchExpression.hpp"
#include "CDPL/Chem/ReactionComponentGroupingMatchExpression.hpp"

#include "CDPL/Chem/AtomProperty.hpp"
#include "CDPL/Chem/BondProperty.hpp"
#include "CDPL/Chem/MolecularGraphProperty.hpp"
#include "CDPL/Chem/ReactionProperty.hpp"
#include "CDPL/Chem/PharmacophoreProperty.hpp"
#include "CDPL/Chem/PharmacophoreFeatureProperty.hpp"
#include "CDPL/Chem/AtomPropertyFlag.hpp"
#include "CDPL/Chem/BondPropertyFlag.hpp"
#include "CDPL/Chem/ControlParameter.hpp"
#include "CDPL/Chem/ControlParameterDefault.hpp"
#include "CDPL/Chem/ControlParameterFunctions.hpp"

#include "CDPL/Chem/AtomConfiguration.hpp"
#include "CDPL/Chem/BondConfiguration.hpp"
#include "CDPL/Chem/MDLParity.hpp"
#include "CDPL/Chem/BondStereoFlag.hpp"
#include "CDPL/Chem/AtomType.hpp"
#include "CDPL/Chem/ResidueType.hpp"
#include "CDPL/Chem/HybridizationState.hpp"
#include "CDPL/Chem/ReactionCenterStatus.hpp"
#include "CDPL/Chem/ReactionRole.hpp"
#include "CDPL/Chem/BondDirection.hpp"
#include "CDPL/Chem/RadicalType.hpp"
#include "CDPL/Chem/INCHIReturnCode.hpp"
#include "CDPL/Chem/MDLDataFormatVersion.hpp"
#include "CDPL/Chem/PharmacophoreFeatureType.hpp"
#include "CDPL/Chem/PharmacophoreFeatureGeometry.hpp"
#include "CDPL/Chem/DataFormat.hpp"

#include "CDPL/Chem/AtomMatchConstraint.hpp"
#include "CDPL/Chem/BondMatchConstraint.hpp"
#include "CDPL/Chem/MolecularGraphMatchConstraint.hpp"
#include "CDPL/Chem/ReactionMatchConstraint.hpp"

#include "CDPL/Chem/JMEMoleculeInputHandler.hpp"
#include "CDPL/Chem/JMEReactionInputHandler.hpp"
#include "CDPL/Chem/JMEMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/JMEReactionOutputHandler.hpp"
#include "CDPL/Chem/MOLMoleculeInputHandler.hpp"
#include "CDPL/Chem/MOLMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/SDFMoleculeInputHandler.hpp"
#include "CDPL/Chem/SDFMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/RXNReactionInputHandler.hpp"
#include "CDPL/Chem/RXNReactionOutputHandler.hpp"
#include "CDPL/Chem/RDFReactionInputHandler.hpp"
#include "CDPL/Chem/RDFReactionOutputHandler.hpp"
#include "CDPL/Chem/SMILESMoleculeInputHandler.hpp"
#include "CDPL/Chem/SMILESReactionInputHandler.hpp"
#include "CDPL/Chem/SMILESMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/SMILESReactionOutputHandler.hpp"
#include "CDPL/Chem/SMARTSMoleculeInputHandler.hpp"
#include "CDPL/Chem/SMARTSReactionInputHandler.hpp"
#include "CDPL/Chem/SMARTSMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/SMARTSReactionOutputHandler.hpp"
#include "CDPL/Chem/INCHIMoleculeInputHandler.hpp"
#include "CDPL/Chem/INCHIMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/PDBMoleculeInputHandler.hpp"
#include "CDPL/Chem/PDBMolecularGraphOutputHandler.hpp"

#include "CDPL/Chem/JMEMoleculeReader.hpp"
#include "CDPL/Chem/JMEReactionReader.hpp"
#include "CDPL/Chem/JMEMolecularGraphWriter.hpp"
#include "CDPL/Chem/JMEReactionWriter.hpp"
#include "CDPL/Chem/SMILESMoleculeReader.hpp"
#include "CDPL/Chem/SMILESReactionReader.hpp"
#include "CDPL/Chem/SMILESMolecularGraphWriter.hpp"
#include "CDPL/Chem/SMILESReactionWriter.hpp"
#include "CDPL/Chem/SMARTSMoleculeReader.hpp"
#include "CDPL/Chem/SMARTSReactionReader.hpp"
#include "CDPL/Chem/SMARTSMolecularGraphWriter.hpp"
#include "CDPL/Chem/SMARTSReactionWriter.hpp"
#include "CDPL/Chem/MOLMoleculeReader.hpp"
#include "CDPL/Chem/MOLMolecularGraphWriter.hpp"
#include "CDPL/Chem/SDFMoleculeReader.hpp"
#include "CDPL/Chem/SDFMolecularGraphWriter.hpp"
#include "CDPL/Chem/RXNReactionReader.hpp"
#include "CDPL/Chem/RXNReactionWriter.hpp"
#include "CDPL/Chem/RDFReactionReader.hpp"
#include "CDPL/Chem/RDFReactionWriter.hpp"
#include "CDPL/Chem/INCHIMoleculeReader.hpp"
#include "CDPL/Chem/INCHIMolecularGraphWriter.hpp"
#include "CDPL/Chem/PDBMoleculeReader.hpp"
#include "CDPL/Chem/PDBMolecularGraphWriter.hpp"

#include "CDPL/Chem/CompleteRingSet.hpp"
#include "CDPL/Chem/AromaticRingSet.hpp"
#include "CDPL/Chem/SmallestSetOfSmallestRings.hpp"
#include "CDPL/Chem/AromaticSubstructure.hpp"
#include "CDPL/Chem/CyclicSubstructure.hpp"
#include "CDPL/Chem/ConnectedSubstructureSet.hpp"
#include "CDPL/Chem/ComponentSet.hpp"

#include "CDPL/Chem/SubstructureSearch.hpp"
#include "CDPL/Chem/ReactionSubstructureSearch.hpp"
#include "CDPL/Chem/CommonConnectedSubstructureSearch.hpp"
#include "CDPL/Chem/MaxCommonAtomSubstructureSearch.hpp"
#include "CDPL/Chem/MaxCommonBondSubstructureSearch.hpp"
#include "CDPL/Chem/Reactor.hpp"

#include "CDPL/Chem/MorganNumberingGenerator.hpp"
#include "CDPL/Chem/CIPPriorityCalculator.hpp"
#include "CDPL/Chem/CanonicalNumberingGenerator.hpp"
#include "CDPL/Chem/HashCodeCalculator.hpp"
#include "CDPL/Chem/Atom2DCoordinatesGenerator.hpp"
#include "CDPL/Chem/Hydrogen3DCoordinatesGenerator.hpp"
#include "CDPL/Chem/DaylightFingerprintGenerator.hpp"
#include "CDPL/Chem/BondStereoFlagGenerator.hpp"
#include "CDPL/Chem/BondDirectionGenerator.hpp"
#include "CDPL/Chem/BondOrderGenerator.hpp"
#include "CDPL/Chem/KekuleStructureGenerator.hpp"
#include "CDPL/Chem/XLogPCalculator.hpp"
#include "CDPL/Chem/TPSACalculator.hpp"
#include "CDPL/Chem/SymmetryClassCalculator.hpp"
#include "CDPL/Chem/MolecularComplexityCalculator.hpp"
#include "CDPL/Chem/PEOEChargeCalculator.hpp"
#include "CDPL/Chem/LogSCalculator.hpp"
#include "CDPL/Chem/RDFCodeCalculator.hpp"
#include "CDPL/Chem/AutoCorrelationVectorCalculator.hpp"
#include "CDPL/Chem/BurdenMatrixGenerator.hpp"
#include "CDPL/Chem/BCUTDescriptorCalculator.hpp"

#include "CDPL/Chem/SimilarityFunctions.hpp"
#include "CDPL/Chem/UtilityFunctions.hpp"
#include "CDPL/Chem/AtomTypeFunctions.hpp"
#include "CDPL/Chem/ResidueFunctions.hpp"
#include "CDPL/Chem/AtomContainerFunctions.hpp"
#include "CDPL/Chem/BondContainerFunctions.hpp"
#include "CDPL/Chem/AtomFunctions.hpp"
#include "CDPL/Chem/BondFunctions.hpp"
#include "CDPL/Chem/MolecularGraphFunctions.hpp"
#include "CDPL/Chem/MoleculeFunctions.hpp"
#include "CDPL/Chem/FragmentFunctions.hpp"
#include "CDPL/Chem/ReactionFunctions.hpp"
#include "CDPL/Chem/PharmacophoreFunctions.hpp"
#include "CDPL/Chem/PharmacophoreFeatureFunctions.hpp"

#endif // CDPL_CHEM_HPP
