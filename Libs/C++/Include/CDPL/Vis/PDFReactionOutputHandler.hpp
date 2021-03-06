/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * PDFReactionOutputHandler.hpp 
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
 * \brief Definition of the class CDPL::Vis::PDFReactionOutputHandler.
 */

#ifndef CDPL_VIS_PDFREACTIONOUTPUTHANDLER_HPP
#define CDPL_VIS_PDFREACTIONOUTPUTHANDLER_HPP

#include "CDPL/Vis/DataFormat.hpp"
#include "CDPL/Vis/PDFReactionWriter.hpp"
#include "CDPL/Util/DefaultDataOutputHandler.hpp"


namespace CDPL 
{

	namespace Vis
	{

		/**
		 * \addtogroup CDPL_VIS_PDF_OUTPUT
		 * @{
		 */

		/**
		 * \brief A handler for the output of 2D depictions of chemical reactions in the <em>Portable
		 *        Document Format (PDF)</em> [\ref WPDF].
		 */
		typedef Util::DefaultDataOutputHandler<PDFReactionWriter, DataFormat::PDF> PDFReactionOutputHandler;	
	
		/**
		 * @}
		 */
	}
}

#endif // CDPL_VIS_PDFREACTIONOUTPUTHANDLER_HPP
