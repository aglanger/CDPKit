/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * AttributedGrid.hpp 
 *
 * Copyright (C) 2010-2011 Thomas A. Seidel <thomas.seidel@univie.ac.at>
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
 * \brief Definition of a  grid data type.
 */

#ifndef CDPL_GRID_ATTRIBUTEDGRID_HPP
#define CDPL_GRID_ATTRIBUTEDGRID_HPP

#include <cstddef>

#include <boost/shared_ptr.hpp>

#include "CDPL/Base/PropertyContainer.hpp"


namespace CDPL
{

	namespace Grid
	{

		/**
		 * \addtogroup CDPL_GRID_INTERFACES
		 * @{
		 */

		/**
		 * \brief AttributedGrid.
		 */
		class AttributedGrid : public Base::PropertyContainer
		{

		public:
			typedef boost::shared_ptr<AttributedGrid> SharedPointer;
		
			virtual ~AttributedGrid() {}

			virtual std::size_t getNumElements() const = 0;

			virtual bool isEmpty() const = 0;

		protected:
			AttributedGrid& operator=(const AttributedGrid& grid) {
				Base::PropertyContainer::operator=(grid);
				return *this;
			}
		};

		/**
		 * @}
		 */
	}
}

#endif // CDPL_GRID_ATTRIBUTEDGRID_HPP
