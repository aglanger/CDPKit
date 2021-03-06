/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * Check.hpp 
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
 * \brief Definition of various preprocessor macros for error checking.
 */

#ifndef CDPL_MATH_CHECK_HPP
#define CDPL_MATH_CHECK_HPP

#include <algorithm>

#include "CDPL/Math/Config.hpp"

#ifndef CDPL_MATH_CHECK
#  if (CDPL_MATH_CHECKS_DISABLE == 0)
#    define CDPL_MATH_CHECK(expr, msg, e)	 \
	   if (!(expr)) {						 \
		   throw e(msg);					 \
	   }
#  else // CDPL_MATH_CHECKS_DISABLE != 0
#    define CDPL_MATH_CHECK(expr, msg, e)
#  endif // CDPL_MATH_CHECKS_DISABLE == 0
#endif // CDPL_MATH_CHECK


namespace
{

	template <typename E, typename T>
	T checkSizeEquality(const T& size1, const T& size2)
	{
		CDPL_MATH_CHECK(size1 == size2, "Size mismatch", E);
		return std::min(size1, size2);
	}
}

#define CDPL_MATH_CHECK_SIZE_EQUALITY(size1, size2, e) checkSizeEquality<e>(size1, size2)

#endif // CDPL_MATH_CHECK_HPP
