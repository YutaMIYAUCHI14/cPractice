#define TRUE 1
#define FALSE 0

#define MAXSTACK 100

typedef struct stack
{
  int data[MAXSTACK];
  int index;
} STACK;

STACK *newStack(void);

void stackPush(STACK *sp, int v);

int stackPop(STACK *sp);

int stackElement(STACK *sp);

int stackIsEmpty(STACK *sp);

int stackIsFull(STACK *sp);
