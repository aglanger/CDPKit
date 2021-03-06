/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * UtilityFunctionsTest.cpp 
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

#include <boost/test/auto_unit_test.hpp>

#include "CDPL/Chem/UtilityFunctions.hpp"


BOOST_AUTO_TEST_CASE(UtilityFoldBitSetFunctionTest)
{
	using namespace CDPL;
	using namespace Util;
	using namespace Chem;

	BitSet bs1(std::string("101010101010101010101010"));
	std::string bs_string;

	foldBitSet(bs1, 0);
	to_string(bs1, bs_string);
	BOOST_CHECK(bs_string == "101010101010101010101010");

	foldBitSet(bs1, 1);
	to_string(bs1, bs_string);
	BOOST_CHECK(bs_string == "101010101010");

	foldBitSet(bs1, 1);
	to_string(bs1, bs_string);
	BOOST_CHECK(bs_string == "101010");

	BitSet bs2(std::string("101010101010010101010101"));

	foldBitSet(bs2, 0);
	to_string(bs2, bs_string);
	BOOST_CHECK(bs_string == "101010101010010101010101");

	foldBitSet(bs2, 1);
	to_string(bs2, bs_string);
	BOOST_CHECK(bs_string == "111111111111");

	foldBitSet(bs2, 1);
	to_string(bs2, bs_string);
	BOOST_CHECK(bs_string == "111111");

	BitSet bs3(std::string("010101010101010101010"));

	foldBitSet(bs3, 0);
	to_string(bs3, bs_string);
	BOOST_CHECK(bs_string == "010101010101010101010");

	foldBitSet(bs3, 1);
	to_string(bs3, bs_string);
	BOOST_CHECK(bs_string == "1010101010");

	foldBitSet(bs3, 1);
	to_string(bs3, bs_string);
	BOOST_CHECK(bs_string == "11111");

	BitSet bs4(std::string("111111111100000000000000"));	

	foldBitSet(bs4, 2);
	to_string(bs4, bs_string);
	BOOST_CHECK(bs_string == "111111");

	foldBitSet(bs4, 0);
	to_string(bs4, bs_string);
	BOOST_CHECK(bs_string == "111111");

	foldBitSet(bs4, 1);
	to_string(bs4, bs_string);
	BOOST_CHECK(bs_string == "111");

	foldBitSet(bs4, 1);
	to_string(bs4, bs_string);
	BOOST_CHECK(bs_string == "1");

	foldBitSet(bs4, 1);
	to_string(bs4, bs_string);
	BOOST_CHECK(bs_string == "");

	BitSet bs5;	

	foldBitSet(bs5, 0);
	to_string(bs5, bs_string);
	BOOST_CHECK(bs_string == "");

	foldBitSet(bs5, 1);
	to_string(bs5, bs_string);
	BOOST_CHECK(bs_string == "");

	foldBitSet(bs5, 50);
	to_string(bs5, bs_string);
	BOOST_CHECK(bs_string == "");

	BitSet bs6(std::string("000000000000000000000000"));

	foldBitSet(bs6, 0);
	to_string(bs6, bs_string);
	BOOST_CHECK(bs_string == "000000000000000000000000");

	foldBitSet(bs6, 1);
	to_string(bs6, bs_string);
	BOOST_CHECK(bs_string == "000000000000");

	foldBitSet(bs6, 2);
	to_string(bs6, bs_string);
	BOOST_CHECK(bs_string == "000");
}
