#include <stdio.h>

#include "kion-htmlreport.h"
#include "kionstat.h"

#define DAYARRAY 24

void html_report(struct kisyou array[], int size)
{
  double kion[DAYARRAY];
  int i, di;
  double max, min, range;
  char *str;

  printf("<HTML>\n<HEAD>\n");
  printf("<TITLE>Kion Data</TITLE>\n");
  printf("</HEAD>\n");
  printf("<BODY>\n");
  printf("<H1>Daily Kion Data Statistics</H1>\n");
  printf("<TABLE border = 1>\n");
  printf("<TR><TH>month&day</TH><TH>heikin</TH><TH>max</TH><TH>min</TH><TH>range</TH></TR>\n");
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
      printf("<TR%s><TH>%d %d</TD><TD>%.1f</TD><TD>%.1f</TD><TD>%.1f</TD><TD>%.1f</TD></TR>\n", str, array[i].month, array[i].day, kion_heikin(kion, DAYARRAY), max, min, range);
    }
  printf("</TABLE>\n");
  printf("</BODY>\n");
  printf("</HTML>\n");
}
