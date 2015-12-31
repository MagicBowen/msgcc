#ifndef HD5DA4832_65CF_4D0F_BABC_D24E856E3B08
#define HD5DA4832_65CF_4D0F_BABC_D24E856E3B08

#include "base/BaseTypes.h"

////////////////////////////////////////////////////////////
#define DECL_CHECK()                \
template<typename MSG, typename T> static U32 check(const MSG& msg, const T field, const U32 error)

////////////////////////////////////////////////////////////
#define DECL_CONSTRUCT()            \
template<typename MSG, typename T> static void construct(const MSG& msg, T& field)

#endif
