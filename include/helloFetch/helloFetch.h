// Copyright 2023-present Contributors to the helloWorld project.
// SPDX-License-Identifier: BSD-3-Clause
// https://github.com/mikaelsundell/helloFetch

#pragma once

#include <helloFetch/helloConfig.h>
#include <iostream>

class HELLOFETCH_API helloFetch
{
    public:
        helloFetch();
        virtual ~helloFetch();

        void sayHello();
};
