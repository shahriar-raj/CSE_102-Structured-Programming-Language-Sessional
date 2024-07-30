#include <stdio.h>

int bin(int n)
{
    int c=0;
    for(;n!=0;){
        if(n%2==1)
            c++;
        n=n/2;
        }
    return c;
}

int fact(int n)
{
    int c=0,i;
    for(i=1;i<=n;i++){
        if(n%i==0)
            c++;
    }
    return c;
}

int main()
{
    int x,a[1000],j,k,max,t;
    scanf("%d",&x);
    for(j=0;j<x;j++){
        scanf("%d",&a[j]);
    }
    for(j=x;j>0;j--){
        max=0;
        for(k=1;k<j;k++){
            if(bin(a[k])>bin(a[max]))
                max=k;
            else if(bin(a[k])==bin(a[max])){
                if(fact(a[k])<fact(a[max]))
                    max=k;
                else if(fact(a[k])==fact(a[max])){
                    if(a[k]>a[max])
                        max=k;
                }
            }
        }
    t=a[max];
    a[max]=a[j-1];
    a[j-1]=t;
    }
    for(j=0;j<x;j++){
        printf("%d ",a[j]);
    }
    return 0;
}
