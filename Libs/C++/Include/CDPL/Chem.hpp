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

#include "CDPL/Config.hpp"

#include "CDPL/Chem/Entity3D.hpp"
#include "CDPL/Chem/Entity3DContainer.hpp"
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

#include "CDPL/Chem/AtomDictionary.hpp"
#include "CDPL/Chem/FragmentList.hpp"
#include "CDPL/Chem/Entity3DMapping.hpp"
#include "CDPL/Chem/AtomMapping.hpp"
#include "CDPL/Chem/BondMapping.hpp"
#include "CDPL/Chem/AtomBondMapping.hpp"
#include "CDPL/Chem/StringDataBlock.hpp"
#include "CDPL/Chem/ElementHistogram.hpp"
#include "CDPL/Chem/MassComposition.hpp"
#include "CDPL/Chem/MatchConstraintList.hpp"
#include "CDPL/Chem/StereoDescriptor.hpp"
#include "CDPL/Chem/MultiConfMoleculeInputProcessor.hpp"
#include "CDPL/Chem/DefaultMultiConfMoleculeInputProcessor.hpp"
#include "CDPL/Chem/Atom3DCoordinatesFunction.hpp"
#include "CDPL/Chem/AtomPredicate.hpp"
#include "CDPL/Chem/BondPredicate.hpp"

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

#include "CDPL/Chem/Entity3DProperty.hpp"
#include "CDPL/Chem/AtomProperty.hpp"
#include "CDPL/Chem/BondProperty.hpp"
#include "CDPL/Chem/MolecularGraphProperty.hpp"
#include "CDPL/Chem/ReactionProperty.hpp"
#include "CDPL/Chem/AtomPropertyDefault.hpp"
#include "CDPL/Chem/BondPropertyDefault.hpp"
#include "CDPL/Chem/MolecularGraphPropertyDefault.hpp"
#include "CDPL/Chem/ReactionPropertyDefault.hpp"
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
#include "CDPL/Chem/SybylAtomType.hpp"
#include "CDPL/Chem/MOL2MoleculeType.hpp"
#include "CDPL/Chem/MOL2ChargeType.hpp"
#include "CDPL/Chem/HybridizationState.hpp"
#include "CDPL/Chem/ReactionCenterStatus.hpp"
#include "CDPL/Chem/ReactionRole.hpp"
#include "CDPL/Chem/BondDirection.hpp"
#include "CDPL/Chem/RadicalType.hpp"
#include "CDPL/Chem/INCHIReturnCode.hpp"
#include "CDPL/Chem/MDLDataFormatVersion.hpp"
#include "CDPL/Chem/DataFormat.hpp"
#include "CDPL/Chem/TautomerizationType.hpp"

#include "CDPL/Chem/AtomMatchConstraint.hpp"
#include "CDPL/Chem/BondMatchConstraint.hpp"
#include "CDPL/Chem/MolecularGraphMatchConstraint.hpp"
#include "CDPL/Chem/ReactionMatchConstraint.hpp"

#include "CDPL/Chem/INCHIMoleculeInputHandler.hpp"
#include "CDPL/Chem/INCHIMolecularGraphOutputHandler.hpp"
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
#include "CDPL/Chem/CDFMoleculeInputHandler.hpp"
#include "CDPL/Chem/CDFMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/CDFReactionInputHandler.hpp"
#include "CDPL/Chem/CDFReactionOutputHandler.hpp"
#include "CDPL/Chem/MOL2MoleculeInputHandler.hpp"
#include "CDPL/Chem/MOL2MolecularGraphOutputHandler.hpp"

#if defined(HAVE_BOOST_FILESYSTEM) && defined(HAVE_BOOST_IOSTREAMS)

