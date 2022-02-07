#pragma once

// COMMON HEADER FOR ISOLATED EXECUTABLE
// E.G. TESTS ISOLATED TO THEIR OWN TRANSLATION
// UNIT TO RELAX LINKAGE REQUIREMENTS

// Include utilities from utest
#include "utest.h"
// Track memory allocations
#include "memhook.h"
// Deterministic type generator
#include "typegen.h"
// Include source file
#include "LinkedList.h"
// Include custom insertions
#include "more_assertions.h"

#define TEST(name) UTEST(SORT, name)

// Setup main file
UTEST_MAIN()


