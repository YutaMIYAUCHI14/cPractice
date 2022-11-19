#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "liststack.h"

#define MAXLINE 200

int main(void)
{
  char buff[MAXLINE];
  int i, j, size;
  STACK *stk;

  stk = newStack();
  while(fgets(buff, MAXLINE, stdin) != NULL)
    {
      for(i = 0, j = 0; buff[i] != '\0'; i++)
	{
	  if(isalnum(buff[i]))
	    {
	      buff[j++] = toupper(buff[i]);
	    }
	}
      buff[j] = '\0';
      size = strlen(buff);
      for(i = 0; i < size / 2; i++)
	{
	  stackPush(stk, buff[i]);
	}
      if((size % 2) == 1)
	{
	  i++;
	}
      for(i = i; i < size; i++)
	{
	  if(stackPop(stk) != buff[i])
	    {
	      while(!stackIsEmpty(stk))
		{
		  stackPop(stk);
		}
	      printf("回文ではありません\n");
	      break;
	    }
	}
    }

  return 0;
}
