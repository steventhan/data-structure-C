#include "../src/linked-list.h"
#include "../src/unity.h"

void setUp(void) {
// set stuff up here
}
void tearDown(void) {
// clean stuff up here
}

void test_LinkedList(void) {
  TEST_ASSERT(LinkedList() == 0);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_LinkedList);
  return UNITY_END();
}
