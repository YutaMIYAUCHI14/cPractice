#define TRUE 1
#define FALSE 0

typedef struct node
{
  struct node *next;
  int value;
} NODE;

typedef struct stack
{
  NODE *root;
} STACK;

STACK *newStack(void);

void stackPush(STACK *sp, int v);

int stackPop(STACK *sp);

int stackElement(STACK *sp);

int stackIsEmpty(STACK *sp);

int stackIsFull(STACK *sp);

