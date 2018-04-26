/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * PharmacophoreAutoCorr3DFingerprintGenerator.cpp 
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

#include "CDPL/Pharm/PharmacophoreAutoCorr3DFingerprintGenerator.hpp"
#include "CDPL/Pharm/FeatureContainer.hpp"
#include "CDPL/Pharm/Feature.hpp"
#include "CDPL/Pharm/FeatureType.hpp"
#include "CDPL/Pharm/FeatureFunctions.hpp"
#include "CDPL/Chem/Entity3DFunctions.hpp"


using namespace CDPL;


namespace
{

	struct FeaturePairWeightFunc
	{

		FeaturePairWeightFunc(unsigned int curr_ftr_type): currFtrType(curr_ftr_type) {}
	
		double operator()(const Pharm::Feature& ftr1, const Pharm::Feature& ftr2) const {
			unsigned int ftr_type1 = getType(ftr1);
			unsigned int ftr_type2 = getType(ftr2);

			if (ftr_type1 == currFtrType && ftr_type2 == currFtrType)
				return 2;

			if (ftr_type1 == currFtrType || ftr_type2 == currFtrType)
				return 1;

			return 0;
		}

		unsigned int currFtrType;
	};

	unsigned int FEATURE_TYPES[] = {
	    Pharm::FeatureType::HYDROPHOBIC,
		Pharm::FeatureType::AROMATIC,
		Pharm::FeatureType::NEG_IONIZABLE,
		Pharm::FeatureType::POS_IONIZABLE,
		Pharm::FeatureType::H_BOND_DONOR,
		Pharm::FeatureType::H_BOND_ACCEPTOR
	};
}


CDPL::Pharm::PharmacophoreAutoCorr3DFingerprintGenerator::PharmacophoreAutoCorr3DFingerprintGenerator()
{
    setFeature3DCoordinatesFunction(&Chem::get3DCoordinates);
} 

CDPL::Pharm::PharmacophoreAutoCorr3DFingerprintGenerator::PharmacophoreAutoCorr3DFingerprintGenerator(const FeatureContainer& cntnr, Math::DVector& fp)
{
    setFeature3DCoordinatesFunction(&Chem::get3DCoordinates);
    generate(cntnr, fp);
}

void CDPL::Pharm::PharmacophoreAutoCorr3DFingerprintGenerator::setStartRadius(double start_radius)
{
    autoCorrCalculator.setStartRadius(start_radius);
}

double CDPL::Pharm::PharmacophoreAutoCorr3DFingerprintGenerator::getStartRadius() const
{
    return autoCorrCalculator.getStartRadius();
}

void CDPL::Pharm::PharmacophoreAutoCorr3DFingerprintGenerator::setRadiusIncrement(double radius_inc)
{
    autoCorrCalculator.setRadiusIncrement(radius_inc);
}

double CDPL::Pharm::PharmacophoreAutoCorr3DFingerprintGenerator::getRadiusIncrement() const
{
    return autoCorrCalculator.getRadiusIncrement();
}

void CDPL::Pharm::PharmacophoreAutoCorr3DFingerprintGenerator::setNumSteps(std::size_t num_steps)
{
    autoCorrCalculator.setNumSteps(num_steps);
}

std::size_t CDPL::Pharm::PharmacophoreAutoCorr3DFingerprintGenerator::getNumSteps() const
{
    return autoCorrCalculator.getNumSteps();
}

void CDPL::Pharm::PharmacophoreAutoCorr3DFingerprintGenerator::setFeature3DCoordinatesFunction(const Feature3DCoordinatesFunction& func)
{
    autoCorrCalculator.setEntity3DCoordinatesFunction(func);
}

void CDPL::Pharm::PharmacophoreAutoCorr3DFingerprintGenerator::generate(const FeatureContainer& cntnr, Math::DVector& fp)
{
	std::size_t sub_fp_size = autoCorrCalculator.getNumSteps() + 1;
	std::size_t num_ftr_types = sizeof(FEATURE_TYPES) / sizeof(unsigned int);

	fp.resize(sub_fp_size * num_ftr_types, false);

	for (std::size_t i = 0; i < num_ftr_types; i++) {
		autoCorrCalculator.setEntityPairWeightFunction(FeaturePairWeightFunc(FEATURE_TYPES[i]));

		Math::VectorRange<Math::DVector> sub_fp(fp, Math::range(i * sub_fp_size, (i + 1) * sub_fp_size));

		autoCorrCalculator.calculate(cntnr.getFeaturesBegin(), cntnr.getFeaturesEnd(), sub_fp);
	}
}
