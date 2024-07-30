#include <stdio.h>
#include <string.h>


int a[5][5],b[5][5],ay=0,by=0,r_a,r_b,c_a,c_b,count=0,n=0,k=0,stop=0;


int add(int x[][5], int y[][5], int r1, int r2, int c1, int c2)
{
    int i,j,s;
    if(r1!=r2||c1!=c2)
        printf("Addition not possible\n");
    else{
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                s = x[i][j]+y[i][j];
                printf("%d ",s);
            }
            printf("\n");
        }
    }
    return 0;
}


int sub(int x[][5], int y[][5], int r1, int r2, int c1, int c2)
{
    int i,j,s;
    if(r1!=r2||c1!=c2)
        printf("Subtraction not possible\n");
    else{
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                s = x[i][j]-y[i][j];
                printf("%d ",s);
            }
            printf("\n");
        }
    }
    return 0;
}


int mult(int x[][5], int y[][5], int r1, int r2, int c1, int c2)
{
    int i,j,k,l,c[5][5]={0};
    if(c1!=r2)
        printf("Multiplication not possible\n");
    else{
        for(i=0;i<r1;i++){
            for(l=0;l<c2;l++){
                for(j=0;j<r2;j++)
                    c[i][l]+=(x[i][j]*y[j][l]);
            }
        }
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }
    }
    return 0;
}


int div(int x[][5], int r, int c, int n_)
{
    int i,j,d;
    for(i=0;i<r;i++){
        if(!n_){
        printf("Division not possible\n");
        break;
        }
        for(j=0;j<c;j++){
            printf("%g ",x[i][j]/(n_*1.00));
        }
        printf("\n");
    }
    return 0;
}

int det(int x[][5], int r, int c)
{
    int s;
    if(r!=c)
        printf("Determinant not possible\n");
    else if(r==1)
        printf("%d\n",x[0][0]);
    else if(r==2){
        s=x[0][0]*x[1][1]-x[0][1]*x[1][0];
        printf("%d\n",s);
    }
    else if(r==3){
        s=x[0][0]*(x[1][1]*x[2][2]-x[1][2]*x[2][1])-x[0][1]*(x[1][0]*x[2][2]-x[1][2]*x[2][0])+x[0][2]*(x[1][0]*x[2][1]-x[1][1]*x[2][0]);
        printf("%d\n",s);
    }
    return 0;
}

int trans(int x[][5], int r, int c)
{
    int i,j;
    for(j=0;j<c;j++){
        for(i=0;i<r;i++)
            printf("%d ",x[i][j]);
        printf("\n");
    }
    return 0;
}


