/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * AromaticSSSRSubset.hpp 
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
 * \brief Definition of the class CDPL::Chem::AromaticSSSRSubset.
 */

#ifndef CDPL_CHEM_AROMATICSSSRSUBSET_HPP
#define CDPL_CHEM_AROMATICSSSRSUBSET_HPP

#include <boost/shared_ptr.hpp>

#include "CDPL/Chem/APIPrefix.hpp"
#include "CDPL/Chem/FragmentList.hpp"
#include "CDPL/Util/BitSet.hpp"


namespace CDPL 
{

    namespace Chem
    {

	/**
	 * \addtogroup CDPL_CHEM_AROMATICITY
	 * @{
	 */

	class MolecularGraph;

	/**
	 * \brief Implements the extraction of the aromatic rings in the SSSR of a molecular graph.
	 */
	class CDPL_CHEM_API AromaticSSSRSubset : public FragmentList 
	{

	  public:
	    /**	
	     * \brief A reference-counted smart pointer [\ref BSHPTR] for dynamically allocated \c %AromaticSSSRSubset instances.
	     */
	    typedef boost::shared_ptr<AromaticSSSRSubset> SharedPointer;

	    /**
	     * \brief Constructs an empty \c %AromaticSSSRSubset instance.
	     */
	    AromaticSSSRSubset() {}

	    /**
	     * \brief Construct a \c %AromaticSSSRSubset instance that contains all aromatic rings of the
	     *        SSSR of the molecular graph \a molgraph.
	     * \param molgraph The molecular graph for which to extract the aromatic rings.
	     */
	    AromaticSSSRSubset(const MolecularGraph& molgraph);

	    /**
	     * \brief Replaces the current set of rings by the aromatic rings in the SSSR of the molecular graph \a molgraph.
	     * \param molgraph The molecular graph for which to extract the aromatic rings.
	     */
	    void extract(const MolecularGraph& molgraph);

	  private:
	    AromaticSSSRSubset(const AromaticSSSRSubset&);

	    AromaticSSSRSubset& operator=(const AromaticSSSRSubset&);

	    void init(const MolecularGraph&);
	    void findAromaticRings();
		
	    Util::BitSet          aromBondMask;
	    const MolecularGraph* molGraph;
	};

	/**
	 * @}
	 */
    }
}

#endif // CDPL_CHEM_AROMATICSSSRSUBSET_HPP
