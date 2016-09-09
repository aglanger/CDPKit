/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * CDFMoleculeReader.cpp 
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

#include <boost/lexical_cast.hpp>

#include "CDPL/Biomol/CDFMoleculeReader.hpp"
#include "CDPL/Base/Exceptions.hpp"

#include "CDFDataReader.hpp"


using namespace CDPL;


Biomol::CDFMoleculeReader::CDFMoleculeReader(std::istream& is): 
	Util::StreamDataReader<Chem::Molecule, CDFMoleculeReader>(is), reader(new CDFDataReader(*this)) {}

Biomol::CDFMoleculeReader::~CDFMoleculeReader() {}

bool Biomol::CDFMoleculeReader::readData(std::istream& is, Chem::Molecule& mol)
{
	try {
		return reader->readMolecule(is, mol);

	} catch (Base::Exception& e) {
		throw Base::IOError("CDFMoleculeReader: while reading record " + boost::lexical_cast<std::string>(getRecordIndex()) + 
							": " + e.what());
	}
}

bool Biomol::CDFMoleculeReader::skipData(std::istream& is)
{
	try {
		return reader->skipMolecule(is);

	} catch (Base::Exception& e) {
		throw Base::IOError("CDFMoleculeReader: while skipping record " + boost::lexical_cast<std::string>(getRecordIndex()) + 
							": " + e.what());
	}
}

bool Biomol::CDFMoleculeReader::moreData(std::istream& is)
{
	return reader->hasMoreData(is);
}