/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * DataInputHandler.hpp 
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
 * \brief Definition of the class CDPL::Base::DataInputHandler.
 */

#ifndef CDPL_BASE_DATAINPUTHANDLER_HPP
#define CDPL_BASE_DATAINPUTHANDLER_HPP

#include <ios>
#include <string>

#include <boost/shared_ptr.hpp>

#include "CDPL/Base/DataReader.hpp"


namespace CDPL 
{

	namespace Base
	{

		class DataFormat;
	
		/**
		 * \addtogroup CDPL_BASE_IO
		 * @{
		 */

		/**
		 * \brief A factory interface providing methods for the creation of Base::DataReader instances handling a particular
		 *        object type and storage format.
		 * \tparam T The type of objects handled by the created Base::DataReader instances.
		 */
		template <typename T>
		class DataInputHandler 
		{

		public:
			typedef DataReader<T> ReaderType;

			typedef boost::shared_ptr<DataInputHandler> SharedPointer;

			/**
			 * \brief Virtual destructor.
			 */
			virtual ~DataInputHandler() {}

			/**
			 * \brief Returns a Base::DataFormat object that provides information about the handled input data format.
			 * \return A Base::DataFormat object that provides information about the handled data format.
			 */
			virtual const DataFormat& getDataFormat() const = 0;

			/**
			 * \brief Creates a Base::DataReader instance that will read the data from the input stream \a is.
			 * \param is The input stream to read from.
			 * \return A shared pointer to the created Base::DataReader instance.
			 */
			virtual typename ReaderType::SharedPointer createReader(std::istream& is) const = 0;

			/**
			 * \brief Creates a Base::DataReader instance that will read the data from the file \a file_name.
			 * \param file_name The name of the file to read from.
			 * \param mode Flags specifying the file open-mode.
			 * \return A shared pointer to the created Base::DataReader instance.
			 */
			virtual typename ReaderType::SharedPointer createReader(const std::string& file_name, 
																	std::ios_base::openmode mode = std::ios_base::in | std::ios_base::binary) const = 0;
		};

		/**
		 * @}
		 */
	}
}

#endif // CDPL_BASE_DATAINPUTHANDLER_HPP
