#include <stdio.h>
#include <math.h>
int main()
{
	int x,y,r,x1,y1;
	float d;
	scanf("%d%d%d%d%d",&x,&y,&r,&x1,&y1);
	 d =sqrt(pow(x-x1,2)+pow(y-y1,2));
	if(d==r)
		printf("On the circle\n");
	else if(d<r)
		printf("Inside the circle\n");
	else if(d>r)
		printf("Outside the circle\n");
	return 0;
}
