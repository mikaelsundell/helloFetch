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

# config
add_library(helloFetchConfig INTERFACE)

target_include_directories(
    helloFetchConfig INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_include_directories (
    helloFetch
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

install(
    TARGETS helloFetch
    EXPORT "helloFetch"
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)