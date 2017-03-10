#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


//tests for push function
void test_push(void) {
  Node* list = NULL;
  push(&list, 10);
  push(&list, 5);
  push(&list, 7);
  push(&list, 8);

  assert(list->val == 8);
  assert(list->next->val == 7);
  assert(list->next->next->val == 5);
  assert(list->next->next->next->val == 10);
  assert(list->next->next->next->next == NULL);
  printf("%s passed\n", __func__);
}

//tests for search function
void test_search(void) {
  Node* list = NULL;
  push(&list, 10);
  push(&list, 5);
  push(&list, 7);

  assert(search(list, 100) == NULL);
  assert(search(list, 10)->val == 10);
  printf("%s passed\n", __func__);
}

//tests for search function
void test_size(void) {
  Node* list = NULL;
  push(&list, 10);
  push(&list, 5);
  assert(size(list) == 2);
  push(&list, 7);
  assert(size(list) == 3);
  delete(&list, 5);
  assert(size(list) == 2);
  printf("%s passed\n", __func__);
}

//tests for delete function
void test_delete(void) {
  Node* list = NULL;
  push(&list, 10);
  push(&list, 5);
  push(&list, 7);
  push(&list, 8);

  assert(size(list) == 4);
  delete(&list, 5);
  assert(list->val == 8);
  assert(list->next->val == 7);
  assert(list->next->next->val == 10);
  assert(list->next->next->next == NULL);
  assert(size(list) == 3);
  delete(&list, 7);
  assert(list->val == 8);
  assert(list->next->val == 10);
  assert(list->next->next == NULL);
  assert(size(list) == 2);
  delete(&list, 8);
  assert(list->val == 10);
  assert(list->next == NULL);
  assert(size(list) == 1);
  delete(&list, 1);
  assert(size(list) == 1);
  delete(&list, 10);
  assert(size(list) == 0);
  printf("%s passed\n", __func__);
}

//tests for pop_head function
void test_shift(void) {
  Node* list = NULL;
  push(&list, 1);
  push(&list, 3);
  push(&list, 5);
  assert(size(list) == 3);
  assert(shift(&list) == 5);
  assert(size(list) == 2);
  assert(shift(&list) == 3);
  assert(size(list) == 1);
  assert(shift(&list) == 1);
  assert(size(list) == 0);
  assert(shift(&list) == -1);
  assert(list == NULL);
  printf("%s passed\n", __func__);
}

//tests for pop_tail function
void test_pop(void) {
  Node* list = NULL;
  push(&list, 1);
  push(&list, 3);
  push(&list, 5);
  assert(size(list) == 3);
  assert(pop(&list) == 1);
  assert(size(list) == 2);
  assert(pop(&list) == 3);
  assert(size(list) == 1);
  assert(pop(&list) == 5);
  assert(size(list) == 0);
  assert(pop(&list) == -1);
  printf("%s passed\n", __func__);
}

// main function to run tests
int main(void) {
  test_push();
  test_search();
  test_size();
  test_delete();
  test_shift();
  test_pop();

  // printf("%d\n", list->val);
  printf("All tests passed\n");

  return 0;
}
