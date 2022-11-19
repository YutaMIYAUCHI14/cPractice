#include <stdio.h>

#include "kion-htmlreport.h"

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
