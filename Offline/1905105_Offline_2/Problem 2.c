#include <stdio.h>
#include <string.h>
int main()
{
    char s1[501],s2[101],s3[11];
    int i,j,k,m,n,c,l,p,y;
    gets(s1);
    gets(s2);
    gets(s3);
    l=strlen(s1);
    m=strlen(s2);
    n=strlen(s3);
    for(i=0;s1[i]!='\0';){
        y=0;
        if(s1[i]==s2[0]){
            j=0;
            c=0;
            while(s1[i+j]==s2[j]&&j<m){
                c++;
                j++;
            }
            if(c==m){
                y=1;
                if(m==n){
                    for(j=0;j<n;j++)
                        s1[i+j]=s3[j];
                    i+=n;
                }
                if(m>n){
                    p=m-n;
                    for(j=0;j<n;j++)
                        s1[i+j]=s3[j];
                    i+=n;
                    for(k=0;s1[i+k]!='\0';k++)
                        s1[i+k]=s1[i+k+p];
                }
                if(m<n){
                    p=n-m;
                    for(k=0;i+n-p<=l-k;k++)
                        s1[l-k+p]=s1[l-k];
                    for(j=0;j<n;j++)
                        s1[i+j]=s3[j];
                   // printf("%s\n",s1);
                    i+=n;
                    l=l+p;
                }
            }
        }
        if(y==0)
            i++;
    }
    printf("%s",s1);
    return 0;
}
