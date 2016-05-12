#ifndef HFC33001A_CA5F_442A_8E49_69371AAF3DF5
#define HFC33001A_CA5F_442A_8E49_69371AAF3DF5

#include "Msgs.h"
#include <msgcc/ErrorCodeInterpret.h>
#include "WrapperMsgsMeta.h"

#include <msgcc/ConstrantInterpret.h>
#include "WrapperMsgsMeta.h"

#include <msgcc/ConstructInterpret.h>
#include "WrapperMsgsMeta.h"

#include <msgcc/Msgcc.h>

const U8 ERROR_OFFSET = 1;

__msgcc_implement(SimpleMsg, ERROR_OFFSET);
__msgcc_implement(FixArrayMsg, ERROR_OFFSET);
__msgcc_implement(DynArrayMsg, ERROR_OFFSET);
__msgcc_implement(OmitMsg, ERROR_OFFSET);
__msgcc_implement(SwitchMsg, ERROR_OFFSET);
__msgcc_implement(MixMsg, ERROR_OFFSET);
__msgcc_implement(OrMsg, ERROR_OFFSET);
__msgcc_implement(SpecialOpMsg, ERROR_OFFSET);
__msgcc_implement(RequestMsg, ERROR_OFFSET);
__msgcc_implement(DynRuleArr, ERROR_OFFSET);

#endif
