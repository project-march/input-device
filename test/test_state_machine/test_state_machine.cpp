#include "state_machine.h"

#include <unity.h>

#include <string>

void test_get_gait_name()
{
  StateMachine state_machine;
  std::string gait_name = state_machine.getCurrentGaitName();
  TEST_ASSERT_EQUAL_STRING("", gait_name.c_str());
}

void test_get_image()
{
  StateMachine state_machine;
  SectorAddress address = state_machine.getCurrentImage();
  TEST_ASSERT_EQUAL(0, address.hi);
  TEST_ASSERT_EQUAL(0, address.lo);
}

void test_state_machine_default_no_transitions()
{
  StateMachine state_machine;
  TEST_ASSERT_FALSE(state_machine.left());
  TEST_ASSERT_FALSE(state_machine.right());
  TEST_ASSERT_FALSE(state_machine.back());
  TEST_ASSERT_FALSE(state_machine.select());
  TEST_ASSERT_FALSE(state_machine.activate());
  TEST_ASSERT_FALSE(state_machine.shortcutPush());
}

void test_default_empty()
{
  StateMachine state_machine;
  TEST_ASSERT_EQUAL(0, state_machine.size());
}

int main(int argc, char** argv)
{
  UNITY_BEGIN();
  RUN_TEST(test_get_gait_name);
  RUN_TEST(test_get_image);
  RUN_TEST(test_state_machine_default_no_transitions);
  RUN_TEST(test_default_empty);
  UNITY_END();

  return 0;
}
