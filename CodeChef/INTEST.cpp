#include<stdio.h>
int main()
{
	unsigned long int n,k,p,i;
	int cnt=0;
	scanf("%lu%lu",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lu",&p);
		if(p%k==0)
			cnt++;
	}
	printf("%d",cnt);
	return 0;
} 