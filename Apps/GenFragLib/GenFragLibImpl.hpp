/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * GenFragLibImpl.hpp
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


#ifndef GENFRAGLIB_GENFRAGLIBIMPL_HPP
#define GENFRAGLIB_GENFRAGLIBIMPL_HPP

#include <cstddef>
#include <vector>
#include <string>

#include <boost/thread.hpp>
#include <boost/chrono/chrono.hpp>

#include "CDPL/ConfGen/FragmentLibrary.hpp"
#include "CDPL/Util/CompoundDataReader.hpp"
#include "CDPL/Base/DataInputHandler.hpp"

#include "Lib/CmdLineBase.hpp"


namespace CDPL
{

	namespace Chem
	{

		class Molecule;
	}
}


namespace GenFragLib
{

    class GenFragLibImpl : public AppUtils::CmdLineBase
    {

    public:
		GenFragLibImpl();

    private:
		enum Mode 
		{

		  CREATE,
		  UPDATE
		};

		typedef CDPL::Base::DataInputHandler<CDPL::Chem::Molecule> InputHandler;
		typedef InputHandler::SharedPointer InputHandlerPtr;

		const char* getProgName() const;
		const char* getProgCopyright() const;
		const char* getProgAboutText() const;

		void setRMSD(double rmsd);
		void setEnergyWindow(double ewin);
		void setConfGenTrialFactor(std::size_t factor);
		void setForceFieldType(const std::string& type_str);
		void setMode(const std::string& mode_str);
		void setInputFormat(const std::string& file_ext);
		void setMaxNumThreads(unsigned int num_threads);

		int process();

		void processSingleThreaded();
		void processMultiThreaded();

		void loadFragmentLibrary();
		int saveFragmentLibrary();

		bool readNextMolecule(CDPL::Chem::Molecule& mol);
		bool doReadNextMolecule(CDPL::Chem::Molecule& mol);

		void setErrorMessage(const std::string& msg);
		bool haveErrorMessage();

		void printMessage(VerbosityLevel level, const std::string& msg, bool nl = true, bool file_only = false);

		void printStatistics(std::size_t num_proc_mols, std::size_t num_proc_frags, 
							 std::size_t num_added_frags, std::size_t num_gen_confs,
							 std::size_t proc_time);

		void checkInputFiles() const;
		void printOptionSummary();
		void initInputReader();

		std::string getModeString() const;
		std::string getForceFieldTypeString() const;

		InputHandlerPtr getInputHandler(const std::string& file_path) const;

		void addOptionLongDescriptions();

		class InputScanProgressCallback;
		class FragLibGenerationWorker;

		typedef std::vector<std::string> StringList;
		typedef CDPL::Base::DataReader<CDPL::Chem::Molecule> MoleculeReader;
		typedef CDPL::Util::CompoundDataReader<CDPL::Chem::Molecule> CompMoleculeReader;
		typedef boost::chrono::system_clock Clock;
		typedef CDPL::ConfGen::FragmentLibrary FragmentLibrary;

		StringList                     inputFiles;
		std::string                    outputFile;
		bool                           multiThreading;
		std::size_t                    numThreads;
		Mode                           mode;
		double                         minRMSD;
		std::size_t                    timeout;
		double                         eWindow;
		std::size_t                    confGenTrialFactor;
		unsigned int                   forceFieldType;
		bool                           useInputCoords;
		InputHandlerPtr                inputHandler;
		CompMoleculeReader             inputReader;
		FragmentLibrary::SharedPointer fragmentLibPtr;
		boost::mutex                   mutex;
		std::string                    errorMessage;
		Clock::time_point              startTime;
    };
}

#endif // GENFRAGLIB_GENFRAGLIBIMPL_HPP