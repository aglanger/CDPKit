/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * AtomProperty.hpp 
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
 * \brief Definition of constants in namespace CDPL::Vis::AtomProperty.
 */

#ifndef CDPL_VIS_ATOMPROPERTY_HPP
#define CDPL_VIS_ATOMPROPERTY_HPP

#include "CDPL/Vis/APIPrefix.hpp"


namespace CDPL
{

	namespace Base
	{

		class LookupKey;
	}

	namespace Vis
	{

		/**
		 * \addtogroup CDPL_VIS_ATOM_PROPERTIES
		 * @{
		 */

		/**
		 * \brief Provides keys for built-in Chem::Atom properties.
		 */
		namespace AtomProperty
		{

			/**
			 * \brief Specifies the color of text labels.
			 *
			 * The color specified by this property takes precedence over the colors specified by Vis::ControlParameter::ATOM_COLOR and
			 * Vis::MolecularGraphProperty::ATOM_COLOR. Furthermore, color tables specified by Vis::ControlParameter::ATOM_COLOR_TABLE
			 * or Vis::MolecularGraphProperty::ATOM_COLOR_TABLE will not be considered if this property is set.
			 *
			 * \valuetype Vis::Color
			 */
			extern CDPL_VIS_API const Base::LookupKey COLOR;
	
			/**
			 * \brief Specifies the font for atom element and query match expression labels.
			 *
			 * The font specified by this property takes precedence over the fonts specified by Vis::ControlParameter::ATOM_LABEL_FONT
			 * and Vis::MolecularGraphProperty::ATOM_LABEL_FONT.
			 *
			 * \valuetype Vis::Font
			 */
			extern CDPL_VIS_API const Base::LookupKey LABEL_FONT;

			/**
			 * \brief Specifies the size of atom element and query match expression labels.
			 *
			 * The font size has to be specified as an absolute value. If input-scaling is enabled, the font size will follow the size change
			 * of the chemical structure during bond length normalization. If output-scaling is enabled, the font size grows/shrinks with the
			 * size of the chemical structure during viewport size adjustment. The label size specified by this property takes precedence over
			 * the sizes specified by Vis::ControlParameter::ATOM_LABEL_SIZE and Vis::MolecularGraphProperty::ATOM_LABEL_SIZE.
			 *
			 * \valuetype Vis::SizeSpecification
			 */
			extern CDPL_VIS_API const Base::LookupKey LABEL_SIZE;
	
			/**
			 * \brief Specifies the font for text labels that show the value of various atomic properties.
			 *
			 * The font specified by this property takes precedence over the fonts specified by Vis::ControlParameter::SECONDARY_ATOM_LABEL_FONT
			 * and Vis::MolecularGraphProperty::SECONDARY_ATOM_LABEL_FONT.
			 *
			 * \valuetype Vis::Font
			 */
			extern CDPL_VIS_API const Base::LookupKey SECONDARY_LABEL_FONT;

			/**
			 * \brief Specifies the size of text labels that show the value of various atomic properties.
			 *
			 * The size can either be specified as an absolute value or as a scaling factor for the primary label size given by
			 * Vis::AtomProperty::LABEL_SIZE, Vis::MolecularGraphProperty::ATOM_LABEL_SIZE or Vis::ControlParameter::ATOM_LABEL_SIZE. 
			 * If input-scaling is enabled, the size of the font will follow the size change of the chemical structure during bond length
			 * normalization. If output-scaling is enabled, the font size will follow the size change of the chemical structure during
			 * viewport size adjustment. The label size specified by this property takes precedence over the sizes specified by 
			 * Vis::ControlParameter::SECONDARY_ATOM_LABEL_SIZE and Vis::MolecularGraphProperty::SECONDARY_ATOM_LABEL_SIZE.
			 *
			 * \valuetype Vis::SizeSpecification
			 */
			extern CDPL_VIS_API const Base::LookupKey SECONDARY_LABEL_SIZE;
	
			/**
			 * \brief Specifies the margin of free space around atom labels.
			 *
			 * The margin can either be specified as an absolute value or as a scaling factor for the primary label size given by
			 * Vis::AtomProperty::LABEL_SIZE, Vis::MolecularGraphProperty::ATOM_LABEL_SIZE or Vis::ControlParameter::ATOM_LABEL_SIZE.
			 * If input-scaling is enabled, the width of the margin will follow the size change of the chemical structure during
			 * bond length normalization. If output-scaling is enabled, the label margin will follow the size change of the chemical
			 * structure during viewport size adjustment. The margin specified by this property takes precedence over the margins
			 * specified by Vis::ControlParameter::ATOM_LABEL_MARGIN and Vis::MolecularGraphProperty::ATOM_LABEL_MARGIN. 
			 *
			 * \valuetype Vis::SizeSpecification
			 */
			extern CDPL_VIS_API const Base::LookupKey LABEL_MARGIN;
	
			/**
			 * \brief Specifies the size of radical electron dots.
			 *
			 * The dot size can either be specified as an absolute value or as a scaling factor for the primary label size given by
			 * Vis::AtomProperty::LABEL_SIZE, Vis::MolecularGraphProperty::ATOM_LABEL_SIZE or Vis::ControlParameter::ATOM_LABEL_SIZE.
			 * If input-scaling is enabled, the dot diameter will follow the size change of the chemical structure during bond length
			 * normalization. If output-scaling is enabled, the diameter will follow the size change of the chemical structure during
			 * viewport size adjustment. The dot diameter specified by this property takes precedence over the diameters specified by
			 * Vis::ControlParameter::ATOM_LABEL_MARGIN and Vis::MolecularGraphProperty::ATOM_LABEL_MARGIN. 
			 *
			 * \valuetype Vis::SizeSpecification
			 */
			extern CDPL_VIS_API const Base::LookupKey RADICAL_ELECTRON_DOT_SIZE;
		}

		/**
		 * @}
		 */
	}
}

#endif // CDPL_VIS_ATOMPROPERTY_HPP
