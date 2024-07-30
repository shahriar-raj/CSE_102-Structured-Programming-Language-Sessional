#include <stdio.h>

typedef struct _complex{
    double r,i;
}comp;

void print(comp x)
{
    if(x.i>0)
    printf("%.2lf+%.2lfi\n",x.r,x.i);
    else
    printf("%.2lf%.2lfi\n",x.r,x.i);
}

comp multiply(comp x,comp y)
{
    comp m;
    m.r=(x.r*y.r)-(x.i*y.i);
    m.i=(x.r*y.i)+(x.i*y.r);
    return m;
}

comp divide(comp x,comp y)
{
    comp d,yc,z;
    yc.r=y.r;
    yc.i= (-1*y.i);
    d=multiply(x,yc);
    z=multiply(y,yc);
    d.r=d.r/z.r;
    d.i=d.i/z.r;
    return d;
}
int main()
{
    comp x,y,m,d;
    scanf("%lf %lf %lf %lf",&x.r,&x.i,&y.r,&y.i);
    m=multiply(x,y);
    print(m);
    d=divide(x,y);
    print(d);
    return 0;
}

