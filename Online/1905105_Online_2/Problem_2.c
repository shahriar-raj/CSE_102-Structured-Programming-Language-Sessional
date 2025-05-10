#include <stdio.h>

int main()
{
    int lcm, large, num, small;
    scanf("%d", &lcm);
    printf("LCM of all numbers up to now is %d\n", lcm);
    for (;;)
    {
        scanf("%d", &num);
        if (lcm > num)
        {
            large = lcm;
            small = num;
        }
        else
        {
            large = num;
            small = lcm;
        }
        int temp = large;
        while (large % small != 0)
        {
            large += temp;
        }
        lcm = large;
        printf("LCM of all numbers up to now is %d\n", lcm);
    }
    return 0;
}
