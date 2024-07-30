#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* prepend(char *p,char *q,int n)
{
    int plen,qlen,i;
    char *s;
    plen=strlen(p);
    qlen=strlen(q);
    s=(char*)malloc((plen+qlen-n+1)*sizeof(char));
    for(i=0;*q!='\0';i++){
        *(p+plen+i)=*q;
        q++;
    }
    *(p+plen+i)='\0';
    s=p+n;
    return s;
}

int main()
{
    int n;
    char *p,*q,*r;
    p = (char*)malloc(100*sizeof(char));
    q = (char*)malloc(100*sizeof(char));
    gets(p);
    gets(q);
    scanf("%d",&n);
    r= prepend(p,q,n);
    printf("%s",r);
    return 0;
}
