﻿// Compiler from Wolfram Language to C++
// 
// Copyright 2019 Tianhuan Lu
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#pragma once

#if defined(_MSC_VER)
#define WL_INLINE __forceinline
#elif defined(__INTEL_COMPILER)
#define WL_INLINE __forceinline
#elif defined(__clang__)
#define WL_INLINE __attribute__((always_inline))
#elif defined(__GNUC__)
#define WL_INLINE __attribute__((always_inline))
#endif

#include "types.h"
#include "ndarray.h"
#include "const.h"
#include "control.h"
#include "clause.h"
#include "arithmetic.h"
#include "complex.h"
#include "mathfunction.h"
#include "numerical.h"
#include "boolean.h"
#include "random.h"
#include "arrayfn.h"
#include "functional.h"

namespace wl
{

}
