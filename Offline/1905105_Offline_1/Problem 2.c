#include <stdio.h>

int isperf(int x);

int isperf(int x)
{
    int s=0,j;
    for(j=1;j<x;j++){                                                       //function for determining perfect number
        if(x%j==0)
            s+=j;
    }
    if(s==x)
        return 1;
    else
        return 0;
}

int main()
{
    int n,i,p,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        p=isperf(i);
        if(p)
            sum+=i;
    }
    printf("%d",sum);
    return 0;
}

