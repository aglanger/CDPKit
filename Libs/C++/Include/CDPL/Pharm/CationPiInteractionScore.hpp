/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * CationPiInteractionScore.hpp 
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
 * \brief Definition of the class CDPL::Pharm::CationPiInteractionScore.
 */

#ifndef CDPL_PHARM_CATIONPIINTERACTIONSCORE_HPP
#define CDPL_PHARM_CATIONPIINTERACTIONSCORE_HPP

#include <boost/function.hpp>

#include "CDPL/Pharm/APIPrefix.hpp"
#include "CDPL/Math/Vector.hpp"


namespace CDPL 
{

    namespace Pharm
    {

		class Feature;

		/**
		 * \addtogroup CDPL_PHARM_FUNCTORS
		 * @{
		 */

		/**
		 * \brief CationPiInteractionScore.
		 */
		class CDPL_PHARM_API CationPiInteractionScore
		{

		  public:
			static const double DEF_MIN_DISTANCE;
			static const double DEF_MAX_DISTANCE;
			static const double DEF_MAX_ANGLE;

			typedef boost::function1<double, double> NormalizationFunction;

			/**
			 * \brief Constructs a \c %CationPiInteractionScore functor with the specified constraints.
			 * \param aro_cat \c true if the first feature argument represents the aromatic- and the second one
			 *                the cationic-feature, and \c false otherwise.
			 * \param min_dist The minimum allowed distance between the cationic- and aromatic-feature centers.
			 * \param max_dist The maximum allowed distance between the cationic- and aromatic-feature centers.
			 * \param max_ang The maximum allowed angle between the cationic- and aromatic-feature plane normal.
			 */
			CationPiInteractionScore(bool aro_cat, double min_dist = DEF_MIN_DISTANCE, double max_dist = DEF_MAX_DISTANCE,
									 double max_ang = DEF_MAX_ANGLE);

			double getMinDistance() const;

			double getMaxDistance() const;

			double getMaxAngle() const;

			void setNormalizationFunction(const NormalizationFunction& func);

			double operator()(const Feature& ftr1, const Feature& ftr2) const;

			double operator()(const Math::Vector3D& ftr1_pos, const Feature& ftr2) const;

		  private:
			bool                  aroCatOrder;
			double                minDist;
			double                maxDist;
			double                maxAngle;
			NormalizationFunction normFunc;
		};

		/**
		 * @}
		 */
    }
}

#endif // CDPL_PHARM_CATIONPIINTERACTIONSCORE_HPP
