# -*- mode: CMake -*-

##
# CMakeLists.txt  
#
# This file is part of the Chemical Data Processing Toolkit
#
# Copyright (C) 2003-2020 Thomas A. Seidel <thomas.seidel@univie.ac.at>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program; see the file COPYING. If not, write to
# the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.
##

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}")

FILE(GLOB PYTHON_FILES "*.py")

FOREACH(PYTHON_FILE ${PYTHON_FILES})
  CONFIGURE_FILE("${PYTHON_FILE}" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
ENDFOREACH(PYTHON_FILE)

SET(pharm_MOD_SRCS
    Module.cpp
    FeatureExport.cpp
    BasicFeatureExport.cpp
    FeatureContainerExport.cpp
    FeatureSetExport.cpp
    PharmacophoreExport.cpp
    BasicPharmacophoreExport.cpp

    FeatureMappingExport.cpp 
    FeatureTypeHistogramExport.cpp 
    FeatureRDFCodeCalculatorExport.cpp 
    PharmacophoreRDFDescriptorCalculatorExport.cpp
    FeatureAutoCorrelation3DVectorCalculatorExport.cpp 
    PharmacophoreAutoCorr3DDescriptorCalculatorExport.cpp

    FeatureContainerIOManagerExport.cpp 
    PharmacophoreIOManagerExport.cpp 
    PharmacophoreReaderExport.cpp 
    FeatureContainerWriterExport.cpp 
    PharmacophoreInputHandlerExport.cpp 
    FeatureContainerOutputHandlerExport.cpp 
 
    CDFPharmacophoreInputHandlerExport.cpp 
    CDFFeatureContainerOutputHandlerExport.cpp 
    CDFPharmacophoreReaderExport.cpp 
    CDFFeatureContainerWriterExport.cpp
   
    PMLPharmacophoreInputHandlerExport.cpp 
    PMLFeatureContainerOutputHandlerExport.cpp 
    PMLPharmacophoreReaderExport.cpp 
    PMLFeatureContainerWriterExport.cpp

    PharmacophoreFitScoreExport.cpp

    ScreeningDBCreatorExport.cpp
    ScreeningDBAccessorExport.cpp
    ScreeningProcessorExport.cpp
    PharmacophoreFitScreeningScoreExport.cpp

    BoostFunctionWrapperExport.cpp

    FeatureGeneratorExport.cpp
    PharmacophoreGeneratorExport.cpp
    DefaultPharmacophoreGeneratorExport.cpp
    PatternBasedFeatureGeneratorExport.cpp
    AromaticFeatureGeneratorExport.cpp
    HydrophobicFeatureGeneratorExport.cpp
    HydrophobicAtomFeatureGeneratorExport.cpp
    HBondAcceptorFeatureGeneratorExport.cpp
    HBondDonorFeatureGeneratorExport.cpp
    PosIonizableFeatureGeneratorExport.cpp
    NegIonizableFeatureGeneratorExport.cpp
    InteractionAnalyzerExport.cpp
    DefaultInteractionAnalyzerExport.cpp
    InteractionConstraintConnectorExport.cpp
    FeatureDistanceConstraintExport.cpp
    HydrophobicInteractionConstraintExport.cpp
    IonicInteractionConstraintExport.cpp
    OrthogonalPiPiInteractionConstraintExport.cpp
    ParallelPiPiInteractionConstraintExport.cpp
    CationPiInteractionConstraintExport.cpp
    HBondingInteractionConstraintExport.cpp
    InteractionPharmacophoreGeneratorExport.cpp

    InteractionScoreCombinerExport.cpp
    FeatureDistanceScoreExport.cpp
    HydrophobicInteractionScoreExport.cpp
    IonicInteractionScoreExport.cpp
    OrthogonalPiPiInteractionScoreExport.cpp
    ParallelPiPiInteractionScoreExport.cpp
    CationPiInteractionScoreExport.cpp
    HBondingInteractionScoreExport.cpp
    InteractionScoreGridCalculatorExport.cpp
    InteractionScoreGridSetCalculatorExport.cpp
    DefaultInteractionScoreGridSetCalculatorExport.cpp

    FeatureTypeMatchFunctorExport.cpp
    FeaturePairDistanceMatchFunctorExport.cpp
    TopologicalEntityAlignmentExport.cpp	
    PharmacophoreAlignmentExport.cpp
    GeometricalFeatureMappingExtractorExport.cpp
    FeaturePositionMatchFunctorExport.cpp
    FeatureGeometryMatchFunctorExport.cpp
    
    AttributedGridPropertyExport.cpp 
    AttributedGridPropertyDefaultExport.cpp 

    FeatureContainerPropertyExport.cpp 
    FeaturePropertyExport.cpp 
    FeatureContainerPropertyDefaultExport.cpp 
    FeaturePropertyDefaultExport.cpp 
    DataFormatExport.cpp 
    FeatureTypeExport.cpp 
    FeatureGeometryExport.cpp 
    ControlParameterExport.cpp 
    ControlParameterDefaultExport.cpp 

    PharmacophoreFunctionExport.cpp 
    FeatureFunctionExport.cpp 
    FeatureContainerFunctionExport.cpp 
    FeatureSetFunctionExport.cpp 
    AttributedGridFunctionExport.cpp 
    ControlParameterFunctionExport.cpp 
    MoleculeFunctionExport.cpp 

    ToPythonConverterRegistration.cpp
    FromPythonConverterRegistration.cpp
   )

IF(Boost_FILESYSTEM_FOUND)
  SET(pharm_MOD_SRCS
      ${pharm_MOD_SRCS}
      FileScreeningHitCollectorExport.cpp
     )	
ENDIF(Boost_FILESYSTEM_FOUND)

IF(SQLITE3_FOUND)
  SET(pharm_MOD_SRCS
      ${pharm_MOD_SRCS}
      PSDScreeningDBCreatorExport.cpp
      PSDScreeningDBAccessorExport.cpp
     )	
  IF(Boost_FILESYSTEM_FOUND AND Boost_IOSTREAMS_FOUND)
    SET(pharm_MOD_SRCS
        ${pharm_MOD_SRCS}
        PSDPharmacophoreInputHandlerExport.cpp 
        PSDMoleculeInputHandlerExport.cpp 
        PSDMolecularGraphOutputHandlerExport.cpp 

        PSDPharmacophoreReaderExport.cpp 
        PSDMoleculeReaderExport.cpp 
        PSDMolecularGraphWriterExport.cpp
       )	
  ENDIF(Boost_FILESYSTEM_FOUND AND Boost_IOSTREAMS_FOUND)
ENDIF(SQLITE3_FOUND)

ADD_LIBRARY(_pharm MODULE ${pharm_MOD_SRCS})

TARGET_LINK_LIBRARIES(_pharm cdpl-pharm-shared ${Boost_PYTHON_LIBRARY} ${PYTHON_LIBRARIES})

SET_TARGET_PROPERTIES(_pharm PROPERTIES PREFIX "")

IF(WIN32)
  SET_TARGET_PROPERTIES(_pharm PROPERTIES SUFFIX ".pyd")
  SET(BINARY_INPUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/_pharm.pyd")
ELSE(WIN32)
  SET_TARGET_PROPERTIES(_pharm PROPERTIES COMPILE_DEFINITIONS "BOOST_PYTHON_USE_GCC_SYMBOL_VISIBILITY")

  IF(NOT APPLE)
    SET_TARGET_PROPERTIES(_pharm PROPERTIES INSTALL_RPATH "${CDPKIT_PYTHON_MODULE_INSTALL_RPATH2}")
    SET(BINARY_INPUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/_pharm.so")
  ELSE(NOT APPLE)
    SET_TARGET_PROPERTIES(_pharm PROPERTIES LINK_FLAGS "-Wl,-rpath,\"${CDPKIT_PYTHON_MODULE_INSTALL_RPATH2}\"")
  ENDIF(NOT APPLE)
ENDIF(WIN32)

IF(NOT APPLE)
  CONFIGURE_FILE("${CDPKIT_CMAKE_SCRIPTS_DIR}/InstallExternalRuntimeDependencies.cmake.in" 
    "${CMAKE_CURRENT_BINARY_DIR}/InstallExternalRuntimeDependencies.cmake" 
    @ONLY
    )
  INSTALL(SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/InstallExternalRuntimeDependencies.cmake" COMPONENT CDPLPythonModules)
ENDIF(NOT APPLE)

INSTALL(FILES ${PYTHON_FILES} DESTINATION "${CDPKIT_PYTHON_INSTALL_DIR}/CDPL/Pharm" COMPONENT CDPLPythonModules)
INSTALL(TARGETS _pharm DESTINATION "${CDPKIT_PYTHON_INSTALL_DIR}/CDPL/Pharm" COMPONENT CDPLPythonModules)

IF(PYTHONINTERP_FOUND)
  ADD_SUBDIRECTORY(Tests)
ENDIF(PYTHONINTERP_FOUND)
