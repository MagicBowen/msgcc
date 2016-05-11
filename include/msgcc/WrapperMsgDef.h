#ifndef HDB79ADB1_E2A2_48CA_9895_910491109581
#define HDB79ADB1_E2A2_48CA_9895_910491109581

#include <msgcc/MsgWrapper.h>
#include <msgcc/base/static_assert.h>

/////////////////////////////////////////////////////////////
#define MSG_WRAPPER_BASE(MSG)  MSG##WrapperBase

#define __def_msg(NAME, MSG, ERROR_BASE)                    \
template<typename TO>                                       \
struct MSG_WRAPPER_BASE(MSG) : protected MSG                \
{                                                           \
    static const TO& by(const MSG& from)                    \
    {                                                       \
        STATIC_ASSERT(sizeof(MSG) == sizeof(TO));           \
                                                            \
        return (const TO&)from;                             \
    }                                                       \
    const MSG& getRef() const                               \
    {                                                       \
        return (const MSG&)(*this);                         \
    }                                                       \
    Status verify() const                                   \
    {                                                       \
        return MSG_CHECKER(MSG)::check( (const MSG&)(*this) \
                                      , (const MSG&)(*this) \
                                      , ERROR_BASE);        \
    }                                                       \
};                                                          \
struct NAME                                                 \
: MSG_WRAPPER_BASE(MSG)<NAME>

/////////////////////////////////////////////////////////////
#define __def_default_msg(MSG, ERROR_BASE)                  \
__def_msg(MSG_WRAPPER(MSG), MSG, ERROR_BASE){}

#endif
