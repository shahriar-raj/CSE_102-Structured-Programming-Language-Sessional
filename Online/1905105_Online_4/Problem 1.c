#include <stdio.h>
#include <string.h>

char s1[30],s2[30];

int sub(int a,int b)
{
    int i,j,p=0,count=0;
    for(i=a-1;i>=0;i--){
        for(j=b-1;j>=0;){
            if(s1[i]==s2[j]){
                    count++;
                    break;
            }
            else
                j--;
        }
    }
    if(count==b)
        p= 1+ sub(a-1,b-1);
    else
        return 0;
    return p;
}

int main()
{
    int m,n,s;
    gets(s1);
    gets(s2);
    m=strlen(s1);
    n=strlen(s2);
    s=sub(m,n);
    printf("%d",s);
    return 0;
}
