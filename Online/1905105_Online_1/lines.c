#include <stdio.h>
int main()
{
	int a1,b1,c1,a2,b2,c2;
	float x,y;
	scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
	if(a1*b2==a2*b1)
		printf("Does not intersect");
	else{
		x=(((b1*c2)-(b2*c1))*1.000)/((a1*b2)-(b1*a2));
		y=(((c1*a2)-(c2*a1))*1.000)/((a1*b2)-(b1*a2));
		printf("Intersection point: %.3f %.3f",x,y);
	}

	return 0;
}
