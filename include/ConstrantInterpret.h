#include "base/log.h"
#include "WrapperMsgUndef.h"
#include "InterpretCommon.h"
#include "FieldChecker.h"


#define FIELD_ERROR_CODE(NAME) ERROR::FIELD_ERROR_BASE(NAME) + errorBase
#define MSG_ERROR_CODE(NAME)   ERROR::MSG_ERROR_BASE(NAME) + errorBase

///////////////////////////////////////////////////////////////
#define __def_msg_begin(TYPE)                       \
struct MSG_CHECKER(TYPE)                            \
{                                                   \
    typedef MSG_ERROR(TYPE) ERROR;                  \
    template<typename MSG>                          \
    static U32 check( const MSG&  msg               \
                    , const TYPE& THIS              \
                    , const U32 errorBase           \
                    , const bool present = true)    \
    {                                               \
        if(!present)  return 0;                     \
        U32 ret = 0;

///////////////////////////////////////////////////////////////
#define __def_msg_end()                             \
        return 0;                                   \
    }                                               \
};

///////////////////////////////////////////////////////////////
#define CHECK_FIELD(field, ...)                     \
do{                                                 \
    ret = __VA_ARGS__::check(msg, THIS.field        \
                        , FIELD_ERROR_CODE(field)); \
    if(0 != ret)                                    \
    {                                               \
        ERR_LOG("%s(%d) is error(%d)"               \
             , #field, THIS.field, ret);            \
        return ret;                                 \
    }                                               \
}while(0);

///////////////////////////////////////////////////////////////
#define __field(field, ...)                         \
do{                                                 \
    ret = __VA_ARGS__::check(msg, THIS.field        \
                    , FIELD_ERROR_CODE(field));     \
    if(0 != ret)                                    \
    {                                               \
        ERR_LOG("%s(%d) is error(%d)"               \
                       , #field, THIS.field, ret);  \
        return ret;                                 \
    }                                               \
}while(0);

///////////////////////////////////////////////////////////////
#define __opt_field(field, present, Checker)        \
if(present)                                         \
{                                                   \
    __field(field, Checker)                         \
}

///////////////////////////////////////////////////////////////
#define __switch_field(field, Checker)              \
do{                                                 \
    __field(field, Checker)                         \
    if(0 == THIS.field)  return 0;                  \
}while(0);

///////////////////////////////////////////////////////////////
#define CHECK_ONE_FIELD_FOR_ARRAY(field, ...)       \
do{                                                 \
    ret = __VA_ARGS__::check(msg, THIS.field[i]     \
                        , FIELD_ERROR_CODE(field)); \
    if(0 != ret)                                    \
    {                                               \
        ERR_LOG("%s[%d](%d) is error(%d)"           \
             , #field, i, THIS.field[i], ret);      \
        return ret;                                 \
    }                                               \
}while(0);

///////////////////////////////////////////////////////////////
#define __fix_arr_field(field, size, Checker)       \
for(U32 i = 0; i < size; i++)                       \
{                                                   \
    CHECK_ONE_FIELD_FOR_ARRAY(field, Checker);      \
}

///////////////////////////////////////////////////////////////
#define __dyn_arr_field(field, size, Checker)       \
for(U32 i = 0; i < THIS.size; i++)                  \
{                                                   \
    CHECK_ONE_FIELD_FOR_ARRAY(field, Checker);      \
}

///////////////////////////////////////////////////////////////
#define __fix_arr_opt_field(field, size, present, Checker)\
if(present)                                         \
{                                                   \
    __fix_arr_field(field, size, Checker)           \
}

///////////////////////////////////////////////////////////////
#define __dyn_arr_opt_field(field, size, present, Checker)\
if(present)                                         \
{                                                   \
    __dyn_arr_field(field, size, Checker)           \
}

///////////////////////////////////////////////////////////////
#define __sub_msg(TYPE, field)                      \
do{                                                 \
    ret = MSG_CHECKER(TYPE)::check(msg, THIS.field  \
                          , MSG_ERROR_CODE(field)); \
    if(0 != ret)                                    \
    {                                               \
        ERR_LOG("%s:%s is error(%d)"                \
                           , #TYPE, #field, ret);   \
        return ret;                                 \
    }                                               \
}while(0);

///////////////////////////////////////////////////////////////
#define __opt_sub_msg(TYPE, field, present)         \
do{                                                 \
    ret = MSG_CHECKER(TYPE)::check(msg, THIS.field  \
            , MSG_ERROR_CODE(field), THIS.present); \
    if(0 != ret)                                    \
    {                                               \
        ERR_LOG("%s:%s is error(%d)"                \
                           , #TYPE, #field, ret);   \
        return ret;                                 \
    }                                               \
}while(0);

///////////////////////////////////////////////////////////////
#define CHECK_ONE_SUB_MSG_FOR_ARRAY(TYPE, field)    \
do{                                                 \
    ret = MSG_CHECKER(TYPE)::check( msg             \
                                  , THIS.field[i]   \
                           , MSG_ERROR_CODE(field));\
    if(0 != ret)                                    \
    {                                               \
        ERR_LOG("%s:%s[%d](%d) is error(%d)"        \
            , #TYPE, #field, i, THIS.field[i], ret);\
        return ret;                                 \
    }                                               \
}while(0);

///////////////////////////////////////////////////////////////
#define __fix_arr_sub_msg(TYPE, field, size)        \
for(U32 i = 0; i < size; i++)                       \
{                                                   \
    CHECK_ONE_SUB_MSG_FOR_ARRAY(TYPE, field);       \
}

///////////////////////////////////////////////////////////////
#define __dyn_arr_sub_msg(TYPE, field, size)       \
for(U32 i = 0; i < THIS.size; i++)                 \
{                                                  \
    CHECK_ONE_SUB_MSG_FOR_ARRAY(TYPE, field);      \
}

///////////////////////////////////////////////////////////////
#define __fix_arr_opt_sub_msg(TYPE, field, size, present)\
if(THIS.present)                                    \
{                                                   \
    __fix_arr_sub_msg(TYPE, field, size)            \
}

///////////////////////////////////////////////////////////////
#define __dyn_arr_opt_sub_msg(TYPE, field, size, present)\
if(THIS.present)                                    \
{                                                   \
    __dyn_arr_sub_msg(TYPE, field, size)            \
}

/////////////////////////////////////////////////////////
#define __()            FIELD_CHECKER(Omit)<>
#define EQ(LIMIT)       FIELD_CHECKER(Equal)<LIMIT>
#define NE(LIMIT)       FIELD_CHECKER(UnEqual)<LIMIT>
#define LT(LIMIT)       FIELD_CHECKER(LessThan)<LIMIT>
#define LE(LIMIT)       FIELD_CHECKER(LessOrEqual)<LIMIT>
#define GT(LIMIT)       FIELD_CHECKER(GreatThan)<LIMIT>
#define GE(LIMIT)       FIELD_CHECKER(GreatOrEqual)<LIMIT>
#define BT(LOW, HIGH)   FIELD_CHECKER(Between)<LOW, HIGH>
#define OR(...)         FIELD_CHECKER(CompositeOr)<__VA_ARGS__ >
#define OP(CHECKER)     FIELD_CHECKER(UserSpecified)<CHECKER>

