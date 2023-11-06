// Copyright 2023-present Contributors to the helloWorld project.
// SPDX-License-Identifier: BSD-3-Clause
// https://github.com/mikaelsundell/helloFetch

#pragma once

#if defined(_WIN32)
#   define HELLOCONFIG_IMPORT __declspec(dllimport)
#   define HELLOCONFIG_EXPORT __declspec(dllexport)
#else
#   define HELLOCONFIG_IMPORT __attribute__((visibility("default")))
#   define HELLOCONFIG_EXPORT __attribute__((visibility("default")))
#endif

#if defined(HELLOFETCH_EXPORTS)
#    define HELLOFETCH_API HELLOCONFIG_EXPORT
#else
#    define HELLOFETCH_API HELLOCONFIG_IMPORT
#endif
