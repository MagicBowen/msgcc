#ifndef HFC33001A_CA5F_442A_8E49_69371AAF3DF5
#define HFC33001A_CA5F_442A_8E49_69371AAF3DF5

#include "Msgs.h"
#include "ErrorCodeInterpret.h"
#include "WrapperMsgsMeta.h"

#include "ConstrantInterpret.h"
#include "WrapperMsgsMeta.h"

#include "ConstructInterpret.h"
#include "WrapperMsgsMeta.h"

#include "WrapperMsgDef.h"

const U8 ERROR_OFFSET = 1;

__def_default_msg(SimpleMsg, ERROR_OFFSET);
__def_default_msg(FixArrayMsg, ERROR_OFFSET);
__def_default_msg(DynArrayMsg, ERROR_OFFSET);
__def_default_msg(OmitMsg, ERROR_OFFSET);
__def_default_msg(SwitchMsg, ERROR_OFFSET);
__def_default_msg(MixMsg, ERROR_OFFSET);
__def_default_msg(OrMsg, ERROR_OFFSET);
__def_default_msg(SpecialOpMsg, ERROR_OFFSET);
__def_default_msg(RequestMsg, ERROR_OFFSET);
__def_default_msg(DynRuleArr, ERROR_OFFSET);

#endif
