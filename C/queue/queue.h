#include "../doubly_linked_list/dll.h"

typedef struct Q {
  DLL* _q;
} Q;

Q* create_q(int n);
void enqueue(Q* q, int n);
int dequeue(Q* q);
int peek(Q* q);
int size_q(Q* q);