int main()
{
     while(1){
        char s[100],c,d;
        int i,j;
        gets(s);
        strupr(s);
        for(i=0;s[i]!=0;){
            if(s[i]==' '){
                for(j=i;s[j]!=0;j++)
                    s[j]=s[j+1];
            }
            else
                i++;
        }
        c=s[0];
        switch(c)
        {
        case 'I' :
            d=s[2];
            switch(d)
            {
            case 'A' :
               ay=1;
               scanf("%d%d",&r_a,&c_a);
               for(i=0;i<r_a;i++){
                    for(j=0;j<c_a;j++)
                        scanf("%d",&a[i][j]);
               }
               break;
            case 'B' :
               by=1;
               scanf("%d%d",&r_b,&c_b);
               for(i=0;i<r_b;i++){
                    for(j=0;j<c_b;j++)
                        scanf("%d",&b[i][j]);
               }
               break;
            }
            break;
        case 'O' :
            d=s[3];
            switch(d)
            {
            case 'A' :
               if(ay){
                   for(i=0;i<r_a;i++){
                        for(j=0;j<c_a;j++)
                            printf("%d ",a[i][j]);
                        printf("\n");
                   }
               }
               else
                printf("No A matrix found\n");
               break;
            case 'B' :
               if(by){
                   for(i=0;i<r_b;i++){
                        for(j=0;j<c_b;j++)
                            printf("%d ",b[i][j]);
                        printf("\n");
                   }
               }
               else
                printf("No B matrix found\n");
               break;
            }
            break;
        case 'T' :
            d=s[5];
            switch(d)
            {
            case 'A' :
                if(ay)
                    trans(a, r_a, c_a);
                else
                    printf("No A matrix found\n");
                break;
            case 'B' :
                if(by)
                    trans(b, r_b, c_b);
                else
                    printf("No B matrix found\n");
                break;
            }
            break;
        case 'A' :
              d=s[1];
              switch(d)
              {
              case '+' :
                if(ay&&by)
                    add(a, b, r_a, r_b, c_a, c_b);
                else if(!ay)
                    printf("No A matrix found\n");
                else
                    printf("No B matrix found\n");
                break;
              case '-' :
                if(ay&&by)
                    sub(a, b, r_a, r_b, c_a, c_b);
                else if(!ay)
                    printf("No A matrix found\n");
                else
                    printf("No B matrix found\n");
                break;
              case '*' :
                if(ay&&by)
                    mult(a, b, r_a, r_b, c_a, c_b);
                else if(!ay)
                    printf("No A matrix found\n");
                else
                    printf("No B matrix found\n");
                break;
              case '/' :
                if(ay){
                    n=0;
                    count=0;
                    if(s[2]=='-'){
                        for(i=3;s[i]!=0;i++)
                            count++;
                        for(k=0;k<count;k++){
                            int t= s[3+k] - 48;
                        n -= t - n*10;
                        }
                    }
                    else{
                        for(i=2;s[i]!=0;i++)
                            count++;
                        for(k=0;k<count;k++){
                            int t= s[2+k] - 48;
                            n += t + n*10;
                        }
                    }
                    div(a, r_a, c_a, n);
                }
                else
                    printf("No A matrix found\n");
                break;
              }
            break;
        case 'B' :
              d=s[1];
              switch(d)
              {
              case '+' :
                if(ay&&by)
                    add(a, b, r_a, r_b, c_a, c_b);
                else if(!by)
                    printf("No B matrix found\n");
                else
                    printf("No A matrix found\n");
                break;
              case '-' :
                if(ay&&by)
                    sub(b, a, r_b, r_a, c_b, c_a);
                else if(!by)
                    printf("No B matrix found\n");
                else
                    printf("No A matrix found\n");
                break;
              case '*' :
                if(ay&&by)
                    mult(b, a, r_b, r_a, c_b, c_a);
                else if(!by)
                    printf("No B matrix found\n");
                else
                    printf("No A matrix found\n");
                break;
              case '/' :
                if(ay){
                    n=0;
                    count=0;
                    if(s[2]=='-'){
                        for(i=3;s[i]!=0;i++)
                            count++;
                        for(k=0;k<count;k++){
                            int t= s[3+k] - 48;
                        n -= t - n*10;
                        }
                    }
                    else{
                        for(i=2;s[i]!=0;i++)
                            count++;
                        for(k=0;k<count;k++){
                            int t= s[2+k] - 48;
                            n += t + n*10;
                        }
                    }
                    div(b, r_b, c_b, n);
                }
                else
                    printf("No B matrix found\n");
                break;
              }
            break;
        case 'E' :
            stop=1;                                                // this will make stop = 1
            break;
        case 'D' :
              d=s[3];
              switch(d)
              {
              case 'A' :
                if(ay){
                    det(a, r_a, c_a);
                }
                else
                    printf("No A matrix found\n");
                break;
              case 'B' :
                if(by){
                    det(b, r_b, c_b);
                }
                else
                    printf("No B matrix found\n");
                break;
              }
            break;
        }

        if(stop)
            break;                                                    //if stop is 1 then it will exit the prompt
    }
    return 0;
}
