#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
  int val;
  struct Node* next;
} Node;

typedef struct Stack {
  struct Node* top;
} Stack;

Node* _create_node(int n);
Stack* create(int n);
void push(Stack* s, int n);
int pop(Stack* s);
int peek(Stack* s);

//tests for _create_node function
void test_create_node(void) {
  Node* node = _create_node(5);

  assert(node->val == 5);
  assert(node->next == NULL);
  printf("%s passed\n", __func__);
}

//tests for create function
void test_create(void) {
  Stack* s = create(5);

  assert(s->top->val == 5);
  assert(s->top->next == NULL);
  printf("%s passed\n", __func__);
}

void test_push(void) {
  Stack* s = create(5);
  push(s, 7);
  push(s, 8);
  push(s, 9);
  push(s, 10);

  assert(s->top->val == 10);
  assert(s->top->next->val == 9);
  assert(s->top->next->next->val == 8);
  assert(s->top->next->next->next->val == 7);
  assert(s->top->next->next->next->next->val == 5);
  printf("%s passed\n", __func__);
}

//tests for pop function
void test_pop(void) {
  Stack* s = create(5);
  push(s, 7);
  push(s, 8);
  push(s, 9);
  push(s, 10);

  assert(pop(s) == 10);
  assert(s->top->val == 9);
  assert(pop(s) == 9);
  assert(s->top->val == 8);
  assert(pop(s) == 8);
  assert(s->top->val == 7);
  assert(pop(s) == 7);
  assert(s->top->val == 5);
  assert(pop(s) == 5);
  assert(pop(s) == -1);
  printf("%s passed\n", __func__);
}

//tests for peek function
void test_peek(void) {
  Stack* s = create(5);
  push(s, 7);
  push(s, 8);
  push(s, 9);
  push(s, 10);

  assert(peek(s) == 10);
  assert(s->top->val == 10);
  pop(s);
  assert(peek(s) == 9);
  assert(s->top->val == 9);
  pop(s);
  assert(peek(s) == 8);
  assert(s->top->val == 8);
  pop(s);
  assert(peek(s) == 7);
  assert(s->top->val == 7);
  pop(s);
  assert(peek(s) == 5);
  assert(s->top->val == 5);
  pop(s);
  assert(peek(s) == -1);
  assert(s->top == NULL);
  printf("%s passed\n", __func__);
}

int main(void) {
  test_create_node();
  test_create();
  test_pop();
  test_push();
  test_peek();
  printf("All tests passed\n");
  return 0;
}

//creates new node that carries the supplied value
Node* _create_node(int n) {
  Node* new = malloc(sizeof* new);
  new->val = n;
  new->next = NULL;
  return new;
}

//creates a stack with one value
Stack* create(int n) {
  Stack* s = malloc(sizeof* s);
  s->top = _create_node(n);
  s->top->next = NULL;
  return s;
}


void push(Stack* s, int n) {
  Node* new = _create_node(n);
  new->next = s->top;
  s->top = new;
}

//pop the the top value from the Stack and returns it
int pop(Stack* s) {
  if (s->top == NULL) {
    return -1;
  }
  int popped = s->top->val;
  s->top = s->top->next;
  return popped;
}

int peek(Stack* s) {
  if (s->top == NULL) {
    return -1;
  }
  return s->top->val;
}
