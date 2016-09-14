/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * PharmacophoreGeneratorExport.cpp 
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


#include <boost/python.hpp>

#include "CDPL/Pharm/PharmacophoreGenerator.hpp"

#include "ClassExports.hpp"


void CDPLPythonPharm::exportPharmacophoreGenerator()
{
    using namespace boost;
    using namespace CDPL;

	python::class_<Pharm::PharmacophoreGenerator, python::bases<Pharm::FeatureGenerator>, boost::noncopyable>
		("PharmacophoreGenerator", python::no_init)
		.def(python::init<>(python::arg("self")))
		.def(python::init<Pharm::PharmacophoreGenerator>((python::arg("self"), python::arg("gen"))))
		.def("setFeatureGenerator", &Pharm::PharmacophoreGenerator::setFeatureGenerator, 
			 (python::arg("self"), python::arg("type"), python::arg("ftr_gen")))
		.def("removeFeatureGenerator", &Pharm::PharmacophoreGenerator::removeFeatureGenerator, 
			 (python::arg("self"), python::arg("type")))
		.def("getFeatureGenerator", &Pharm::PharmacophoreGenerator::getFeatureGenerator, 
			 (python::arg("self"), python::arg("type")), python::return_internal_reference<>())
		.def("enableFeature", &Pharm::PharmacophoreGenerator::enableFeature, 
			 (python::arg("self"), python::arg("type"), python::arg("enable")))
		.def("isFeatureEnabled", &Pharm::PharmacophoreGenerator::isFeatureEnabled, 
			 (python::arg("self"), python::arg("ft_type")))
		.def("clearEnabledFeatures", &Pharm::PharmacophoreGenerator::isFeatureEnabled, python::arg("self"))
		.def("assign", &Pharm::PharmacophoreGenerator::operator=, 
			 (python::arg("self"), python::arg("gen")), python::return_self<>());
}
