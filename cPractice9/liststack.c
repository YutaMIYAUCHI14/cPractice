#include <stdlib.h>

#include "liststack.h"

STACK *newStack(void)
{
  STACK  *sp;

  sp = (STACK *)malloc(sizeof(STACK));
  sp->root = NULL;

  return sp;
}

void stackPush(STACK *sp, int v)
{
  NODE *np;

  np = (NODE *)malloc(sizeof(NODE));
  np->value = v;
  np->next = sp->root;
  sp->root = np;
}

int stackPop(STACK *sp)
{
  int v;
  NODE *np;

  np = sp->root;
  sp->root = np->next;
  v = np->value;
  free(np);

  return v;
}

int stackElement(STACK *sp)
{
  int n;
  NODE *np;

  for(n = 0, np = sp->root; np != NULL; np = np->next)
    {
      n++;
    }

  return n;
}

int stackIsEmpty(STACK *sp)
{
  if(sp->root == NULL)
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
  return FALSE;
}
