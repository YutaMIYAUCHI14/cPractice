#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct struct_dummy 
{ 
    char nc; 
    struct struct_dummy *next; 
} Seq;


Seq *srchS(Seq *sq, char *startcdn);
Seq *srchE(Seq *sq, char *stopcdn[3]);

int main(char argc, char *argv[])
{
    char mrna[] = "GCAUGCAUGCGCAUGUGUAGGCAU";
    char startcdn[] = "AUG";
    char *stopcdn[3] = {"UAA", "UAG", "UGA"};
    Seq *sq1;
    Seq *pt;
    Seq *sq2;
    Seq *sq2stop;
    Seq *sq2end;
    int nth = 0;

    sq1 = (Seq *)malloc(sizeof(Seq));
    pt = sq1;
    for(nth = 0; nth < strlen(mrna)-1; nth = nth + 1)
    {
        pt->nc = mrna[nth];
        pt->next = (Seq *)malloc(sizeof(Seq));
        pt = pt->next;
    }
    pt->nc = mrna[nth];
    pt->next = NULL;

    sq2 = srchS(sq1, startcdn);
    if(sq2 == NULL)
    {
        printf("Start: Not Found\n");
    }
    else
    {
        sq2stop = srchE(sq2, stopcdn);
        if(sq2stop == NULL)
        {
            printf("Stop: Not Found\n");
        }
        else
        {
            sq2end = sq2stop->next->next->next;
            for(pt = sq2; pt != sq2end; pt = pt->next)
            {
                printf("%c", pt->nc);
            }
        }
    }

    return 0;
}

Seq *srchS(Seq *sq, char *startcdn)
{
    Seq *temp;

    temp = sq;
    while(temp != NULL)
    {
        if(temp->nc == startcdn[0])
        {
            if(temp->next->nc == startcdn[1])
            {
                if(temp->next->next->nc == startcdn[2])
                {
                    return temp;
                }
            }
        }
        temp = temp->next;
    }
    return NULL;
}

Seq *srchE(Seq *sq, char *stopcdn[3])
{
    Seq *temp;
    int count = 0;

    temp = sq;
    while(temp != NULL)
    {
        if(count%3 == 0)
        {
            for(int i = 0; i < 3; i++)
            {
                if(temp->nc == stopcdn[i][0])
                {
                    if(temp->next->nc == stopcdn[i][1])
                    {
                        if(temp->next->next->nc == stopcdn[i][2])
                        {
                            return temp;
                        }
                    }
                }
            }
        }
        temp = temp->next;
        count++;
    }
    return NULL;
}