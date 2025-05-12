#include <stdio.h>

int main()
{
    int i;
    float x,t,r,s=0;
    scanf("%f",&x);
    x=(x*3.1416)/180;
    t=x;
    s=x;
    for(i=1;i<100;i++){
        r=-(x*x)/(2*i*(2*i+1));
        t=r*t;
        s=s+t;
    }
    printf("%f",s);
    return 0;
}
