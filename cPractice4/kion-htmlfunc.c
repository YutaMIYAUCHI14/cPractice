#include <stdio.h>
#include <stdlib.h>

double kion_heikin(double array[], int size)
{
  int i;
  double sum;

  sum = 0.0;
  for(i = 0; i < size; i++)
    {
      sum += array[i];
    }

  return sum / size;
}

double kion_max(double array[], int size)
{
  int i;
  double vmax;

  vmax = array[0];
  for(i = 1; i < size; i++)
    {
      if(array[i] > vmax)
	{
	  vmax = array[i];
	}
    }

  return vmax;
}

double kion_min(double array[], int size)
{
  int i;
  double vmin;

  vmin = array[0];
  for(i = 1; i < size; i++)
    {
      if(array[i] < vmin)
	{
	  vmin = array[i];
	}
    }

  return vmin;
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
      fprintf(stderr, "Error: File Open\n");
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

#define DAYARRAY 24

void html_report(struct kisyou array[], int size)
{
  double kion[DAYARRAY];
  int i, di;

  printf("<HTML>\n<HEAD>\n");
  printf("<TITLE>Kion Data</TITLE>\n");
  printf("</HEAD>\n");
  printf("<BODY>\n");
  printf("<H1>Daily Kion Data Statistics</H1>\n");
  printf("<TABLE border = 1>\n");
  printf("<TR><TH>month&day</TH><TH>heikin</TH><TH>max</TH><TH>min</TH></TR>\n");
  for(i = 0; i < size; i += DAYARRAY)
    {
      for(di = 0; di < DAYARRAY; di++)
	{
	  kion[di] = array[i + di].kion;
	}
      printf("<TR><TH>%d %d</TD><TD>%.1f</TD><TD>%.1f</TD><TD>%.1f</TD></TR>\n", array[i].month, array[i].day, kion_heikin(kion, DAYARRAY), kion_max(kion, DAYARRAY), kion_min(kion, DAYARRAY));
    }
  printf("</TABLE>\n");
  printf("</BODY>\n");
  printf("</HTML>\n");
}

#define MAXFILENAME 100
#define ARRAYSIZE 10000

int main(void)
{
  char filename[MAXFILENAME];
  struct kisyou kisyoudata[ARRAYSIZE];
  int size;

  fprintf(stderr, "Data File Name: ");
  scanf("%s", filename);
  size = readfile(filename, kisyoudata, ARRAYSIZE);
  html_report(kisyoudata, size);

  return 0;
}
