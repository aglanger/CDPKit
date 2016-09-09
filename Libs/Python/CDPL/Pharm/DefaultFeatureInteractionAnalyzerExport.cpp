/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * DefaultFeatureInteractionAnalyzerExport.cpp 
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

#include "CDPL/Pharm/DefaultFeatureInteractionAnalyzer.hpp"
#include "CDPL/Pharm/Pharmacophore.hpp"

#include "ClassExports.hpp"


void CDPLPythonPharm::exportDefaultFeatureInteractionAnalyzer()
{
    using namespace boost;
    using namespace CDPL;

    python::class_<Pharm::DefaultFeatureInteractionAnalyzer, python::bases<Pharm::FeatureInteractionAnalyzer>,
				   boost::noncopyable>("DefaultFeatureInteractionAnalyzer", python::no_init)
		.def(python::init<>(python::arg("self")))
		.def(python::init<const Pharm::Pharmacophore&, const Pharm::Pharmacophore&, Pharm::FeatureMapping&>(
				 (python::arg("self"), python::arg("molgraph"), python::arg("pharm"))))
		.def(python::init<const Pharm::DefaultFeatureInteractionAnalyzer&>((python::arg("self"), python::arg("analyzer"))))
		.def("assign", &Pharm::DefaultFeatureInteractionAnalyzer::operator=, 
			 (python::arg("self"), python::arg("analyzer")), python::return_self<>());
}