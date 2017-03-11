#include <stdlib.h>
#include "queue.h"

//creates a Q
Q* create_q(int n) {
  Q* q = malloc(sizeof* q);
  q->_q = create(n);
  return q;
}

//add a item to the end of a Q
void enqueue(Q* q, int n) {
  append(q->_q, n);
}

//dequeue the first item in Q
int dequeue(Q* q) {
  return shift(q->_q);
}

//peek the first item in Q, keeps the Q intact
int peek(Q* q) {
  return q->_q->head->val;
}

//peek the first item in Q, keeps the Q intact
int size_q(Q* q) {
  return size(q->_q);
}
