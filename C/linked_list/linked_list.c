#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// represents a node in a linked list
typedef struct Node {
  int val;
  struct Node *next;
} Node;

void push(Node** list, int n);
Node* search(Node* list, int n);
int size(Node* list);
int pop_head(Node** list);
int pop_tail(Node** list);
void delete(Node** list, int n);

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
void test_pop_head(void) {
  Node* list = NULL;
  push(&list, 1);
  push(&list, 3);
  push(&list, 5);
  assert(size(list) == 3);
  assert(pop_head(&list) == 5);
  assert(size(list) == 2);
  assert(pop_head(&list) == 3);
  assert(size(list) == 1);
  assert(pop_head(&list) == 1);
  assert(size(list) == 0);
  assert(pop_head(&list) == -1);
  assert(list == NULL);
  printf("%s passed\n", __func__);
}

//tests for pop_tail function
void test_pop_tail(void) {
  Node* list = NULL;
  push(&list, 1);
  push(&list, 3);
  push(&list, 5);
  assert(size(list) == 3);
  assert(pop_tail(&list) == 1);
  assert(size(list) == 2);
  assert(pop_tail(&list) == 3);
  assert(size(list) == 1);
  assert(pop_tail(&list) == 5);
  assert(size(list) == 0);
  assert(pop_tail(&list) == -1);
  printf("%s passed\n", __func__);
}

// main function to run tests
int main(void) {
  test_push();
  test_search();
  test_size();
  test_delete();
  test_pop_head();
  test_pop_tail();

  // printf("%d\n", list->val);
  printf("All tests passed\n");

  return 0;
}

// inserts new node to the head of the linked list
void push(Node** list, int n) {
  Node *new = malloc(sizeof *new);
  new->val = n;
  new->next = *list;
  *list = new;
}

// gets a node that contains val of n, returns NULL if not found
Node* search(Node* list, int n) {
  if (list->next == NULL) {
    return NULL;
  } else if (list->next->val == n) {
    return list->next;
  }
  return search(list->next, n);
}

// calculates size of the linked list
int size(Node* list) {
  if (list == NULL) {
    return 0;
  }
  return 1 + size(list->next);
}

// pop the head node from linked list and returns its value
int pop_head(Node** list) {
  if (*list == NULL) {
    printf("Empty linked list\n");
    return -1;
  }
  int popped = (*list)->val;
  if ((*list)->next == NULL) {
    *list = NULL;
  } else {
    *list = (*list)->next;
  }
  return popped;
}

//pop the tail node from linked list and returns its value
int pop_tail(Node** list) {
  if (*list == NULL || (*list)->next == NULL){
    return pop_head(list);
  }
  int popped;
  Node* cur = *list;
  while (cur != NULL) {
    if (cur->next->next == NULL) {
      popped = cur->next->val;
      cur->next = cur->next->next;
      break;
    }
    cur = cur->next;
  }
  return popped;
}

// deletes a number from a linked list
void delete(Node** list, int n) {
  if ((*list)->val == n) {
    int p = pop_head(list);
    return;
  }
  Node* cur = *list;
  while (cur->next != NULL) {
    if (cur->next->val == n) {
      cur->next = cur->next->next;
      break;
    }
    cur = cur->next;
  }
}
