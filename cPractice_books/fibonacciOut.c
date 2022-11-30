#include <stdio.h>

#define MAXVECTORSIZE 10000

int fibo[MAXVECTORSIZE]; 

int fibonacci(int N)
{
    if(N == 0)
    {
        fibo[N] = 0;
        return fibo[N];
    }
    else if(N == 1)
    {
        fibo[N] = 1;
        return fibo[N];
    }
    if(fibo[N] != -1)
    {
        return fibo[N];
    }
    else
    {
        fibo[N - 1] = fibonacci(N - 1);
        fibo[N - 2] = fibonacci(N - 2);
        fibo[N] = fibo[N - 1] + fibo[N - 2];
        return fibo[N];
    }
}

int main(void)
{
    int n;

    printf("please input number ! : ");
    scanf("%d", &n);
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        fibo[i] = -1;
    }

    fibo[n-1] = fibonacci(n-1);

    printf("fibonacci to %d\n", n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", fibo[i]);
    }
    printf("\n");

    return 0;
}