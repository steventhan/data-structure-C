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
