#include <stdio.h>
#include <stdlib.h>

double kion_heikin(double array[], int size)
{
  int i;
  double sum, ave;

  sum = 0.0;
  for(i = 0; i < size; i++)
    {
      sum += array[i];
    }
  ave = sum / (double)size;

  return ave;
}

double kion_max(double array[], int size)
{
  int i;
  double max;

  max = array[0];
  for(i = 1; i < size; i++)
    {
      if(array[i] > max)
	{
	  max = array[i];
	}
    }

  return max;
}

double kion_min(double array[], int size)
{
  int i;
  double min;

  min = array[i];
  for(i = 1; i < size; i++)
    {
      if(array[i] < min)
	{
	  min = array[i];
	}
    }

  return min;
}

struct kisyou
{
  int month;
  int day;
  int hour;
  double kion;
};

int readfile(char filename[], struct kisyou array[], int amax)
{
  FILE *fp;
  int month, day, hour;
  double data;
  int size;

  if((fp = fopen(filename, "r")) == NULL)
    {
      fprintf(stderr, "Error: File Opem\n");
      exit(1);
    }
  size = 0;
  while(fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF)
    {
      if(size >= amax)
	{
	  fprintf(stderr, "Error: Cant Read\n");
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

#define MAXFILENAME 100
#define ARRAYSIZE 10000
#define DAYARRAY 24

int main(void)
{
  char filename[MAXFILENAME];
  struct kisyou kisyoudata[ARRAYSIZE];
  double kion[DAYARRAY];
  int size;
  int month, day;
  int i, j;

  fprintf(stderr, "Data File Name: ");
  scanf("%s", filename);
  size = readfile(filename, kisyoudata, ARRAYSIZE);
  while(1)
    {
      fprintf(stderr, "Month & Day: ");
      scanf("%d %d", &month, &day);
      if(month == 0)
	{
	  fprintf(stderr, "Finish Search\n");
	  break;
	}
      for(i = 0; i < size; i++)
	{
	  if(kisyoudata[i].month == month && kisyoudata[i].day == day)
	    {
	      for(j = 0; j < DAYARRAY; j++)
		{
		  if(kisyoudata[i].hour == j)
		    {
		      kion[j] = kisyoudata[i].kion;
		    }
		}
	    }
	}
      printf("%d %d: %lf, %lf, %lf\n", month, day, kion_heikin(kion, DAYARRAY), kion_max(kion, DAYARRAY), kion_min(kion, DAYARRAY));
    }

  return 0;
}
