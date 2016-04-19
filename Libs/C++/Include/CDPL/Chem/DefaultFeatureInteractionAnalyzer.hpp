/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * DefaultFeatureInteractionAnalyzer.hpp 
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
 * \brief Definition of the class CDPL::Chem::DefaultFeatureInteractionAnalyzer.
 */

#ifndef CDPL_CHEM_DEFAULTFEATUREINTERACTIONANALYZER_HPP
#define CDPL_CHEM_DEFAULTFEATUREINTERACTIONANALYZER_HPP

#include "CDPL/Chem/APIPrefix.hpp"
#include "CDPL/Chem/FeatureInteractionAnalyzer.hpp"


namespace CDPL 
{

    namespace Chem
    {

	/**
	 * \addtogroup CDPL_CHEM_FEATUREINTERACTION_PERCEPTION
	 * @{
	 */

	/**
	 * \brief DefaultFeatureInteractionAnalyzer.
	 */
	class CDPL_CHEM_API DefaultFeatureInteractionAnalyzer : public FeatureInteractionAnalyzer
	{

	  public:
	    /**
	     * \brief Constructs the \c %DefaultFeatureInteractionAnalyzer instance.
	     */
	    DefaultFeatureInteractionAnalyzer();

	    DefaultFeatureInteractionAnalyzer(const Pharmacophore& pharm1, const Pharmacophore& pharm2, FeatureMapping& interactions);

	  private:
	    /** \cond CDPL_PRIVATE_SECTION_DOC */
	
	    void init();
	
	    /** \endcond */
	};

	/**
	 * @}
	 */
    }
}

#endif // CDPL_CHEM_DEFAULTFEATUREINTERACTIONANALYZER_HPP