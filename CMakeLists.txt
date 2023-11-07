# Copyright 2023-present Contributors to the helloWorld project.
# SPDX-License-Identifier: BSD-3-Clause
# https://github.com/mikaelsundell/helloFetch

cmake_minimum_required (VERSION 3.22)

project ("helloFetch")
set (soname "10")
set (baseversion "3.0.5")
set (version "${soname}.${baseversion}")

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
dump_configuration (${PROJECT_NAME})

# helloFetch
file(GLOB_RECURSE sources "src/*.cpp")
file(GLOB_RECURSE headers "include/${PROJECT_NAME}/*.h")
set (CMAKE_DEBUG_POSTFIX "_d" )

add_library (
    ${PROJECT_NAME} 
    SHARED
)

target_sources (
    ${PROJECT_NAME} 
    PRIVATE ${sources}
)

# config
target_include_directories (
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_definitions(
    ${PROJECT_NAME}
    PRIVATE 
        HELLOFETCH_EXPORTS
)

set_property(
    TARGET ${PROJECT_NAME} 
    PROPERTY PUBLIC_HEADER ${headers}
)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    SOVERSION ${soname}
    VERSION ${version}
)

# target_link_libraries(
#     helloFetch
#     PUBLIC
#         Library1
#         Library1
#)

# configuration
include(CMakePackageConfigHelpers)

file(
    WRITE 
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake" 
    "# Dummy file"
)

write_basic_package_version_file(
    "${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${version}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION 
        ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

# install
include (GNUInstallDirs)
install (
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    PUBLIC_HEADER
      DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/helloFetch
)

install (
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/helloFetch
)

install(
    EXPORT ${PROJECT_NAME}Targets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    EXPORT_LINK_INTERFACE_LIBRARIES
)