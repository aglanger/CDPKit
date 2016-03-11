/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * BasicPharmacophore.hpp 
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
 * \brief Definition of the class CDPL::Chem::BasicPharmacophore.
 */

#ifndef CDPL_CHEM_BASICPHARMACOPHORE_HPP
#define CDPL_CHEM_BASICPHARMACOPHORE_HPP

#include <vector>

#include <boost/iterator/indirect_iterator.hpp>
#include <boost/shared_ptr.hpp>

#include "CDPL/Chem/APIPrefix.hpp"
#include "CDPL/Chem/Pharmacophore.hpp"
#include "CDPL/Chem/BasicPharmacophoreFeature.hpp"


namespace CDPL 
{

    namespace Chem
    {
	
	/**
	 * \addtogroup CDPL_CHEM_PHARMACOPHORE_IMPLEMENTATIONS
	 * @{
	 */

	/**
	 * \brief BasicPharmacophore.
	 */
	class CDPL_CHEM_API BasicPharmacophore : public Pharmacophore
	{

	    typedef std::vector<BasicPharmacophoreFeature*> FeaturePtrList;

	  public:
	    /**	
	     * \brief A reference-counted smart pointer [\ref BSHPTR] for dynamically allocated \c %BasicPharmacophore instances.
	     */
	    typedef boost::shared_ptr<BasicPharmacophore> SharedPointer;
		
	    typedef boost::indirect_iterator<FeaturePtrList::iterator, BasicPharmacophoreFeature> FeatureIterator;
	    typedef boost::indirect_iterator<FeaturePtrList::const_iterator, const BasicPharmacophoreFeature> ConstFeatureIterator;
		
	    /**
	     * \brief Constructs an empty \c %BasicPharmacophore instance.
	     */
	    BasicPharmacophore();
	
	    /**
	     * \brief Constructs a copy of the \c %BasicPharmacophore instance \a pharm.
	     * \param pharm The other \c %BasicPharmacophore instance to copy.
	     */
	    BasicPharmacophore(const BasicPharmacophore& pharm);
	
	    /**
	     * \brief Constructs a copy of the Chem::Pharmacophore instance \a pharm.
	     * \param pharm The other Chem::Pharmacophore instance to copy.
	     */
	    BasicPharmacophore(const Pharmacophore& pharm);
		
	    /**
	     * \brief Destructor.
	     *
	     * Destroys the \c %BasicPharmacophore instance and frees all allocated resources.
	     */
	    ~BasicPharmacophore();
		
	    void clear();
		
	    std::size_t getNumFeatures() const;
		
	    /**
	     * \brief Returns a constant iterator pointing to the beginning of the features.
	     * \return A constant iterator pointing to the beginning of the features.
	     */
	    ConstFeatureIterator getFeaturesBegin() const;

	    /**
	     * \brief Returns a mutable iterator pointing to the beginning of the features.
	     * \return A mutable iterator pointing to the beginning of the features.
	     */
	    FeatureIterator getFeaturesBegin();

	    /**
	     * \brief Returns a constant iterator pointing to the end of the features.
	     * \return A constant iterator pointing to the end of the features.
	     */
	    ConstFeatureIterator getFeaturesEnd() const;

	    /**
	     * \brief Returns a mutable iterator pointing to the end of the features.
	     * \return A mutable iterator pointing to the end of the features.
	     */
	    FeatureIterator getFeaturesEnd();

	    const BasicPharmacophoreFeature& getFeature(std::size_t idx) const;

	    BasicPharmacophoreFeature& getFeature(std::size_t idx);

	    BasicPharmacophoreFeature& addFeature();
		
	    void removeFeature(std::size_t idx);
		
	    /**
	     * \brief Removes the feature specified by the iterator \a it.
	     * \param it An iterator that specifies the feature to remove.
	     * \return A mutable iterator pointing to the next feature in the list.
	     * \throw Base::RangeError if the number of features is zero or \a it is not in the range
	     *        [getFeaturesBegin(), getFeaturesEnd() - 1].
	     */
	    FeatureIterator removeFeature(const FeatureIterator& it);
				
	    bool containsFeature(const PharmacophoreFeature& feature) const;
				
	    std::size_t getFeatureIndex(const PharmacophoreFeature& feature) const;

	    /**
	     * \brief Replaces the current set of features by a copy of the
	     *        features and properties of the pharmacophore \a pharm.
	     *
	     * Internally calls copy() to perform the actual work.
	     *
	     * \param pharm The pharmacophore to copy.
	     * \return A reference to itself.
	     */
	    BasicPharmacophore& operator=(const BasicPharmacophore& pharm);
	
	    using Pharmacophore::operator=;

	    /**
	     * \brief Extends the current set of features by a copy of the features in the
	     *        pharmacophore \a pharm.
	     *
	     * Internally calls append() to perform the actual work.
	     *
	     * \param pharm The pharmacophore providing the features to append.
	     * \return A reference to itself.
	     */
	    BasicPharmacophore& operator+=(const BasicPharmacophore& pharm);

	    using Pharmacophore::operator+=;

	    Pharmacophore::SharedPointer clone() const;
	
	    /**
	     * \brief Replaces the current set of features and properties by a copy of the
	     *        features and properties of the pharmacophore \a pharm.
	     * \param pharm The pharmacophore to copy.
	     */
	    void copy(const BasicPharmacophore& pharm);
	
	    void copy(const Pharmacophore& pharm);
				
	    /**
	     * \brief Extends the current set of features by a copy of the features in the
	     *        pharmacophore \a pharm.
	     * \param pharm The pharmacophore providing the features to append.
	     * \note Does not affect any properties.
	     */
	    void append(const BasicPharmacophore& pharm);

	    void append(const Pharmacophore& pharm);
	
	  private:
	    template <typename T>
		void doCopy(const T& pharm);

	    template <typename T>
		void doAppend(const T& pharm);
			
	    void clearFeatures();

	    void renumberFeatures(std::size_t idx);

	    BasicPharmacophoreFeature* allocFeature();
	    void freeFeature(BasicPharmacophoreFeature* feature);

	    static void destroyFeature(BasicPharmacophoreFeature* feature);
		
	    typedef boost::shared_ptr<BasicPharmacophoreFeature> SharedFeaturePointer;

	    typedef std::vector<SharedFeaturePointer> AllocFeatureList;

	    AllocFeatureList allocFeatures;
	    FeaturePtrList   freeFeatures;
	    FeaturePtrList   features;
	};

	/**
	 * @}
	 */
    }
}

#endif // CDPL_CHEM_BASICPHARMACOPHORE_HPP