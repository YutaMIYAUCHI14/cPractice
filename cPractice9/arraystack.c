#include <stdlib.h>

#include "arraystack.h"

STACK *newStack(void)
{
  STACK *sp;

  sp = (STACK *)malloc(sizeof(STACK));
  sp->index = 0;

  return sp;
}

void stackPush(STACK *sp, int v)
{
  sp->data[sp->index++] = v;
}

int stackPop(STACK *sp)
{
  return sp->data[--sp->index];
}

int stackElement(STACK *sp)
{
  return sp->index;
}

int stackIsEmpty(STACK *sp)
{
  if(sp->index <= 0)
    {
      return TRUE;
    }
  else
    {
      return FALSE;
    }
}

int stackIsFull(STACK *sp)
{
  if(sp->index >= MAXSTACK)
    {
      return TRUE;
    }
  else
    {
      return FALSE;
    }
}
