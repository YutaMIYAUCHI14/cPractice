#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"

#define HASH_TABLE_SIZE 4441

typedef struct wordcountlist
{
  struct wordcountlist *next;
  WORDCOUNT info;
} WORDCOUNTLIST;

WORDCOUNTLIST *HashTable[HASH_TABLE_SIZE];

void wordcountInit(void)
{
  int i;

  for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
      HashTable[i] = NULL;
    }
}

unsigned int hash(char *s)
{
  unsigned int v;

  for(v = 0; *s != '\0'; s++)
    {
      v = (v << 2) + *s;
    }

  return v % HASH_TABLE_SIZE;
}

WORDCOUNT *wordcountSearch(char *word)
{
  unsigned int hash_value;
  WORDCOUNTLIST *wcl;

  hash_value = hash(word);
  if(HashTable[hash_value] != NULL)
    {
      for(wcl = HashTable[hash_value]; wcl != NULL; wcl = wcl->next)
	{
	  if(strcmp(word, wcl->info.word) == 0)
	    {
	      return &(wcl->info);
	    }
	}
    }
  return  NULL;
}

void wordcountRegister(char *word)
{
  WORDCOUNT *id;
  WORDCOUNTLIST *wcl;
  unsigned int hash_value;

  if((id = wordcountSearch(word)) != NULL)
    {
      id->count++;
    }
  else
    {
      wcl = (WORDCOUNTLIST *)malloc(sizeof(WORDCOUNTLIST));
      strcpy(wcl->info.word, word);
      wcl->info.count = 1;
      hash_value = hash(word);
      HashTable[hash_value] = wcl;
    }
}

void wordcountStatistics(void)
{
  int i;
  WORDCOUNTLIST *wcl;

  for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
      for(wcl = HashTable[i]; wcl != NULL; wcl = wcl->next)
	{
	  printf("%5d: %s\n", wcl->info.count, wcl->info.word);
	}
    }
}
    
	
	
