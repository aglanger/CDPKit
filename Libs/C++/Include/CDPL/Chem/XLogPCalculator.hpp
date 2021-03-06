/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * XLogPCalculator.hpp 
 *  
 * Calculation of the partition coefficient by an atom-additive method
 * (R. Wang, Y. Gao, L. Lai, Persp. Drug Disc. Design 2000, 19, 47-66)
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

/**
 * \file
 * \brief Definition of the class CDPL::Chem::XLogPCalculator.
 */

#ifndef CDPL_CHEM_XLOGPCALCULATOR_HPP
#define CDPL_CHEM_XLOGPCALCULATOR_HPP

#include <cstddef>

#include "CDPL/Chem/APIPrefix.hpp"
#include "CDPL/Chem/SubstructureHistogramGenerator.hpp"
#include "CDPL/Chem/PatternAtomTyper.hpp"
#include "CDPL/Math/Vector.hpp"


namespace CDPL 
{

	namespace Chem
	{

		class MolecularGraph;

		/**
		 * \addtogroup CDPL_CHEM_LOGP
		 * @{
		 */

		/**
		 * \brief XLogPCalculator.
		 * \see [\ref XLOGP]
		 */
		class CDPL_CHEM_API XLogPCalculator 
		{

		public:
			/**
			 * \brief Specifies the number of different structural features used by the \f$ \log P \f$ model.
			 */
			static const std::size_t FEATURE_VECTOR_SIZE = 101;

			/**
			 * \brief Constructs the \c %XLogPCalculator instance.
			 */
			XLogPCalculator();

			/**
			 * \brief Constructs the \c %LogSCalculator instance and calculates the \f$ \log P \f$ of the molecular
			 *        graph \a molgraph.
			 *
			 * The calculated \f$ \log P \f$ can be retrieved by a call to getResult().
			 *
			 * \param molgraph The molecular graph for which to calculate the \f$ \log P \f$.
			 */
			XLogPCalculator(const MolecularGraph& molgraph);

			/**
			 * \brief Calculates the \f$ \log P \f$ of the molecular graph \a molgraph.
			 * \param molgraph The molecular graph for which to calculate the \f$ \log P \f$.
			 * \return The calculated \f$ \log P \f$ of the molecular graph \a molgraph.
			 */
			double calculate(const MolecularGraph& molgraph);

			/**
			 * \brief Returns the result of the last \f$ \log P \f$ calculation.
			 * \return The result of the last \f$ \log P \f$ calculation, or zero if a calculation has not yet been performed.
			 */
			double getResult() const;

			/**
			 * \brief Returns the feature count vector of the last \f$ \log P \f$ calculation.
			 *
			 * The occurrence count of a particular structural feature (atom type or correction factor feature) can be retrieved from
			 * the returned vector via its feature index. For atom type related features, the feature index correspond to the
			 * numerical identifier of the atom type in the original publication [\ref XLOGP] minus \e 1. The feature indices
			 * of the various correction factors start at index \e 90 and are ordered according to their definition in the paper.
			 *
			 * \return The feature count vector of the last \f$ \log P \f$ calculation.
			 * \note The returned feature vector is of size XLogPCalculator::FEATURE_VECTOR_SIZE.
			 */
			const Math::DVector& getFeatureVector() const;

		private:
			void init(const MolecularGraph& molgraph);

			void countHydrophicCarbons(const MolecularGraph& molgraph);
	
			void calcLogP(const MolecularGraph& molgraph);
		
			Math::DVector                  featureVector;
			double                         logP;
			PatternAtomTyper               atomTyper;
			SubstructureHistogramGenerator corrSubstructHistoGen;
		};

		/**
		 * @}
		 */
	}
}

#endif // CDPL_CHEM_XLOGPCALCULATOR_HPP
 
