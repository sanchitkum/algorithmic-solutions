#include<stdio.h>
int main()
{
	int x;
	float y;
	scanf("%d%f",&x,&y);
	if(x%5==0 && (y-x-.5>0))
	{
		y=y-x-.5;
	}
	printf("%.2f",y);
	return 0;
}   