/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * BondConfiguration.hpp 
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
 * \brief Definition of constants in namespace CDPL::Chem::BondConfiguration.
 */

#ifndef CDPL_CHEM_BONDCONFIGURATION_HPP
#define CDPL_CHEM_BONDCONFIGURATION_HPP


namespace CDPL 
{

	namespace Chem
	{

		/**
		 * \addtogroup CDPL_CHEM_CONSTANTS
		 * @{
		 */

		/**
		 * \brief Provides constants that are used to specify the <em>E/Z</em> configuration of double bonds.
		 */
		namespace BondConfiguration
		{

			/**
			 * \brief Specifies that the configuration of the bond is undefined.
			 */
			const unsigned int UNDEF  = 0;

			/**
			 * \brief Specifies that a bond does not meet the requirements (e.g. not a double bond or symmetric)
			 *        to be assigned a configuration.
			 */
			const unsigned int NONE   = 0x1;

			/**
			 * \brief Specifies that the bond has \e E configuration.
			 */
			const unsigned int E      = 0x2;
		
			/**
			 * \brief Specifies that the bond has \e TRANS configuration.
			 */
			const unsigned int TRANS  = E;
	
			/**
			 * \brief Specifies that the bond has \e Z configuration.
			 */
			const unsigned int Z      = 0x4;

			/**
			 * \brief Specifies that the bond has \e CIS configuration.
			 */
			const unsigned int CIS      = Z;

			/**
			 * \brief Specifies that the bond meets all requirements but has no defined configuration.
			 */
			const unsigned int EITHER = 0x8;
		}

		/**
		 * @}
		 */
	}
}

#endif // CDPL_CHEM_BONDCONFIGURATION_HPP
