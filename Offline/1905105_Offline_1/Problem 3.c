#include <stdio.h>

int main()
{
    int a[100],n,max=0,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);                              //array input
    }
    for(i=1;i<n;i++){
        if(a[max]<a[i])
            max=i;                                      //finding maximum
    }
    for(i=0;i<a[max];i++){                              //loop for row
        k=a[max]-i;
        for(j=0;j<n;j++){                               //loop for column
            if(k<=a[j])
                printf("** ");
            else
                printf("   ");
        }
        printf("\n");
    }
    return 0;
}
