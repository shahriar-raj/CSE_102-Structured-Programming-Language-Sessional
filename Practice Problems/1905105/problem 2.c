#include <stdio.h>

int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=1;i<2*n;i++){
        if(i<=n){
            for(j=1;j<2*n;j++){
                if(j==n-i+1||j==n+i-1)
                    printf("*");
                else if(j>n-i+1&&j<n+i-1)
                    printf("-");
                else
                    printf(" ");
            }
        }
        else{
            k=2*n-i;
            for(j=1;j<2*n;j++){
                if(j==n-k+1||j==n+k-1)
                    printf("*");
                else if(j>n-k+1&&j<n+k-1)
                    printf("-");
                else
                    printf(" ");
           }
        }
        printf("\n");
    }
    return 0;
}
