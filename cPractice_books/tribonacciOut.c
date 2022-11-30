#include <stdio.h>

#define MAXVECTORSIZE 10000

int tribonacci(int N, int memo[])
{
    if(N == 0)
    {
        return 0;
    }
    else if(N == 1)
    {
        return 0;
    }
    else if(N == 2)
    {
        return 1;
    }
    if(memo[N] != -1)
    {
        return memo[N];
    }
    else
    {
        memo[N - 1] = tribonacci(N - 1, memo);
        memo[N - 2] = tribonacci(N - 2, memo);
        memo[N - 3] = tribonacci(N - 3, memo);
        memo[N] = memo[N - 1] + memo[N - 2] + memo[N - 3];
        return memo[N];
    }
}

int main(void)
{
    int n;
    int tri[MAXVECTORSIZE];

    printf("please input number ! : ");
    scanf("%d", &n);
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        tri[i] = -1;
    }

    tri[n-1] = tribonacci(n-1, tri);

    printf("tribonacci to %d\n", n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", tri[i]);
    }
    printf("\n");

    return 0;
}