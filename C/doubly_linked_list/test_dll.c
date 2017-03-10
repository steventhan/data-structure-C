#include <stdio.h>
#include <assert.h>
#include "dll.h"

//tests for create function
void test_create_node(void) {
  Node* node = create_node(5);
  Node* node1 = create_node(7);

  assert(node->val == 5);
  assert(node->prev == NULL);
  assert(node->next == NULL);
  assert(node1->val == 7);
  assert(node1->prev == NULL);
  assert(node1->next == NULL);
  printf("%s passed\n", __func__);
}

//tests for create function
void test_create(void) {
  DLL* list = create(5);

  assert(list->head->val == 5);
  assert(list->head->prev == NULL);
  assert(list->head->next == NULL);
  assert(list->tail->val == 5);
  assert(list->tail->prev == NULL);
  assert(list->tail->next == NULL);
  printf("%s passed\n", __func__);
}

//test for push function
void test_push(void) {
  DLL* list = create(5);

  push(list, 7);
  assert(list->head->val == 7);
  assert(list->head->prev == NULL);
  assert(list->head->next == list->tail);
  assert(list->head->next->val == 5);
  assert(list->tail->next == NULL);
  assert(list->head->next->next == NULL);
  assert(list->head->next->prev == list->head);
  assert(list->head->next->prev->val == 7);

  push(list, 10);
  assert(list->head->val == 10);
  assert(list->tail->val == 5);
  assert(list->head->prev == NULL);
  assert(list->head->next->val == 7);
  assert(list->tail->prev->val == 7);
  assert(list->head->next->prev == list->head);
  assert(list->tail->prev->prev->val == 10);
  assert(list->head->next->prev->val == 10);
  assert(list->head->next->next == list->tail);
  assert(list->head->next->next->val == 5);
  assert(list->head->next->next->prev == list->head->next);
  assert(list->head->next->next->prev->val == 7);
  assert(list->head->next->next->next == NULL);
  printf("%s passed\n", __func__);
}

//test for append function
void test_append(void) {
  DLL* list = create(5);
  append(list, 7);
  append(list, 10);
  append(list, 12);

  assert(size(list) == 4);
  assert(list->head->val == 5);
  assert(list->head->next->val == 7);
  assert(list->head->next->next->val == 10);
  assert(list->head->next->next->next->val == 12);
  assert(list->tail->val == 12);
  assert(list->tail->prev->val == 10);
  assert(list->tail->prev->prev->val == 7);
  assert(list->tail->prev->prev->prev->val == 5);

  printf("%s passed\n", __func__);
}

//test for size function
void test_size(void) {
  DLL* list = create(5);
  push(list, 7);
  push(list, 10);

  assert(size(list) == 3);
  push(list, 12);
  assert(size(list) == 4);
  push(list, 14);
  assert(size(list) == 5);
  printf("%s passed\n", __func__);
}

//tests for pop function
void test_pop(void) {
  DLL* list = create(5);
  push(list, 7);
  push(list, 10);
  push(list, 12);

  assert(size(list) == 4);
  assert(pop(list) == 5);
  assert(size(list) == 3);
  assert(pop(list) == 7);
  assert(size(list) == 2);
  assert(pop(list) == 10);
  assert(size(list) == 1);
  assert(pop(list) == 12);
  assert(size(list) == 0);
  assert(pop(list) == -1);
  printf("%s passed\n", __func__);
}

//tests for shift function
void test_shift(void) {
  DLL* list = create(5);
  push(list, 7);
  push(list, 10);
  push(list, 12);

  assert(size(list) == 4);
  assert(shift(list) == 12);
  assert(size(list) == 3);
  assert(shift(list) == 10);
  assert(size(list) == 2);
  assert(shift(list) == 7);
  assert(size(list) == 1);
  assert(shift(list) == 5);
  assert(size(list) == 0);
  assert(shift(list) == -1);
  printf("%s passed\n", __func__);
}

//tests for delete function
void test_delete(void) {
  DLL* list = create(5);
  push(list, 7);
  push(list, 10);
  push(list, 12);

  delete(list, 20);
  assert(size(list) == 4);
  delete(list, 7);
  assert(size(list) == 3);
  assert(list->head->val == 12);
  assert(list->head->next->val == 10);
  assert(list->head->next->next->val == 5);
  assert(list->head->next->next->next == NULL);
  assert(list->tail->val == 5);
  assert(list->tail->prev->val == 10);
  assert(list->tail->prev->prev->val == 12);
  assert(list->tail->prev->prev->prev == NULL);

  delete(list, 10);
  assert(size(list) == 2);
  assert(list->head->val == 12);
  assert(list->head->next->val == 5);
  assert(list->head->next->next == NULL);
  assert(list->tail->val == 5);
  assert(list->tail->prev->val == 12);
  assert(list->tail->prev->prev == NULL);

  delete(list, 5);
  assert(size(list) == 1);
  assert(list->head->val == 12);
  assert(list->head->next == NULL);
  assert(list->tail->val == 12);
  assert(list->tail->prev == NULL);

  delete(list, 12);
  assert(size(list) == 0);
  assert(list->head == NULL);
  assert(list->tail == NULL);

  printf("%s passed\n", __func__);
}

int main(void) {
  test_create_node();
  test_create();
  test_push();
  test_append();
  test_size();
  test_pop();
  test_shift();
  test_delete();
  printf("All tests passed\n");
  return 0;
}
