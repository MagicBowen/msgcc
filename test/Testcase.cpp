#include "gtest/gtest.h"
#include "WrapperMsgs.h"


TEST(msgcc, should_omit_the_unpresent_part)
{
    SimpleMsg msg;

    msg.field1 = 3;
    msg.subMsg1Present = 0;
    msg.subMsg2Present = 0;
    msg.subMsg2.field1 = 4;

    ASSERT_EQ(0, MSG_WRAPPER(SimpleMsg)::by(msg).verify());
}

TEST(MagCc, should_return_the_error_code_correctly)
{
    SimpleMsg msg;

    msg.field1 = 3;
    msg.subMsg1Present = 0;
    msg.subMsg2Present = 1;
    msg.subMsg2.field1 = 2;

    ASSERT_EQ(4, MSG_WRAPPER(SimpleMsg)::by(msg).verify());
}

TEST(msgcc, should_verify_the_array_part_correctly)
{
    FixArrayMsg msg;

    msg.field[0] = 3;
    msg.field[1] = 3;
    msg.present = 1;
    msg.subMsg[0].field1 = 3;
    msg.subMsg[1].field1 = 0;

    ASSERT_EQ(2, MSG_WRAPPER(FixArrayMsg)::by(msg).verify());
}

TEST(msgcc, should_construct_valid_simple_msg)
{
    SimpleMsg msg;

    ASSERT_TRUE(MSG_CTOR(SimpleMsg)::construct(msg));

    ASSERT_EQ(4, msg.field1);
    ASSERT_EQ(1, msg.subMsg1Present);
    ASSERT_EQ(2, msg.subMsg1.field1);
    ASSERT_EQ(4, msg.subMsg1.field2);
    ASSERT_EQ(1, msg.subMsg2Present);
    ASSERT_EQ(3, msg.subMsg2.field1);

    ASSERT_EQ(0, MSG_WRAPPER(SimpleMsg)::by(msg).verify());
}

TEST(msgcc, should_construct_valid_msg_with_array)
{
    FixArrayMsg msg;

    MSG_CTOR(FixArrayMsg)::construct(msg);

    ASSERT_EQ(4, msg.field[0]);
    ASSERT_EQ(4, msg.field[1]);
    ASSERT_EQ(1, msg.present);
    ASSERT_EQ(3, msg.subMsg[0].field1);
    ASSERT_EQ(3, msg.subMsg[1].field1);

    ASSERT_EQ(0, MSG_WRAPPER(FixArrayMsg)::by(msg).verify());
}

TEST(msgcc, should_verify_the_msg_with_dynamic_array)
{
    DynArrayMsg msg;

    MSG_CTOR(DynArrayMsg)::construct(msg);

    msg.subMsg2[2].field1 = 1;

    ASSERT_EQ(4, MSG_WRAPPER(DynArrayMsg)::by(msg).verify());
}

TEST(msgcc, should_omit_the_uncare_field)
{
    OmitMsg msg;

    MSG_CTOR(OmitMsg)::construct(msg);
    ASSERT_EQ(0, msg.field2);

    msg.field2 = 5;
    msg.field3 = 5;

    ASSERT_EQ(3, MSG_WRAPPER(OmitMsg)::by(msg).verify());
}

TEST(msgcc, should_omit_fields_when_switch_field_indicated_disable)
{
    SwitchMsg msg;

    MSG_CTOR(SwitchMsg)::construct(msg);

    ASSERT_EQ(1, msg.enable);
    ASSERT_EQ(1, msg.field2);

    msg.enable = 2;
    ASSERT_EQ(1, MSG_WRAPPER(SwitchMsg)::by(msg).verify());

    msg.enable = 1;
    msg.field2 = 2;

    ASSERT_EQ(3, MSG_WRAPPER(SwitchMsg)::by(msg).verify());
}

TEST(msgcc, should_verify_the_mixed_msg_ok)
{
    MixMsg msg;

    MSG_CTOR(MixMsg)::construct(msg);

    msg.present1 = 0;
    msg.sCfg.enable = 2;

    ASSERT_EQ(0, MSG_WRAPPER(MixMsg)::by(msg).verify());

    msg.present1 = 1;
    msg.sCfg.enable = 0;
    msg.nCfg.field1 = 5;

    ASSERT_EQ(4, MSG_WRAPPER(MixMsg)::by(msg).verify());
}

TEST(msgcc, should_verify_the_msg_with_OR_part)
{
    OrMsg msg;

    MSG_CTOR(OrMsg)::construct(msg);

    ASSERT_EQ(2, msg.field);

    msg.field = 255;
    ASSERT_EQ(0, MSG_WRAPPER(OrMsg)::by(msg).verify());
}

TEST(msgcc, should_verify_the_msg_with_user_defined_operation)
{
    SpecialOpMsg msg;

    MSG_CTOR(SpecialOpMsg)::construct(msg);

    ASSERT_EQ(10, msg.condition);
    ASSERT_EQ(10, msg.field);

    msg.field = 0;

    ASSERT_EQ(2, MSG_WRAPPER(SpecialOpMsg)::by(msg).verify());
}

TEST(msgcc, should_config_and_verify_the_requisite_msg)
{
    RequestMsg msg;

    MSG_CTOR(RequestMsg)::construct(msg);

    ASSERT_EQ(0, MSG_WRAPPER(RequestMsg)::by(msg).verify());

    msg.subMsg1.field1 = 4;

    ASSERT_EQ(1, MSG_WRAPPER(RequestMsg)::by(msg).verify());
}

TEST(msgcc, should_config_and_verify_the_dynamic_rule_arr_cfg)
{
    DynRuleArr msg;

    MSG_CTOR(DynRuleArr)::construct(msg);

    ASSERT_EQ(0, msg.fields[0]);
    ASSERT_EQ(1, msg.fields[1]);

    msg.fields[0] = 4;

    ASSERT_EQ(1, MSG_WRAPPER(DynRuleArr)::by(msg).verify());
}

//////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
