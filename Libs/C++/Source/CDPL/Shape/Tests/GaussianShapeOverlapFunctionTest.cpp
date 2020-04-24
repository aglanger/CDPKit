/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * GaussianShapeOverlapFunctionTest.cpp 
 *
 * This file is part of the Chemical Data Processing Toolkit
 *
 * Copyright (C) 2003-2020 Thomas A. Seidel <thomas.seidel@univie.ac.at>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; see the file COPYING. If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#include <boost/test/auto_unit_test.hpp>

#include "CDPL/Shape/GaussianShapeOverlapFunction.hpp"
#include "CDPL/Shape/GaussianShapeFunction.hpp"
#include "CDPL/Shape/GaussianShape.hpp"
#include "CDPL/Math/AffineTransform.hpp"

#include "TestData.hpp"


namespace
{

	double calcGradientRMS(const CDPL::Math::Vector3DArray& grad)
	{
		double rms = 0.0;

		for (std::size_t i = 0; i < grad.getSize(); i++)
			rms += innerProd(grad[i], grad[i]);

		return (std::sqrt(rms / (grad.getSize() * 3)));
	}
}


BOOST_AUTO_TEST_CASE(GaussianShapeOverlapFunctionTest)
{
    using namespace CDPL;
    using namespace Shape;
	
	GaussianShapeOverlapFunction overlap_func;
	GaussianShapeFunction shape_func1, shape_func2;
	Math::Vector3DArray overlap_grad;

	shape_func1.setShape(*TestData::getShapeData("1dwc_MIT", 2.7));
	shape_func2 = shape_func1;
	
	overlap_func.setShapeFunction(shape_func1, true);
	overlap_func.setShapeFunction(shape_func2, false);
	overlap_func.enableProximityOptimization(false);
	overlap_func.useFastExpFunction(false);

	BOOST_CHECK_CLOSE(overlap_func.calcOverlap(), 341.132, 0.001);
	BOOST_CHECK_CLOSE(overlap_func.calcOverlap(Math::IdentityMatrix<double>(4, 4)), 341.132, 0.001);
	BOOST_CHECK_CLOSE(overlap_func.calcOverlapGradient(Math::IdentityMatrix<double>(4, 4), overlap_grad), 341.132, 0.001);
	BOOST_CHECK_CLOSE(overlap_func.calcSelfOverlap(true), 341.132, 0.001);
	BOOST_CHECK_CLOSE(overlap_func.calcSelfOverlap(false), 341.132, 0.001);

	overlap_func.enableProximityOptimization(true);
	overlap_func.useFastExpFunction(true);

	BOOST_CHECK_CLOSE(overlap_func.calcOverlap(), 347.114, 0.001);
	BOOST_CHECK_CLOSE(overlap_func.calcOverlap(Math::IdentityMatrix<double>(4, 4)), 347.114, 0.001);
	BOOST_CHECK_CLOSE(overlap_func.calcOverlapGradient(Math::IdentityMatrix<double>(4, 4), overlap_grad), 347.114, 0.001);
	BOOST_CHECK_CLOSE(overlap_func.calcSelfOverlap(true), 347.114, 0.001);
	BOOST_CHECK_CLOSE(overlap_func.calcSelfOverlap(false), 347.114, 0.001);

//-
	
	shape_func1.setShape(*TestData::getShapeData("4phv_VAC", 2.7));
	shape_func2 = shape_func1;
	
	overlap_func.setShapeFunction(shape_func1, true);
	overlap_func.setShapeFunction(shape_func2, false);
	overlap_func.enableProximityOptimization(false);
	overlap_func.useFastExpFunction(false);
	
	BOOST_CHECK_CLOSE(overlap_func.calcOverlap(), 431.894, 0.001);

	overlap_func.enableProximityOptimization(true);
	overlap_func.useFastExpFunction(true);

	BOOST_CHECK_CLOSE(overlap_func.calcOverlap(), 439.375, 0.001);

//-
	
	shape_func1.setShape(*TestData::getShapeData("1tmn_0ZN", 2.7));
	shape_func2 = shape_func1;
	
	overlap_func.setShapeFunction(shape_func1, true);
	overlap_func.setShapeFunction(shape_func2, false);
	overlap_func.enableProximityOptimization(false);
	overlap_func.useFastExpFunction(false);

	BOOST_CHECK_CLOSE(overlap_func.calcOverlap(), 335.628, 0.001);
	BOOST_CHECK_CLOSE(overlap_func.calcOverlap(Math::TranslationMatrix<double>(4, 1.0, 0.0, 0.0)), 277.618, 0.001);
	
	overlap_func.enableProximityOptimization(true);
	overlap_func.useFastExpFunction(true);

	BOOST_CHECK_CLOSE(overlap_func.calcOverlap(), 337.4, 0.001);
	BOOST_CHECK_CLOSE(overlap_func.calcOverlap(Math::TranslationMatrix<double>(4, 1.0, 0.0, 0.0)), 274.306, 0.001);
	
//-

	overlap_func.useFastExpFunction(false);

	BOOST_CHECK(overlap_func.calcOverlapGradient(Math::IdentityMatrix<double>(4, 4), overlap_grad) == overlap_func.calcOverlap());

	//Math::Vector3DArray num_overlap_grad;
	//num_overlap_grad.resize(overlap_grad.getSize());

	for (std::size_t i = 0, num_elem = shape_func2.getShape()->getNumElements(); i < num_elem; i++) {
		GaussianShape::Element& elem = const_cast<GaussianShape::Element&>(shape_func2.getShape()->getElement(i));
		Math::Vector3D elem_pos = elem.getPosition();
		
		for (std::size_t j = 0; j < 3; j++) {
			Math::Vector3D tmp = elem_pos;

			tmp[j] += 0.00001;
			
			elem.setPosition(tmp);
			shape_func2.setShape(*shape_func2.getShape());

			double num_grad = overlap_func.calcOverlap();

			tmp[j] -= 0.00002;

			elem.setPosition(tmp);
			shape_func2.setShape(*shape_func2.getShape());

			num_grad = (num_grad - overlap_func.calcOverlap()) / 0.00002;
			
			BOOST_CHECK_CLOSE(overlap_grad[i][j], num_grad, 0.01);

			elem.setPosition(elem_pos);

			//num_overlap_grad[i][j] = num_grad;
		}
	}

	BOOST_CHECK_CLOSE(calcGradientRMS(overlap_grad), 2.73076, 0.001);
}
