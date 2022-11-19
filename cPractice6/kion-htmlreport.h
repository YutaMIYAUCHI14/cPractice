struct kisyou
{
  int month;
  int day;
  int hour;
  double kion;
};

int readfile(char filename[], struct kisyou array[], int amax);

void html_report(struct kisyou array[], int size);
