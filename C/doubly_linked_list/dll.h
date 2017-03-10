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
void append(DLL* list, int n);
int size(DLL* list);
int pop(DLL* list);
int shift(DLL* list);
void delete(DLL* list, int n);
