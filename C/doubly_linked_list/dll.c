#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

//represents a node in a doubly linked list
typedef struct Node {
  int val;
  struct Node* prev;
  struct Node* next;
} Node;

//represents a dll
typedef struct DLL {
  struct Node* head;
  struct Node* tail;
} DLL;

DLL* create(int n);
Node* create_node(int n);
void push(DLL* list, int n);
int size(DLL* list);
int pop(DLL* list);
int shift(DLL* list);
void delete(*DLL list, int n);

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

int main(void) {
  test_create_node();
  test_create();
  test_push();
  test_size();
  test_pop();
  test_shift();
  test_delete();
  printf("All tests passed\n");

  return 0;
}

//creates a new node that carries given value
Node* create_node(int n) {
  Node* node = malloc(sizeof* node);
  node->val = n;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

//creates a new dll with 1 node
DLL* create(int n) {
  DLL* list = malloc(sizeof* list);
  Node* node = create_node(n);
  list->head = node;
  list->tail = node;
  return list;
}

//adds new node to beginning of the dll
void push(DLL* list, int n) {
  Node* new = create_node(n);
  new->next = list->head;
  list->head->prev = new;
  list->head = new;
}

//calculates size of the dll
int size(DLL* list) {
  int s = 0;
  Node* cur = list->head;
  while (cur != NULL) {
    s++;
    cur = cur->next;
  }
  return s;
}

//removes last node from the dll and returns its value
int pop(DLL* list) {
  if (list->head == NULL || list->tail == NULL) {
    printf("Empty dll\n");
    return -1;
  }
  int popped = list->tail->val;
  Node* new_tail = list->tail->prev;
  if (new_tail == NULL) {
    list->head = NULL;
    list->tail = NULL;
  } else {
    list->tail = new_tail;
    new_tail->next = NULL;
  }
  return popped;
}

//removes first node from the dll and returns its value
int shift(DLL* list) {
  if (list->head == NULL || list->tail == NULL || list->head->next == NULL) {
    return pop(list);
  }
  int popped = list->head->val;
  Node* new_head = list->head->next;
  list->head = new_head;
  new_head->prev = NULL;
  return popped;
}

void delete(*DLL list, int n) {
  if (list->head->val == n) {
    int shifted = shift(list);
    return;
  } else if (list->tail->val == n) {
    int popped = pop(list);
    return;
  }
  Node* cur = list->head;
  while (cur != NULL) {
    if (cur->val == n) {
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
      break;
    }
    cur = cur->next;
  }
}
