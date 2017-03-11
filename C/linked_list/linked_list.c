#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

// creates a head node for a singly linked list
Node* create(int n) {
  Node* head = malloc(sizeof* head);
  head->val = n;
  head->next = NULL;
  return head;
}

// inserts new node to the head of the linked list
void push(Node** list, int n) {
  Node* new = create(n);
  new->next = *list;
  *list = new;
}

// inserts new node to the end of the linked list
void append(Node** list, int n) {
  if (*list == NULL) {
    push(list, n);
    return;
  }
  Node* new = create(n);
  Node* cur = *list;
  while (cur != NULL) {
    if (cur->next == NULL) {
      cur->next = new;
      break;
    }
    cur = cur->next;
  }
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
int shift(Node** list) {
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
int pop(Node** list) {
  if (*list == NULL || (*list)->next == NULL){
    return shift(list);
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
    int p = shift(list);
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
