# Copyright 2023-present Contributors to the helloWorld project.
# SPDX-License-Identifier: BSD-3-Clause
# https://github.com/mikaelsundell/helloFetch

cmake_minimum_required (VERSION 3.23)

set (project_name "helloFetch")
project ("${project_name} project")

# cmake
list (APPEND CMAKE_MODULE_PATH
      "${PROJECT_SOURCE_DIR}/cmake"
      "${PROJECT_SOURCE_DIR}/cmake/modules")
include (utils)

# configuration
message (STATUS "Configuration")
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Debug")
endif ()
dump_configuration (${project_name})

# helloFetch
set (sources
    helloFetch.cpp
    helloFetch.h
)

add_library (
    helloFetch 
    SHARED
)

target_sources (
    helloFetch 
    PRIVATE ${sources}
)

target_include_directories (
    helloFetch
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

install(
    TARGETS helloFetch
    EXPORT MyLibraryTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)