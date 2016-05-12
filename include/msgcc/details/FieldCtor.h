#ifndef HD2933C2F_F099_4166_A33E_1BE2E4BBF729
#define HD2933C2F_F099_4166_A33E_1BE2E4BBF729

#include <msgcc/details/FieldOpCommon.h>

/////////////////////////////////////////////////
#define FIELD_CTOR(OP) OP##Ctor

/////////////////////////////////////////////////
#define DEF_FIELD_CTOR(OP, CONSTRUCT, ...)  \
template<__VA_ARGS__>                       \
struct FIELD_CTOR(OP)                       \
{                                           \
    DECL_CONSTRUCT()                        \
    {                                       \
        CONSTRUCT;                          \
    }                                       \
};

/////////////////////////////////////////////////
DEF_FIELD_CTOR(Equal,         field = LIMIT,     const U32 LIMIT)
DEF_FIELD_CTOR(UnEqual,       field = LIMIT + 1, const U32 LIMIT)
DEF_FIELD_CTOR(LessThan,      field = LIMIT - 1, const U32 LIMIT)
DEF_FIELD_CTOR(LessOrEqual,   field = LIMIT,     const U32 LIMIT)
DEF_FIELD_CTOR(GreatThan,     field = LIMIT + 1, const U32 LIMIT)
DEF_FIELD_CTOR(GreatOrEqual,  field = LIMIT,     const U32 LIMIT)
DEF_FIELD_CTOR(Omit,          field = LIMIT,     const U32 LIMIT = 0)
DEF_FIELD_CTOR(Between,       field = LOW + 1,   const U32 LOW, const U32 HIGH)
DEF_FIELD_CTOR(CompositeOr,   Ctor1::construct(msg, field), typename Ctor1, typename Ctor2)
DEF_FIELD_CTOR(UserSpecified, SpecifiedCtor::construct(msg, field), typename SpecifiedCtor)

#endif
