/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * ControlParameterDefault.hpp 
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
 * \brief Definition of constants in namespace CDPL::Pharm::ControlParameterDefault.
 */

#ifndef CDPL_PHARM_CONTROLPARAMETERDEFAULT_HPP
#define CDPL_PHARM_CONTROLPARAMETERDEFAULT_HPP

#include "CDPL/Pharm/APIPrefix.hpp"


namespace CDPL 
{

	namespace Pharm
	{

		/**
		 * \addtogroup CDPL_PHARM_CONTROL_PARAMETERS
		 * @{
		 */

		/**
		 * \brief Provides default values for built-in control-parameters.
		 */
		namespace ControlParameterDefault
		{

			/**
			 * \brief Default setting (= \c false) for the control-parameter Pharm::ControlParameter::STRICT_ERROR_CHECKING.
			 */
			extern CDPL_PHARM_API const bool STRICT_ERROR_CHECKING;

			extern CDPL_PHARM_API const bool CDF_WRITE_SINGLE_PRECISION_FLOATS;
		}

		/**
		 * @}
		 */
	}
}

#endif // CDPL_PHARM_CONTROLPARAMETERDEFAULT_HPP