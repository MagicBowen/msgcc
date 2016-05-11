#ifndef H463C8A80_396E_4096_958B_C31C6CF4A71B
#define H463C8A80_396E_4096_958B_C31C6CF4A71B

#include <msgcc/FieldOpCommon.h>

/////////////////////////////////////////////////////////
#define FIELD_CHECKER(OP) OP##Checker

/////////////////////////////////////////////////////////
#define DEF_FIELD_CHECKER(OP, CONDITION, ...)           \
template<__VA_ARGS__>                                   \
struct FIELD_CHECKER(OP)                                \
{                                                       \
    DECL_CHECK()                                        \
    {                                                   \
        return (CONDITION) ?  0 : error;                \
    }                                                   \
};

/////////////////////////////////////////////////////////
DEF_FIELD_CHECKER(Equal,         field == LIMIT, const U32 LIMIT)
DEF_FIELD_CHECKER(UnEqual,       field != LIMIT, const U32 LIMIT)
DEF_FIELD_CHECKER(LessThan,      field <  LIMIT, const U32 LIMIT)
DEF_FIELD_CHECKER(LessOrEqual,   field <= LIMIT, const U32 LIMIT)
DEF_FIELD_CHECKER(GreatThan,     field >  LIMIT, const U32 LIMIT)
DEF_FIELD_CHECKER(GreatOrEqual,  field >= LIMIT, const U32 LIMIT)
DEF_FIELD_CHECKER(Omit,          field == field, const U32 LIMIT = 0)
DEF_FIELD_CHECKER(Between,       (LOW <= field) && (field <= HIGH), const U32 LOW, const U32 HIGH)
DEF_FIELD_CHECKER(CompositeOr,   (0 == Checker1::check(msg, field, error))||(0 == Checker2::check(msg, field, error)), typename Checker1, typename Checker2)
DEF_FIELD_CHECKER(UserSpecified, (0 == SpecifiedChecker::check(msg, field, error)), typename SpecifiedChecker)

#endif
