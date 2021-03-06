/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * JMEReactionInputHandlerTest.cpp 
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


#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include <boost/test/auto_unit_test.hpp>

#include "CDPL/Chem/JMEReactionInputHandler.hpp"
#include "CDPL/Chem/DataFormats.hpp"
#include "CDPL/Chem/JMEReactionReader.hpp"
#include "CDPL/Chem/JMEReactionWriter.hpp"
#include "CDPL/Chem/Reaction.hpp"
#include "CDPL/Chem/ReactionProperties.hpp"
#include "CDPL/Base/DataIOManager.hpp"
#include "CDPL/Base/DataReader.hpp"
#include "CDPL/Base/IntTypes.hpp"


BOOST_AUTO_TEST_CASE(JMEReactionInputHandlerTest)
{
	using namespace CDPL;
	using namespace Chem;
	using namespace Base;

	Reaction rxn1;
	Reaction rxn2;

	const DataInputHandler<Reaction>* handler = DataIOManager<Reaction>::getInputHandlerByFormat(Chem::DataFormat::JME);

	BOOST_CHECK(handler);

	BOOST_CHECK(handler->getDataFormat() == Chem::DataFormat::JME);

	BOOST_CHECK(DataIOManager<Reaction>::getInputHandlerByName("jme") == handler);
	BOOST_CHECK(DataIOManager<Reaction>::getInputHandlerByFileExtension("jme") == handler);

	std::ifstream ifs(std::string(std::string(std::getenv("CDPKIT_TEST_DATA_DIR")) + "/MorphineAcetylation.jme").c_str());

	BOOST_CHECK(ifs);

	BOOST_CHECK(JMEReactionReader(ifs).read(rxn1));

	std::ostringstream oss;

	BOOST_CHECK(oss);

	BOOST_CHECK(JMEReactionWriter(oss).write(rxn1));

	std::istringstream iss(oss.str());

	BOOST_CHECK(iss);

	DataReader<Reaction>::SharedPointer reader_ptr(handler->createReader(iss));

	BOOST_CHECK(reader_ptr);
	BOOST_CHECK(reader_ptr->read(rxn2));

	BOOST_CHECK(rxn1.getNumReactants() == rxn2.getNumReactants());
	BOOST_CHECK(rxn1.getNumAgents() == rxn2.getNumAgents());
	BOOST_CHECK(rxn1.getNumProducts() == rxn2.getNumProducts());

	BOOST_CHECK(rxn1.getProperty<Base::uint64>(ReactionProperty::HASH_CODE) == rxn2.getProperty<Base::uint64>(ReactionProperty::HASH_CODE));
}

