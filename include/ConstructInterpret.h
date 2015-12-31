#include "WrapperMsgUndef.h"
#include "MsgWrapper.h"
#include "FieldCtor.h"
#include "base/NullPtr.h"

///////////////////////////////////////////////////////////////
#define __def_msg_begin(TYPE)                   \
struct MSG_CTOR(TYPE)                           \
{                                               \
    template<typename MSG, typename T = U16>    \
    static void construct( const MSG& msg       \
                         , TYPE& THIS           \
                         , T* present = __null_ptr__)\
    {

///////////////////////////////////////////////////////////////
#define __def_msg_end()                         \
        if(__not_null(present)) *present = 1;   \
    }                                           \
    template<typename MSG>                      \
    static bool construct(MSG& msg)             \
    {                                           \
        U32 present = 0;                        \
        construct(msg, msg, &present);          \
        return (1 == present);                  \
    }                                           \
};

///////////////////////////////////////////////////////////////
#define __field(field, Ctor)  Ctor::construct(msg, THIS.field);

///////////////////////////////////////////////////////////////
#define __opt_field(field, present, Ctor)   Ctor::construct(msg, THIS.field);

///////////////////////////////////////////////////////////////
#define __switch_field(field, Ctor)  Ctor::construct(msg, THIS.field);

///////////////////////////////////////////////////////////////
#define __fix_arr_field(field, size, Ctor)      \
for(U32 i = 0; i < size; i++)                   \
{                                               \
    Ctor::construct(msg, THIS.field[i]);        \
}                                               \

///////////////////////////////////////////////////////////////
#define __dyn_arr_field(field, size, Ctor)      \
for(U32 i = 0; i < THIS.size; i++)              \
{                                               \
    Ctor::construct(msg, THIS.field[i]);        \
}

///////////////////////////////////////////////////////////////
#define __fix_arr_opt_field(field, size, present, Ctor)\
__fix_arr_field(field, size, Ctor)

///////////////////////////////////////////////////////////////
#define __dyn_arr_opt_field(field, size, present, Ctor)\
__dyn_arr_field(field, size, Ctor)

///////////////////////////////////////////////////////////////
#define __sub_msg(TYPE, field)                  \
MSG_CTOR(TYPE)::construct(msg, THIS.field);

///////////////////////////////////////////////////////////////
#define __opt_sub_msg(TYPE, field, present)     \
MSG_CTOR(TYPE)::construct(msg, THIS.field, &(THIS.present));

///////////////////////////////////////////////////////////////
#define __fix_arr_sub_msg(TYPE, field, size)            \
for(U32 i = 0; i < size; i++)                           \
{                                                       \
    MSG_CTOR(TYPE)::construct( msg                      \
                             , THIS.field[i]);          \
}

///////////////////////////////////////////////////////////////
#define __dyn_arr_sub_msg(TYPE, field, size)            \
for(U32 i = 0; i < THIS.size; i++)                      \
{                                                       \
    MSG_CTOR(TYPE)::construct( msg                      \
                             , THIS.field[i]);          \
}

///////////////////////////////////////////////////////////////
#define __fix_arr_opt_sub_msg(TYPE, field, size, present)\
for(U32 i = 0; i < size; i++)                           \
{                                                       \
    MSG_CTOR(TYPE)::construct( msg                      \
                             , THIS.field[i]            \
                             , &(THIS.present));        \
}

///////////////////////////////////////////////////////////////
#define __dyn_arr_opt_sub_msg(TYPE, field, size, present)\
for(U32 i = 0; i < THIS.size; i++)                      \
{                                                       \
    MSG_CTOR(TYPE)::construct( msg                      \
                             , THIS.field[i]            \
                             , &(THIS.present));        \
}

///////////////////////////////////////////////////////////////
#define __()            FIELD_CTOR(Omit)<>
#define EQ(LIMIT)       FIELD_CTOR(Equal)<LIMIT>
#define NE(LIMIT)       FIELD_CTOR(UnEqual)<LIMIT>
#define LT(LIMIT)       FIELD_CTOR(LessThan)<LIMIT>
#define LE(LIMIT)       FIELD_CTOR(LessOrEqual)<LIMIT>
#define GT(LIMIT)       FIELD_CTOR(GreatThan)<LIMIT>
#define GE(LIMIT)       FIELD_CTOR(GreatOrEqual)<LIMIT>
#define BT(LOW, HIGH)   FIELD_CTOR(Between)<LOW, HIGH>
#define OR(...)         FIELD_CTOR(CompositeOr)<__VA_ARGS__ >
#define OP(CTOR)        FIELD_CTOR(UserSpecified)<CTOR>

