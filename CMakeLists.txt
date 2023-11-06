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

add_library(${project_name} SHARED ${sources})
set_property(TARGET ${project_name} PROPERTY CXX_STANDARD 17)