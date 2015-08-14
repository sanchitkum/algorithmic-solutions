#include<stdio.h>
int main()
{
	int n,i,cnt;
	long unsigned no,div;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cnt=0;
		scanf("%lu",&no);
		for(div=5;div<=no;div*=5)
			cnt=cnt+(int)(no/div);
		printf("%lu\n",cnt);		
	}
	return 0;
} 