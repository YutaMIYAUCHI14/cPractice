#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXVECTORSIZE 100000

int maxDigit(int num)
{
    int copy = num;
    int count = 0;

    while(num != 0)
    {
        num /= 10;
        ++count;
    }
    return count;
}

int getDigits(int num, int down, int up)
{
    int copy = num;
    int underNum;
    int ans;

    copy = abs(copy);
    underNum = copy % (int)pow(10, up);
    ans = underNum / pow(10, down-1);

    return ans;
}

bool detect753(int num)
{
    int digit = maxDigit(num);
    int anum;
    bool flag3 = false;
    bool flag5 = false;
    bool flag7 = false;

    for(int i = 1; i <= digit; i++)
    {
        anum = getDigits(num, i, i);
        if(anum == 3)
        {
            flag3 = true;
        }
        else if(anum == 5)
        {
            flag5 = true;
        }
        else if(anum == 7)
        {
            flag7 = true;
        }
    }
    if(flag3 && flag5 && flag7)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    int k;
    bool ans;

    printf("please input number ! : ");
    scanf("%d", &k);
    printf("\n");
    ans = detect753(k);
    if(ans == true)
    {
        printf("%d is 753 number.\n", k);
    }
    else
    {
        printf("%d is not 753 number.\n", k);
    }

    return 0;
}