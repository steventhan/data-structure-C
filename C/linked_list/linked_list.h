// represents a node in a linked list
typedef struct Node {
  int val;
  struct Node *next;
} Node;

Node* create(int n);
void push(Node** list, int n);
Node* search(Node* list, int n);
int size(Node* list);
int shift(Node** list);
int pop(Node** list);
void delete(Node** list, int n);
