#include <stdio.h>
#include <stdlib.h>

int readfile(char filename[], double array[], int amax)
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
	  fprintf(stderr, "Error: Cant open\n");
	  exit(2);
	}
      array[size] = data;
      size++;
    }
  fclose(fp);

  return size;
}

#define MAXFILENAME 100
#define ARRAYSIZE 10000

int main(void)
{
  char filename[MAXFILENAME];
  double kion[ARRAYSIZE];
  int size;
  int i;

  fprintf(stderr, "Data File Name: ");
  scanf("%s", filename);
  size = readfile(filename, kion, ARRAYSIZE);
  for(i = 0; i < size; i++)
    {
      printf("kion[%d]: %.1f\n", i, kion[i]);
    }

  return 0;
}
