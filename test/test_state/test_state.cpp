#include "state.h"

#include <unity.h>

#include <string>

void test_state_get_gait_name() {
  std::string gait("test");
  State state({0, 0}, gait);
  TEST_ASSERT_EQUAL_STRING(gait.c_str(), state.getGaitName().c_str());
}

void test_state_get_address() {
  SectorAddress expected = {7, 8};
  State state(expected);

  SectorAddress address;
  state.getImage(address);
  TEST_ASSERT_EQUAL(expected.hi, address.hi);
  TEST_ASSERT_EQUAL(expected.lo, address.lo);
}

void test_state_default_transitions() {
  State state({0, 0});
  TEST_ASSERT_EQUAL(&state, state.left());
  TEST_ASSERT_EQUAL(&state, state.right());
  TEST_ASSERT_EQUAL(&state, state.up());
  TEST_ASSERT_EQUAL(&state, state.down());
  TEST_ASSERT_EQUAL(&state, state.back());
  TEST_ASSERT_EQUAL(&state, state.select());
  TEST_ASSERT_EQUAL(&state, state.activate());
}

int main(int argc, char** argv) {
  UNITY_BEGIN();
  RUN_TEST(test_state_get_gait_name);
  RUN_TEST(test_state_get_address);
  RUN_TEST(test_state_default_transitions);
  UNITY_END();

  return 0;
}
