#include <stdio.h>
#include <string.h>

#include "arraystack.h"

#define MAXLINE 200

int main(void)
{
  char buff[MAXLINE];
  int i, size;
  STACK *checker;

  *checker = *newStack();
  while(fgets(buff, MAXLINE, stdin) != NULL)
    {
      size = strlen(buff);
      size--;
      for(i = 0; i < size / 2; i++)
	{
	  stackPush(checker, buff[i]);
	}
      if((size % 2) == 1)
	{
	  i++;
	}
      for(i = i; i < size; i++)
	{
	  if(stackPop(checker) != buff[i])
	    {
	      while(!stackIsEmpty(checker))
		{
		  stackPop(checker);
		}
	      printf("回文ではありません｡\n");
	      break;
	    }
	}
    }

  return 0;
}