#include "CDPL/Chem/SDFGZMoleculeInputHandler.hpp"
#include "CDPL/Chem/SDFGZMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/SDFBZ2MoleculeInputHandler.hpp"
#include "CDPL/Chem/SDFBZ2MolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/SMILESGZMoleculeInputHandler.hpp"
#include "CDPL/Chem/SMILESGZReactionInputHandler.hpp"
#include "CDPL/Chem/SMILESGZMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/SMILESGZReactionOutputHandler.hpp"
#include "CDPL/Chem/SMILESBZ2MoleculeInputHandler.hpp"
#include "CDPL/Chem/SMILESBZ2ReactionInputHandler.hpp"
#include "CDPL/Chem/SMILESBZ2MolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/SMILESBZ2ReactionOutputHandler.hpp"
#include "CDPL/Chem/RDFGZReactionInputHandler.hpp"
#include "CDPL/Chem/RDFGZReactionOutputHandler.hpp"
#include "CDPL/Chem/RDFBZ2ReactionInputHandler.hpp"
#include "CDPL/Chem/RDFBZ2ReactionOutputHandler.hpp"
#include "CDPL/Chem/CDFGZMoleculeInputHandler.hpp"
#include "CDPL/Chem/CDFGZMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/CDFBZ2MoleculeInputHandler.hpp"
#include "CDPL/Chem/CDFBZ2MolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/CDFGZReactionInputHandler.hpp"
#include "CDPL/Chem/CDFGZReactionOutputHandler.hpp"
#include "CDPL/Chem/CDFBZ2ReactionInputHandler.hpp"
#include "CDPL/Chem/CDFBZ2ReactionOutputHandler.hpp"
#include "CDPL/Chem/MOL2GZMoleculeInputHandler.hpp"
#include "CDPL/Chem/MOL2GZMolecularGraphOutputHandler.hpp"
#include "CDPL/Chem/MOL2BZ2MoleculeInputHandler.hpp"
#include "CDPL/Chem/MOL2BZ2MolecularGraphOutputHandler.hpp"

#include "CDPL/Chem/SDFGZMoleculeReader.hpp"
#include "CDPL/Chem/SDFGZMolecularGraphWriter.hpp"
#include "CDPL/Chem/SDFBZ2MoleculeReader.hpp"
#include "CDPL/Chem/SDFBZ2MolecularGraphWriter.hpp"
#include "CDPL/Chem/RDFGZReactionReader.hpp"
#include "CDPL/Chem/RDFGZReactionWriter.hpp"
#include "CDPL/Chem/RDFBZ2ReactionReader.hpp"
#include "CDPL/Chem/RDFBZ2ReactionWriter.hpp"
#include "CDPL/Chem/SMILESGZMoleculeReader.hpp"
#include "CDPL/Chem/SMILESGZMolecularGraphWriter.hpp"
#include "CDPL/Chem/SMILESBZ2MoleculeReader.hpp"
#include "CDPL/Chem/SMILESBZ2MolecularGraphWriter.hpp"
#include "CDPL/Chem/SMILESGZReactionReader.hpp"
#include "CDPL/Chem/SMILESGZReactionWriter.hpp"
#include "CDPL/Chem/SMILESBZ2ReactionReader.hpp"
#include "CDPL/Chem/SMILESBZ2ReactionWriter.hpp"
#include "CDPL/Chem/CDFGZMoleculeReader.hpp"
#include "CDPL/Chem/CDFGZMolecularGraphWriter.hpp"
#include "CDPL/Chem/CDFBZ2MoleculeReader.hpp"
#include "CDPL/Chem/CDFBZ2MolecularGraphWriter.hpp"
#include "CDPL/Chem/CDFGZReactionReader.hpp"
#include "CDPL/Chem/CDFGZReactionWriter.hpp"
#include "CDPL/Chem/CDFBZ2ReactionReader.hpp"
#include "CDPL/Chem/CDFBZ2ReactionWriter.hpp"
#include "CDPL/Chem/MOL2GZMoleculeReader.hpp"
#include "CDPL/Chem/MOL2GZMolecularGraphWriter.hpp"
#include "CDPL/Chem/MOL2BZ2MoleculeReader.hpp"
#include "CDPL/Chem/MOL2BZ2MolecularGraphWriter.hpp"

#endif // defined(HAVE_BOOST_FILESYSTEM) && defined(HAVE_BOOST_IOSTREAMS)

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
#include "CDPL/Chem/CDFMoleculeReader.hpp"
#include "CDPL/Chem/CDFMolecularGraphWriter.hpp"
#include "CDPL/Chem/CDFReactionReader.hpp"
#include "CDPL/Chem/CDFReactionWriter.hpp"
#include "CDPL/Chem/MOL2MoleculeReader.hpp"
#include "CDPL/Chem/MOL2MolecularGraphWriter.hpp"

