#include <stdlib.h>
#include "stack.h"

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
