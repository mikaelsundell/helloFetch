// Copyright 2023-present Contributors to the helloWorld project.
// SPDX-License-Identifier: BSD-3-Clause
// https://github.com/mikaelsundell/helloFetch

#pragma once

#if defined(_WIN32)
    #if defined(HELLOFETCH_EXPORTS)
        #define HELLOFETCH_EXPORT __declspec(dllexport)
        #define HELLOFETCH_EXPORT extern __declspec(dllexport)
    #else
        #define HELLOFETCH_EXPORT __declspec(dllimport)
        #define HELLOFETCH_EXPORT extern __declspec(dllimport)
    #endif
#else
    #define HELLOFETCH_EXPORT
    #define HELLOFETCH_EXPORT_CONST extern
#endif




