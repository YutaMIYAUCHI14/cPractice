#define MAXWORDSIZE 100

typedef struct wordcount
{
  char word[MAXWORDSIZE];
  int count;
} WORDCOUNT;

void wordcountInit(void);
WORDCOUNT *wordcountSearch(char *word);
void wordcountRegister(char *word);
void wordcountStatistics(void);
