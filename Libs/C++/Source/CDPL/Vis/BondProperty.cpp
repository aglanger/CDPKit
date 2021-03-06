/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * BondProperty.cpp 
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


#include "StaticInit.hpp"

#include "CDPL/Vis/BondProperty.hpp"

#include "CDPL/Base/LookupKeyDefinition.hpp"


namespace CDPL
{

	namespace Vis
	{

		namespace BondProperty
		{

			CDPL_DEFINE_LOOKUP_KEY(COLOR);
			CDPL_DEFINE_LOOKUP_KEY(LINE_WIDTH);
			CDPL_DEFINE_LOOKUP_KEY(LINE_SPACING);
			CDPL_DEFINE_LOOKUP_KEY(STEREO_BOND_WEDGE_WIDTH);
			CDPL_DEFINE_LOOKUP_KEY(STEREO_BOND_HASH_SPACING);
			CDPL_DEFINE_LOOKUP_KEY(REACTION_CENTER_LINE_LENGTH);
			CDPL_DEFINE_LOOKUP_KEY(REACTION_CENTER_LINE_SPACING);
			CDPL_DEFINE_LOOKUP_KEY(DOUBLE_BOND_TRIM_LENGTH);
			CDPL_DEFINE_LOOKUP_KEY(TRIPLE_BOND_TRIM_LENGTH);
			CDPL_DEFINE_LOOKUP_KEY(LABEL_FONT);
			CDPL_DEFINE_LOOKUP_KEY(LABEL_SIZE);
			CDPL_DEFINE_LOOKUP_KEY(LABEL_MARGIN);
		}

		void initBondProperties() {}
	}
}
