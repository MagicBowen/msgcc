#ifndef HFC33001A_CA5F_442A_8E49_69371AAF3DF6
#define HFC33001A_CA5F_442A_8E49_69371AAF3DF6

#include <ccinfra/base/BaseTypes.h>

struct SubMsg1
{
    U8  field1;
    U32 field2;
};

struct SubMsg2
{
    U16 field1;
};

struct SimpleMsg
{
    U32 field1;

    U32 subMsg1Present;
    SubMsg1 subMsg1;

    U16 subMsg2Present;
    SubMsg2 subMsg2;
};

struct FixArrayMsg
{
    U32 field[2];

    U8 present;
    SubMsg2 subMsg[2];
};

struct DynArrayMsg
{
    U8   num1;
    U32  fieldArr[3];

    U32 present;
    U16 num2;
    SubMsg2 subMsg2[3];
};

struct OmitMsg
{
    U8 field1;
    U8 field2;
    U8 field3;
};

struct SwitchMsg
{
    U32 enable;
    U8  field1;
    U8  field2;
};

struct MixMsg
{
    U32 present1;
    SwitchMsg sCfg;
    U32 present2;
    SubMsg1 nCfg;
};

struct OrMsg
{
    U32 field;
};

struct SpecialOpMsg
{
    U8  condition;
    U32 field;
};

struct RequestMsg
{
    SubMsg1 subMsg1;
};

struct DynRuleArr
{
    U8 fields[2];
};

#endif
