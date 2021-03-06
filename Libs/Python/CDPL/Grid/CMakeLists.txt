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

IF(NUMPY_FOUND)
  INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}" "${NUMPY_INCLUDE_DIRS}")
ELSE(NUMPY_FOUND)
  INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}")
ENDIF(NUMPY_FOUND)

FILE(GLOB PYTHON_FILES "*.py")

FOREACH(PYTHON_FILE ${PYTHON_FILES})
  CONFIGURE_FILE("${PYTHON_FILE}" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
ENDFOREACH(PYTHON_FILE)

SET(grid_MOD_SRCS
    Module.cpp
    AttributedGridExport.cpp
    SpatialGridExport.cpp
    RegularGridExport.cpp
    RegularGridSetExport.cpp

    AttributedGridPropertyExport.cpp 
    AttributedGridPropertyDefaultExport.cpp 
    ControlParameterExport.cpp 
    ControlParameterDefaultExport.cpp 
    DataFormatExport.cpp 

    RegularGridInputHandlerExport.cpp
    RegularGridOutputHandlerExport.cpp
    RegularGridSetInputHandlerExport.cpp
    RegularGridSetOutputHandlerExport.cpp

    RegularGridIOManagerExport.cpp
    RegularGridSetIOManagerExport.cpp

    RegularGridReaderExport.cpp
    RegularGridWriterExport.cpp
    RegularGridSetReaderExport.cpp
    RegularGridSetWriterExport.cpp

    CDFRegularGridInputHandlerExport.cpp
    CDFRegularGridOutputHandlerExport.cpp
    CDFRegularGridSetInputHandlerExport.cpp
    CDFRegularGridSetOutputHandlerExport.cpp

    CDFRegularGridReaderExport.cpp
    CDFRegularGridWriterExport.cpp
    CDFRegularGridSetReaderExport.cpp
    CDFRegularGridSetWriterExport.cpp

    AttributedGridFunctionExport.cpp 
    ControlParameterFunctionExport.cpp 

    ToPythonConverterRegistration.cpp
    FromPythonConverterRegistration.cpp
   )

IF(NUMPY_FOUND)
  SET(grid_MOD_SRCS
      ${grid_MOD_SRCS}
      ../Math/NumPy.cpp
     )
ENDIF(NUMPY_FOUND)

ADD_LIBRARY(_grid MODULE ${grid_MOD_SRCS})

TARGET_LINK_LIBRARIES(_grid cdpl-grid-shared ${Boost_PYTHON_LIBRARY} ${PYTHON_LIBRARIES})

SET_TARGET_PROPERTIES(_grid PROPERTIES PREFIX "")

IF(WIN32)
  SET_TARGET_PROPERTIES(_grid PROPERTIES SUFFIX ".pyd")
  SET(BINARY_INPUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/_grid.pyd")
ELSE(WIN32)
  SET_TARGET_PROPERTIES(_grid PROPERTIES COMPILE_DEFINITIONS "BOOST_PYTHON_USE_GCC_SYMBOL_VISIBILITY")

  IF(NOT APPLE)
    SET_TARGET_PROPERTIES(_grid PROPERTIES INSTALL_RPATH "${CDPKIT_PYTHON_MODULE_INSTALL_RPATH2}")
    SET(BINARY_INPUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/_grid.so")
  ELSE(NOT APPLE)
    SET_TARGET_PROPERTIES(_grid PROPERTIES LINK_FLAGS "-Wl,-rpath,\"${CDPKIT_PYTHON_MODULE_INSTALL_RPATH2}\"")
  ENDIF(NOT APPLE)
ENDIF(WIN32)

IF(NOT APPLE)
  CONFIGURE_FILE("${CDPKIT_CMAKE_SCRIPTS_DIR}/InstallExternalRuntimeDependencies.cmake.in" 
    "${CMAKE_CURRENT_BINARY_DIR}/InstallExternalRuntimeDependencies.cmake" 
    @ONLY
    )
  INSTALL(SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/InstallExternalRuntimeDependencies.cmake" COMPONENT CDPLPythonModules)
ENDIF(NOT APPLE)

INSTALL(FILES ${PYTHON_FILES} DESTINATION "${CDPKIT_PYTHON_INSTALL_DIR}/CDPL/Grid" COMPONENT CDPLPythonModules)
INSTALL(TARGETS _grid DESTINATION "${CDPKIT_PYTHON_INSTALL_DIR}/CDPL/Grid" COMPONENT CDPLPythonModules)

IF(PYTHONINTERP_FOUND)
  ADD_SUBDIRECTORY(Tests)
ENDIF(PYTHONINTERP_FOUND)
