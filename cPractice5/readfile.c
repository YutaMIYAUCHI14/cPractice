#include <stdio.h>
#include <stdlib.h>

#include "kion-htmlreport.h"

int readfile(char filename[], struct kisyou array[], int amax)
{
  FILE *fp;
  int month, day, hour;
  double data;
  int size;

  if((fp = fopen(filename, "r")) == NULL)
    {
      fprintf(stderr, "Error: File Open\n");
      exit(1);
    }
  size = 0;
  while(fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF)
    {
      if(size >= amax)
	{
	  fprintf(stderr, "Error: Cant Open\n");
	  exit(2);
	}
      array[size].month = month;
      array[size].day = day;
      array[size].hour = hour;
      array[size].kion = data;
      size++;
    }
  fclose(fp);

  return size;
}
