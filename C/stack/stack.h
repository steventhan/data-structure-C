//represents a node in a stack
typedef struct Node {
  int val;
  struct Node* next;
} Node;

//represents a stack
typedef struct Stack {
  struct Node* top;
} Stack;

Node* _create_node(int n);
Stack* create(int n);
void push(Stack* s, int n);
int pop(Stack* s);
int peek(Stack* s);
