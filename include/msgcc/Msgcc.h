#ifndef HF538AD62_558E_4451_A5AC_34027940BD3D
#define HF538AD62_558E_4451_A5AC_34027940BD3D

#include <msgcc/base/BaseTypes.h>
#include <msgcc/details/MsgWrapper.h>

template <typename MSG>
struct Msgcc
{
    static Status check(const MSG&);
    static void construct(MSG&);
};

////////////////////////////////////////////////////////
#define __msgcc_implement(MSG, ERROR_BASE)          \
template<> struct Msgcc<MSG>                        \
{                                                   \
    static Status check(const MSG& msg)             \
    {                                               \
        return MSG_CHECKER(MSG)::check( msg         \
                                      , msg         \
                                      , ERROR_BASE);\
    }                                               \
    static void construct(MSG& msg)                 \
    {                                               \
        MSG_CTOR(MSG)::construct(msg, msg);         \
    }                                               \
};

#endif
