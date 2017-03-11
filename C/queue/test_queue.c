#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

//tests for create_q function
void test_create_q(void) {
  Q* q = create_q(5);

  assert(q->_q->head->val == 5);
  printf("%s passed\n", __func__);
}

//tests for enqueue function
void test_enqueue(void) {
  Q* q = create_q(5);
  enqueue(q, 7);
  enqueue(q, 8);
  enqueue(q, 9);

  assert(q->_q->head->val == 5);
  assert(q->_q->head->next->val == 7);
  assert(q->_q->head->next->next->val == 8);
  assert(q->_q->head->next->next->next->val == 9);
  printf("%s passed\n", __func__);
}

//tests for dequeue function
void test_dequeue(void) {
  Q* q = create_q(5);
  enqueue(q, 7);
  enqueue(q, 8);
  enqueue(q, 9);

  assert(dequeue(q) == 5);
  assert(dequeue(q) == 7);
  assert(dequeue(q) == 8);
  assert(dequeue(q) == 9);
  assert(dequeue(q) == -1);
  printf("%s passed\n", __func__);
}

//tests for peek function
void test_peek(void) {
  Q* q = create_q(5);
  enqueue(q, 7);
  enqueue(q, 8);
  enqueue(q, 9);

  assert(peek(q) == 5);
  dequeue(q);
  assert(peek(q) == 7);
  dequeue(q);
  assert(peek(q) == 8);
  dequeue(q);
  assert(peek(q) == 9);
  printf("%s passed\n", __func__);
}

//tests for size function
void test_size(void) {
  Q* q = create_q(5);

  assert(size_q(q) == 1);
  enqueue(q, 7);
  assert(size_q(q) == 2);
  enqueue(q, 8);
  assert(size_q(q) == 3);
  enqueue(q, 9);
  assert(size_q(q) == 4);
  dequeue(q);
  assert(size_q(q) == 3);
  dequeue(q);
  assert(size_q(q) == 2);
  dequeue(q);
  assert(size_q(q) == 1);
  dequeue(q);
  assert(size_q(q) == 0);
  printf("%s passed\n", __func__);
}

int main(void) {
  test_create_q();
  test_enqueue();
  test_dequeue();
  test_peek();
  test_size();

  printf("All tests passed\n");
  return 0;
}
