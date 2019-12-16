#include "state_machine.h"

#include <unity.h>

#include <string>

void test_get_gait_name() {
  StateMachine state_machine;
  std::string gait_name = state_machine.getCurrentGaitName();
  TEST_ASSERT_EQUAL_STRING("", gait_name.c_str());
}

void test_get_image() {
  StateMachine state_machine;
  unsigned int expected_hi = 2;
  unsigned int expected_lo = 3;
  unsigned int hi = expected_hi;
  unsigned int lo = expected_lo;
  state_machine.getCurrentImage(hi, lo);
  TEST_ASSERT_EQUAL(expected_hi, hi);
  TEST_ASSERT_EQUAL(expected_lo, lo);
}

void test_state_machine_default_no_transitions() {
  StateMachine state_machine;
  TEST_ASSERT_FALSE(state_machine.left());
  TEST_ASSERT_FALSE(state_machine.right());
  TEST_ASSERT_FALSE(state_machine.up());
  TEST_ASSERT_FALSE(state_machine.down());
  TEST_ASSERT_FALSE(state_machine.back());
  TEST_ASSERT_FALSE(state_machine.select());
  TEST_ASSERT_FALSE(state_machine.activate());
}

int main(int argc, char** argv) {
  UNITY_BEGIN();
  RUN_TEST(test_get_gait_name);
  RUN_TEST(test_get_image);
  RUN_TEST(test_state_machine_default_no_transitions);
  UNITY_END();

  return 0;
}
