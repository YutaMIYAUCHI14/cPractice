#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zipcount-sub.h"

int main(void)
{
  FILE *fp;
  char buff[MAXLINE];
  char prefname[MAXPREFNAME];
  struct pref_zip_count zip_count[MAXPREFNUM];
  int index, prefcount;

  if((fp = fopen("YUBIN.csv", "r")) == NULL)
    {
      fprintf(stderr, "Error: File Open\n");
      exit(1);
    }
  prefcount = 0;
  while(fgets(buff, MAXLINE, fp) != NULL)
    {
      sscanf(buff, "%*d, %*[^,], %[^,]", prefname);
      if((index = zip_pref_search(zip_count, prefcount, prefname)) != NOT_FOUND)
	{
	  zip_count[index].zipcount++;
	}
      else
	{
	  zip_pref_add(zip_count, prefcount, prefname);
	  prefcount++;
	}
    }
  fclose(fp);
  zip_pref_html_print(zip_count, prefcount);

  return 0;
}
