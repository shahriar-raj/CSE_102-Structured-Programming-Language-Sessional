#include <stdio.h>
#include <string.h>

char s1[30], s2[30];

int sub(int i, int j)
{
    int cnt = 0;
    // printf("%c %c\n", s1[i], s2[j]);
    if (s2[j] == '\0')
    {
        return 1;
    }
    if (s1[i] == '\0')
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        cnt += sub(i + 1, j + 1);
        cnt += sub(i + 1, j); // checks for further matchings
    }
    else
    {
        cnt += sub(i + 1, j);
    }
    return cnt;
}

int main()
{
    int i, j;
    int cnt = 0;
    gets(s1);
    gets(s2);
    cnt = sub(0, 0);
    printf("%d", cnt);
    return 0;
}
