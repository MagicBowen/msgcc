#include "SpecifiedOp.h"
////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(SubMsg1)
    __field(field1, LT(3))
    __field(field2, NE(3))
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(SubMsg2)
    __field(field1, GE(3))
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(SimpleMsg)
    __field(field1, BT(3,5))
    __opt_sub_msg(SubMsg1, subMsg1, subMsg1Present)
    __opt_sub_msg(SubMsg2, subMsg2, subMsg2Present)
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(FixArrayMsg)
    __fix_arr_field(field, 2, BT(3,5))
    __fix_arr_opt_sub_msg(SubMsg2, subMsg, 2, present)
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(DynArrayMsg)
    __field(num1, LE(3))
    __dyn_arr_field(fieldArr, num1, BT(2,4))
    __field(num2, LE(3))
    __dyn_arr_opt_sub_msg(SubMsg2, subMsg2, num2, present)
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(OmitMsg)
    __field(field1, LE(2))
    __field(field2, __())
    __field(field3, LE(2))
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(SwitchMsg)
    __switch_field(enable, LE(1))
    __field(field1, __())
    __field(field2, LE(1))
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(MixMsg)
    __opt_sub_msg(SwitchMsg, sCfg, present1)
    __opt_sub_msg(SubMsg1,   nCfg, present2)
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(OrMsg)
    __field(field,  OR(LE(2), EQ(255)))
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(SpecialOpMsg)
    __field(condition,   GE(10))
    __field(field,  OP(SpecifiedOp))
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(RequestMsg)
    __sub_msg(SubMsg1, subMsg1)
__def_msg_end()

////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
__def_msg_begin(DynRuleArr)
    __field(fields,  OP(SpecifiedOp1))
__def_msg_end()

