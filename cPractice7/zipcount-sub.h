#define MAXLINE 200
#define MAXPREFNAME 20
#define MAXPREFNUM 100

struct pref_zip_count
{
  char pref_name[MAXPREFNAME];
  int zipcount;
};

#define NOT_FOUND -1

int zip_pref_search(struct pref_zip_count data[], int size, char prefname[]);
void zip_pref_add(struct pref_zip_count data[], int pos, char prefname[]);
void zip_pref_print(struct pref_zip_count data[], int size);
void zip_pref_html_print(struct pref_zip_count data[], int size);

int zip_pref_search(struct pref_zip_count data[], int size, char prefname[])
{
  int i;

  for(i = 0; i < size; i++)
    {
      if(strcmp(prefname, data[i].pref_name) == 0)
	{
	  return i;
	}
    }

  return NOT_FOUND;
}

void zip_pref_add(struct pref_zip_count data[], int pos, char prefname[])
{
  strcpy(data[pos].pref_name, prefname);
  data[pos].zipcount = 1;
}

void zip_pref_print(struct pref_zip_count data[], int size)
{
  int i, prefcount;

  for(i = 0; i < size; i++)
    {
      printf("%d: %s\n", data[i].zipcount, data[i].pref_name);
    }
}

void zip_pref_html_print(struct pref_zip_count data[], int size)
{
  FILE *fp;
  int i, prefcount;
  char filename[] = "zip-pref-report.html";

  if((fp = fopen(filename, "w")) == NULL)
    {
      fprintf(stderr, "Error: Open Error\n", filename);
      exit(1);
    }
  fprintf(fp, "<HTML>\n<HEAD>\n");
  fprintf(fp, "<TITLE>Zip Pref Report</TITLE>\n");
  fprintf(fp, "</HEAD>\n");
  fprintf(fp, "<BODY>\n");
  fprintf(fp, "<TABLE border = 1>\n");
  fprintf(fp, "<TR><TH>zip</TH><TH>prefecture</TH></TR>\n");
  for(i = 0; i < size; i++)
    {
      fprintf(fp, "<TR><TD>%d</TD><TH>%s</TH></TR>\n", data[i].zipcount, data[i].pref_name);
    }
  fprintf(fp, "</TABLE>\n");
  fprintf(fp, "</BODY>\n");
  fprintf(fp, "</HTML>\n");
}

