/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * FastGaussianShapeOverlapFunction.hpp 
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
 * \brief Definition of the class CDPL::Shape::FastGaussianShapeOverlapFunction.
 */

#ifndef CDPL_SHAPE_FASTGAUSSIANSHAPEOVERLAPFUNCTION_HPP
#define CDPL_SHAPE_FASTGAUSSIANSHAPEOVERLAPFUNCTION_HPP

#include <boost/shared_ptr.hpp>

#include "CDPL/Shape/APIPrefix.hpp"
#include "CDPL/Shape/GaussianShapeOverlapFunction.hpp"


namespace CDPL 
{

    namespace Shape
    {

		/**
		 * \addtogroup CDPL_SHAPE_FUNCTORS
		 * @{
		 */

		class CDPL_SHAPE_API FastGaussianShapeOverlapFunction : public GaussianShapeOverlapFunction
		{
			
		  public:
			static const double DEF_RADIUS_SCALING_FACTOR;
			
			typedef boost::shared_ptr<FastGaussianShapeOverlapFunction> SharedPointer;

			FastGaussianShapeOverlapFunction();

			FastGaussianShapeOverlapFunction(const FastGaussianShapeOverlapFunction& func);
			
			FastGaussianShapeOverlapFunction(const GaussianShapeFunction& ref_shape_func,
											 const GaussianShapeFunction& ovl_shape_func);

			~FastGaussianShapeOverlapFunction();
		
			void proximityOptimization(bool enable);

			bool proximityOptimization() const;

			void setRadiusScalingFactor(double factor);

			double getRadiusScalingFactor() const;
			
			void fastExpFunction(bool enable);

			bool fastExpFunction() const;

			FastGaussianShapeOverlapFunction& operator=(const FastGaussianShapeOverlapFunction& func);
			
		  private:
			double calcOverlapImpl(const GaussianProductList* prod_list1, const GaussianProductList* prod_list2,
								   const GaussianProductCenterArray& trans_prod_ctrs, bool orig_centers, bool rigid_xform) const;
			double calcOverlapGradientImpl(const GaussianProductList* prod_list1, const GaussianProductList* prod_list2,
										   const GaussianProductCenterArray& trans_prod_ctrs, Math::Vector3DArray::StorageType& grad,
										   bool rigid_xform) const;
			bool   proximityOpt;
			bool   fastExpFunc;
			double radScalingFact;
		};

		/**
		 * @}
		 */
    }
}

#endif // CDPL_SHAPE_FASTGAUSSIANSHAPEOVERLAPFUNCTION_HPP
