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
void delete(Node** list, int n);

// main function to run tests
int main(void) {
  Node* list;
  list->val = 10;
  list->next = NULL;
  push(&list, 5);
  push(&list, 7);

  assert(list->val == 7);
  assert(list->next->val == 5);
  assert(search(list, 100) == NULL);
  assert(search(list, 10)->val == 10);
  assert(size(list) == 3);

  delete(&list, 5);
  assert(size(list) == 2);
  delete(&list, 7);
  assert(size(list) == 1);
  delete(&list, 10);
  assert(size(list) == 0);

  // printf("%d\n", list->val);
  printf("All tests passed\n");
  // free(list);

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
    return list->next;
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

// deletes a number from a linked list
void delete(Node** list, int n) {
  if ((*list)->val == n) {
    if ((*list)->next == NULL) {
      *list = NULL;
    } else {
      *list = ((*list)->next);
    }
    return;
  }
  
  do {
    if ((*list)->next->val == n) {
      (*list)->next = (*list)->next->next;
      break;
    }
    (*list) = (*list)->next;
  } while((*list) != NULL);
}
