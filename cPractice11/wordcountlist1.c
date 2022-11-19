#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"

typedef struct wordcountlist
{
  struct wordcountlist *next;
  WORDCOUNT info;
} WORDCOUNTLIST;

WORDCOUNTLIST *root;

void wordcountInit(void)
{
  root = NULL;
}

WORDCOUNT *wordcountSearch(char *word)
{
  WORDCOUNTLIST *wcl;

  for(wcl = root; wcl != NULL; wcl = wcl->next)
    {
      if(strcmp(word, wcl->info.word) == 0)
	{
          return &(wcl->info);
	}
    }
  return NULL;
}

void wordcountRegister(char *word)
{
  WORDCOUNT *id;
  WORDCOUNTLIST *wcl;

  if((id = wordcountSearch(word)) != NULL)
    {
      id->count++;
    }
  else
    {
      wcl = (WORDCOUNTLIST *)malloc(sizeof(WORDCOUNTLIST));
      strcpy(wcl->info.word, word);
      wcl->info.count = 1;
      wcl->next = root;
      root = wcl;
    }
}

void wordcountStatistics(void)
{
  WORDCOUNTLIST *wcl;

  for(wcl = root->next; wcl != NULL; wcl = wcl->next)
    {
      printf("%5d: %s\n", wcl->info.count, wcl->info.word);
    }
}
      
	
