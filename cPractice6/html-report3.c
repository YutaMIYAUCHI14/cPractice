#include <stdio.h>
#include <stdlib.h>

#include "kion-htmlreport.h"
#include "kionstat.h"

#define DAYARRAY 24

void html_report(struct kisyou array[], int size)
{
  FILE *fp;
  double kion[DAYARRAY];
  int i, di;
  double max, min, range;
  char *str;
  char filename[] = "report.html";

  if((fp = fopen(filename, "w")) == NULL)
    {
      fprintf(stderr, "Error: Open Error %s\n", filename);
      exit(1);
    }
  fprintf(fp, "<HTML>\n<HEAD>\n");
  fprintf(fp, "<TITLE>Kion Data</TITLE>\n");
  fprintf(fp, "</HEAD>\n");
  fprintf(fp, "<BODY>\n");
  fprintf(fp, "<H1>Daily Kion Data Statistics</H1>\n");
  fprintf(fp, "<TABLE border = 1>\n");
  fprintf(fp, "<TR><TH>month&day</TH><TH>heikin</TH><TH>max</TH><TH>min</TH><TH>range</TH></TR>\n");
  for(i = 0; i < size; i += DAYARRAY)
    {
      for(di = 0; di < DAYARRAY; di++)
	{
	  kion[di] = array[i + di].kion;
	}
      max = kion_max(kion, DAYARRAY);
      min = kion_min(kion, DAYARRAY);
      range = max - min;
      if(range >= 15)
	{
	  str = " bgcolor=red";
	}
      else
	{
	  str = "";
	}
      fprintf(fp, "<TR%s><TH>%d %d</TD><TD>%.1f</TD><TD>%.1f</TD><TD>%.1f</TD><TD>%.1f</TD></TR>\n", str, array[i].month, array[i].day, kion_heikin(kion, DAYARRAY), max, min, range);
    }
  fprintf(fp, "</TABLE>\n");
  fprintf(fp, "</BODY>\n");
  fprintf(fp, "</HTML>\n");
}
