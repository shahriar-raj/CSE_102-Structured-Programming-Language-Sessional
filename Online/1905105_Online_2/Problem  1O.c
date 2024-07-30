#include <stdio.h>

int main()
{
    int i,k,l,h,w,n=0;
    scanf("%d%d",&h,&w);
    for(i=1;i<=2*h;i++){
        if(i<=h+1){
                n=n+w;
                for(l=1;l<=2;l++){
                    for(k=1;k<=n;k++){
                        printf("*");
                    }
                    printf("\n");
                }
                i++;
              }
        else{
                n=n-w;
                for(l=1;l<=2;l++){
                    for(k=1;k<=n;k++){
                        printf("*");
                    }
                    printf("\n");
                }
                i++;
              }
    }
    return 0;
}