#include "CDPL/Chem/CompleteRingSet.hpp"
#include "CDPL/Chem/AromaticRingSet.hpp"
#include "CDPL/Chem/AromaticSSSRSubset.hpp"
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
#include "CDPL/Chem/AtomRDFCodeCalculator.hpp"
#include "CDPL/Chem/AutoCorrelation2DVectorCalculator.hpp"
#include "CDPL/Chem/AutoCorrelation3DVectorCalculator.hpp"
#include "CDPL/Chem/AtomAutoCorrelation3DVectorCalculator.hpp"
#include "CDPL/Chem/BurdenMatrixGenerator.hpp"
#include "CDPL/Chem/BCUTDescriptorCalculator.hpp"
#include "CDPL/Chem/SurfaceAtomExtractor.hpp"
#include "CDPL/Chem/PatternAtomTyper.hpp"
#include "CDPL/Chem/SubstructureHistogramGenerator.hpp"
#include "CDPL/Chem/PathFingerprintGenerator.hpp"
#include "CDPL/Chem/CircularFingerprintGenerator.hpp"
#include "CDPL/Chem/GeneralizedBellAtomDensity.hpp"  
#include "CDPL/Chem/AtomDensityGridCalculator.hpp"  
#include "CDPL/Chem/AtomHydrophobicityCalculator.hpp"  
#include "CDPL/Chem/BuriednessScore.hpp"  
#include "CDPL/Chem/BuriednessGridCalculator.hpp"  
#include "CDPL/Chem/TautomerGenerator.hpp"  
#include "CDPL/Chem/DefaultTautomerGenerator.hpp"  
#include "CDPL/Chem/TautomerizationRule.hpp"  
#include "CDPL/Chem/PatternBasedTautomerizationRule.hpp"  
#include "CDPL/Chem/KetoEnolTautomerization.hpp"  
#include "CDPL/Chem/ImineEnamineTautomerization.hpp"  
#include "CDPL/Chem/NitrosoOximeTautomerization.hpp"  
#include "CDPL/Chem/AmideImidicAcidTautomerization.hpp"  
#include "CDPL/Chem/LactamLactimTautomerization.hpp"  
#include "CDPL/Chem/KeteneYnolTautomerization.hpp"  
#include "CDPL/Chem/NitroAciTautomerization.hpp"  
#include "CDPL/Chem/PhosphinicAcidTautomerization.hpp"  
#include "CDPL/Chem/SulfenicAcidTautomerization.hpp"  
#include "CDPL/Chem/GenericHydrogen13ShiftTautomerization.hpp"  
#include "CDPL/Chem/GenericHydrogen15ShiftTautomerization.hpp"  

#include "CDPL/Chem/TopologicalEntityAlignment.hpp"
#include "CDPL/Chem/GeometricalEntityAlignment.hpp"

#include "CDPL/Chem/Atom3DCoordinatesFunctor.hpp"
#include "CDPL/Chem/AtomConformer3DCoordinatesFunctor.hpp"
#include "CDPL/Chem/AtomArray3DCoordinatesFunctor.hpp"

#include "CDPL/Chem/SimilarityFunctions.hpp"
#include "CDPL/Chem/UtilityFunctions.hpp"
#include "CDPL/Chem/AtomContainerFunctions.hpp"
#include "CDPL/Chem/BondContainerFunctions.hpp"
#include "CDPL/Chem/AtomContainerFunctions.hpp"
#include "CDPL/Chem/Entity3DContainerFunctions.hpp"
#include "CDPL/Chem/AtomFunctions.hpp"
#include "CDPL/Chem/BondFunctions.hpp"
#include "CDPL/Chem/MolecularGraphFunctions.hpp"
#include "CDPL/Chem/MoleculeFunctions.hpp"
#include "CDPL/Chem/FragmentFunctions.hpp"
#include "CDPL/Chem/ReactionFunctions.hpp"

#endif // CDPL_CHEM_HPP
