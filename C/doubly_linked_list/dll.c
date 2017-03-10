#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

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

//adds new node to end of the dll
void append(DLL* list, int n) {
  Node* new = create_node(n);
  new->prev = list->tail;
  list->tail->next = new;
  list->tail = new;
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

//deletes the node that carries the given value from the dll
void delete(DLL* list, int n) {
  if (list->head == NULL || list->tail == NULL || list->head->val == n) {
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
