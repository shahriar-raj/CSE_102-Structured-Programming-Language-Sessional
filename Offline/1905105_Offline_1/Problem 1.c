#include <stdio.h>

 int main()
 {
     int a[20000]={0},n,p,i,j,k,max=0,c;
     scanf("%d",&n);
     for(i=0;i<n;i++){
        scanf("%d",&p);
        c=0;
        k=0;
        a[p+10000]=a[p+10000]+1;
        for(j=0;j<20000;j++){
            if(a[max]<a[j])
                max=j;
        }
        for(j=0;j<20000;j++){
            if(a[max]==a[j])
                c++;                                            //c for counting the number of modes
        }
        printf("Most frequent number=");
        for(j=0;j<20000;j++){
            if(a[max]==a[j]){
                printf("%d",j-10000);
                k++;
                if(k<c)
                    printf(", ");                              //when we print one mode k increases, if k becomes equal to c the comma and the space are not printed
            }
        }
        printf("\n");
     }
     return 0;
 }

