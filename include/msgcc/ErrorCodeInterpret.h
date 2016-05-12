#include <msgcc/InterpretUndef.h>
#include <msgcc/details/InterpretCommon.h>

///////////////////////////////////////////////////////////////
#define __msgcc_begin(TYPE)                         \
struct MSG_ERROR(TYPE)                              \
{                                                   \
    enum{

///////////////////////////////////////////////////////////////
#define __msgcc_end()                               \
    MAX_ERROR_NUM    };                             \
};

///////////////////////////////////////////////////////////////
#define __field(NAME, Checker)   FIELD_ERROR_BASE(NAME),

///////////////////////////////////////////////////////////////
#define __opt_field(NAME, present, Checker)   FIELD_ERROR_BASE(NAME),

///////////////////////////////////////////////////////////////
#define __switch_field(NAME, Checker)   FIELD_ERROR_BASE(NAME),

///////////////////////////////////////////////////////////////
#define __fix_arr_field(NAME, SIZE, Checker)   FIELD_ERROR_BASE(NAME),

///////////////////////////////////////////////////////////////
#define __dyn_arr_field(NAME, SIZE, Checker)   FIELD_ERROR_BASE(NAME),

///////////////////////////////////////////////////////////////
#define __fix_arr_opt_field(NAME, SIZE, Checker)   FIELD_ERROR_BASE(NAME),

///////////////////////////////////////////////////////////////
#define __dyn_arr_opt_field(NAME, SIZE, Checker)   FIELD_ERROR_BASE(NAME),

///////////////////////////////////////////////////////////////
#define __sub_msg(TYPE, NAME)                       \
MSG_ERROR_BASE(NAME),                               \
MSG_ERROR_END(NAME) = MSG_ERROR_BASE(NAME) + MSG_ERROR(TYPE)::MAX_ERROR_NUM - 1,

///////////////////////////////////////////////////////////////
#define __opt_sub_msg(TYPE, NAME, PRESENT)  __sub_msg(TYPE, NAME)

///////////////////////////////////////////////////////////////
#define __fix_arr_sub_msg(TYPE, NAME, SIZE)         \
__sub_msg(TYPE, NAME)

///////////////////////////////////////////////////////////////
#define __dyn_arr_sub_msg(TYPE, NAME, SIZE)         \
__sub_msg(TYPE, NAME)

///////////////////////////////////////////////////////////////
#define __fix_arr_opt_sub_msg(TYPE, NAME, SIZE, PRESENT)\
__opt_sub_msg(TYPE, NAME, PRESENT)

///////////////////////////////////////////////////////////////
#define __dyn_arr_opt_sub_msg(TYPE, NAME, SIZE, PRESENT)\
__opt_sub_msg(TYPE, NAME, PRESENT)
