#ifndef H474FD28A_3CA7_48B2_8D98_D5100C5138D6
#define H474FD28A_3CA7_48B2_8D98_D5100C5138D6

#include "FieldOpCommon.h"

struct SpecifiedOp
{
    DECL_CHECK()
    {
        return (field == msg.condition) ? 0 : error;
    }

    DECL_CONSTRUCT()
    {
        field = msg.condition;
    }
};

struct SpecifiedOp1
{
    static U32 check(const DynRuleArr& msg, const U8* fields, const U32 error)
    {
        return ((fields[0] < 1) && (fields[1] < 2)) ? 0 : error;
    }

    static void construct(const DynRuleArr& cfg, U8* fields)
    {
        fields[0] = 0;
        fields[1] = 1;
    }
};

#endif
