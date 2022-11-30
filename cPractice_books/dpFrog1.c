#include <stdio.h>
#include <stdlib.h>

#define INF 999999

int min(int a, int b)
{
    if(a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main(void)
{
    int N;
    printf("please input number N: ");
    scanf("%d", &N);
    printf("\n");

    int h[N];
    printf("please input %d number h\n", N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &h[i]);
    }
    printf("\n");

    int dp[N];
    for(int i = 0; i < N; i++)
    {
        dp[i] = INF;
    }
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < N; i++)
    {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    printf("%d\n", dp[N - 1]);
}