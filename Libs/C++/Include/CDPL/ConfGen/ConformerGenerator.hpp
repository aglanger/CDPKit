/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * ConformerGenerator.hpp 
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
 * \brief Definition of the class CDPL::ConfGen::ConformerGenerator.
 */

#ifndef CDPL_CONFGEN_CONFORMERGENERATOR_HPP
#define CDPL_CONFGEN_CONFORMERGENERATOR_HPP

#include <memory>

#include "CDPL/ConfGen/APIPrefix.hpp"
#include "CDPL/ConfGen/ConformerGeneratorSettings.hpp"


namespace CDPL 
{

	namespace Chem
	{

		class MolecularGraph;
	}

    namespace ConfGen 
    {

		class ConformerGeneratorImpl;

		/**
		 * \addtogroup CDPL_CONFGEN_GENERATORS
		 * @{
		 */

		class CDPL_CONFGEN_API ConformerGenerator
		{

		public:
			ConformerGenerator();
	
			const ConformerGeneratorSettings& getSettings() const;

			ConformerGeneratorSettings& getSettings();

			unsigned int generate(const Chem::MolecularGraph& molgraph);

		private:
			ConformerGenerator(const ConformerGenerator&);

			ConformerGenerator& operator=(const ConformerGenerator&);

			typedef std::auto_ptr<ConformerGeneratorImpl> ImplementationPointer;

			ImplementationPointer impl;
		};

		/**
		 * @}
		 */
    }
}

#endif // CDPL_CONFGEN_CONFORMERGENERATOR_HPP