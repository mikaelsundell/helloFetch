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
file(GLOB_RECURSE sources "src/*.cpp")
file(GLOB_RECURSE headers "include/helloFetch/*.h")
set (CMAKE_DEBUG_POSTFIX "_debug" )

add_library (
    helloFetch 
    SHARED
)

target_sources (
    helloFetch 
    PRIVATE ${sources}
)

# config
target_include_directories (
    helloFetch
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_definitions(
    helloFetch
    PRIVATE 
        HELLOFETCH_EXPORTS
)

set_property(
    TARGET helloFetch 
    PROPERTY PUBLIC_HEADER ${headers}
)

# target_link_libraries(
#     helloFetch
#     PUBLIC
#         Library1
#         Library1
#)

# install
include(GNUInstallDirs)
install(
    TARGETS helloFetch
    EXPORT helloFetchTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    PUBLIC_HEADER
      DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/helloFetch
)