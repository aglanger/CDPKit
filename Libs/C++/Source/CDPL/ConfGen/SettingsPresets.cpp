/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * SettingsPresets.cpp 
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

 
#include "StaticInit.hpp"

#include "CDPL/ConfGen/FragmentConformerGeneratorSettings.hpp"
#include "CDPL/ConfGen/FragmentAssemblerSettings.hpp"
#include "CDPL/ConfGen/ConformerGeneratorSettings.hpp"
#include "CDPL/ConfGen/StructureGeneratorSettings.hpp"
#include "CDPL/ConfGen/TorsionDriverSettings.hpp"
#include "CDPL/ConfGen/DGStructureGeneratorSettings.hpp"
#include "CDPL/ConfGen/DGConstraintGeneratorSettings.hpp"


using namespace CDPL;


namespace
{

    ConfGen::FragmentConformerGeneratorSettings FRAG_CONF_GEN_FAST;
    ConfGen::FragmentConformerGeneratorSettings FRAG_CONF_GEN_EXHAUSTIVE;

    ConfGen::ConformerGeneratorSettings CONF_GEN_SMALL_SET_DIVERSE;
    ConfGen::ConformerGeneratorSettings CONF_GEN_MEDIUM_SET_DIVERSE;
    ConfGen::ConformerGeneratorSettings CONF_GEN_LARGE_SET_DIVERSE;
    ConfGen::ConformerGeneratorSettings CONF_GEN_SMALL_SET_DENSE;
    ConfGen::ConformerGeneratorSettings CONF_GEN_MEDIUM_SET_DENSE;
    ConfGen::ConformerGeneratorSettings CONF_GEN_LARGE_SET_DENSE;

    struct Init {

		Init() {
			// TODO
		}

    } init;
}


const ConfGen::FragmentConformerGeneratorSettings ConfGen::FragmentConformerGeneratorSettings::FAST       = FRAG_CONF_GEN_FAST;
const ConfGen::FragmentConformerGeneratorSettings ConfGen::FragmentConformerGeneratorSettings::EXHAUSTIVE = FRAG_CONF_GEN_EXHAUSTIVE;
const ConfGen::FragmentConformerGeneratorSettings ConfGen::FragmentConformerGeneratorSettings::DEFAULT    = FRAG_CONF_GEN_EXHAUSTIVE;

const ConfGen::FragmentAssemblerSettings ConfGen::FragmentAssemblerSettings::DEFAULT;

const ConfGen::ConformerGeneratorSettings ConfGen::ConformerGeneratorSettings::SMALL_SET_DIVERSE   = CONF_GEN_SMALL_SET_DIVERSE;
const ConfGen::ConformerGeneratorSettings ConfGen::ConformerGeneratorSettings::MEDIUM_SET_DIVERSE  = CONF_GEN_MEDIUM_SET_DIVERSE;
const ConfGen::ConformerGeneratorSettings ConfGen::ConformerGeneratorSettings::LARGE_SET_DIVERSE   = CONF_GEN_LARGE_SET_DIVERSE;
const ConfGen::ConformerGeneratorSettings ConfGen::ConformerGeneratorSettings::SMALL_SET_DENSE     = CONF_GEN_SMALL_SET_DENSE;
const ConfGen::ConformerGeneratorSettings ConfGen::ConformerGeneratorSettings::MEDIUM_SET_DENSE    = CONF_GEN_MEDIUM_SET_DENSE;
const ConfGen::ConformerGeneratorSettings ConfGen::ConformerGeneratorSettings::LARGE_SET_DENSE     = CONF_GEN_LARGE_SET_DENSE;
const ConfGen::ConformerGeneratorSettings ConfGen::ConformerGeneratorSettings::DEFAULT             = CONF_GEN_MEDIUM_SET_DIVERSE;

const ConfGen::StructureGeneratorSettings ConfGen::StructureGeneratorSettings::DEFAULT;

const ConfGen::TorsionDriverSettings ConfGen::TorsionDriverSettings::DEFAULT;

const ConfGen::DGStructureGeneratorSettings ConfGen::DGStructureGeneratorSettings::DEFAULT;

const ConfGen::DGConstraintGeneratorSettings ConfGen::DGConstraintGeneratorSettings::DEFAULT;