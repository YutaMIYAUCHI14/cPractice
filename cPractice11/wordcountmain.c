#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "wordcount.h"

int main(int argc, char *argv[])
{
  FILE *fp;
  char buff[MAXWORDSIZE];
  WORDCOUNT *id;
  int i;

  if(argc != 2)
    {
      fprintf(stderr, "Error: Specify File Name\n");
      exit(1);
    }
  if((fp = fopen(argv[1], "r")) == NULL)
    {
      fprintf(stderr, "Error: Cant Open File\n");
      exit(2);
    }
  wordcountInit();
  fscanf(fp, "%*[^A-Za-z]");
  while(fscanf(fp, "%[A-Za-z]%*[^A-Za-z]", buff) != EOF)
    {
      for(i = 0; buff[i] != '\0'; i++)
	{
	  buff[i] = tolower(buff[i]);
	}
      wordcountRegister(buff);
    }
  fclose(fp);
  wordcountStatistics();

  return 0;
}
