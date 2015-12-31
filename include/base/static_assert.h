#ifndef INCL_static_assert_2013725105338_H
#define INCL_static_assert_2013725105338_H

#include "base/Config.h"

#if __SUPPORT_STATIC_ASSERT
# define STATIC_ASSERT(expr) static_assert(expr, #expr)
#else
# define STATIC_ASSERT(expr) do {               \
    enum { static_assert_failure = 1/(expr) };  \
} while(0)
#endif

#endif
