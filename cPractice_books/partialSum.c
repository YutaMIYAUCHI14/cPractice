#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int N, W;
    printf("please input number N, W: ");
    scanf("%d %d", &N, &W);
    printf("\n");

    int a[N];
    printf("please input %d number.\n", N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    bool ans;

    for(int bit = 0; bit < (1 << N); bit++)
    {
        int sum = 0;
        for(int i = 0; i < N; i++)
        {
            if(bit & (1 << i))
            {
                sum += a[i];
            }
        }
        if(sum == W)
        {
            ans = true;
        }
    }

    if(ans == true)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}