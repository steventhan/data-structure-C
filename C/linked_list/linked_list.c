#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// represents a node in a linked list
typedef struct Node {
  int val;
  struct Node *next;
} Node;

// inserts new node to the head of the linked list
void push(Node **list, int n) {
  Node *new = malloc(sizeof *new);
  new->val = n;
  new->next = *list;
  *list = new;
}

// gets a node that contains val of n, returns NULL if not found
Node *search(Node *list, int n) {
  if (list->next == NULL) {
    return list->next;
  } else if (list->next->val == n) {
    return list->next;
  }
  return search(list->next, n);
}

// calculates size of the linked list
int size(Node *list) {
  if (list->next == NULL) {
    return 1;
  }
  return 1 + size(list->next);
}

// main function to run tests
int main(void) {
  Node *list;
  list->val = 10;
  list->next = NULL;
  push(&list, 5);

  assert(list->val == 5);
  assert(list->next->val == 10);
  assert(search(list, 100) == NULL);
  assert(search(list, 10)->val == 10);
  assert(size(list) == 2);

  // printf("%d\n", list->val);
  printf("All tests passed\n");
  free(list);

  return 0;
}
