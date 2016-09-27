/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * SQLiteScreeningDBAccessor.hpp 
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
 * \brief Definition of the class CDPL::Pharm::SQLiteScreeningDBAccessor.
 */

#ifndef CDPL_PHARM_SQLITESCREENINGDBACCESSOR_HPP
#define CDPL_PHARM_SQLITESCREENINGDBACCESSOR_HPP

#include <memory>

#include "CDPL/Pharm/APIPrefix.hpp"
#include "CDPL/Pharm/ScreeningDBAccessor.hpp"


namespace CDPL 
{

    namespace Pharm
    {
	
	/**
	 * \addtogroup CDPL_PHARM_SCREENING
	 * @{
	 */

	/**
	 * \brief A class for accessing pharmacophore screening databases in the built-in optimized format.
	 */
	class CDPL_PHARM_API SQLiteScreeningDBAccessor : public ScreeningDBAccessor
	{

	  public:
		typedef boost::shared_ptr<SQLiteScreeningDBAccessor> SharedPointer;

	    SQLiteScreeningDBAccessor();

	    /**
	     * \brief Constructs a \c %ScreeningDBAccessor instance that will read data from the 
	     *        database-file specified by \a name.
	     * \param name The name of the database-file.
	     */
	    SQLiteScreeningDBAccessor(const std::string& name);

	    /**
	     * \brief Destructor.
	     */
	    ~SQLiteScreeningDBAccessor();

		void open(const std::string& name);

		void close();

		const std::string& getDatabaseName() const;

		std::size_t getNumMolecules() const;

		std::size_t getNumPharmacophores() const;

		void getMolecule(std::size_t idx, Chem::Molecule& mol) const; 

		void getPharmacophore(std::size_t idx, Pharmacophore& pharm) const; 

		void getPharmacophore(std::size_t mol_idx, std::size_t conf_idx, Pharmacophore& pharm) const; 

		std::size_t findMatchingEntries(const Pharmacophore& pharm);

		std::size_t getNumMatchingEntries();

		std::size_t getMatchingEntryMolIndex(std::size_t idx) const;

		std::size_t getMatchingEntryConfIndex(std::size_t idx) const;

	  private:
	    class Implementation;

	    typedef std::auto_ptr<Implementation> ImplementationPointer;

	    SQLiteScreeningDBAccessor(const SQLiteScreeningDBAccessor&);

	    SQLiteScreeningDBAccessor& operator=(const SQLiteScreeningDBAccessor&);
		
	    ImplementationPointer impl;
	};

	/**
	 * @}
	 */
    }
}

#endif // CDPL_PHARM_SQLITESCREENINGDBACCESSOR_HPP
