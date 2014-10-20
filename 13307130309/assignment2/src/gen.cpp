#include<stdio.h>
#include<stdlib.h>
int n;
int main()
{
	int i;
	freopen("input.txt","w",stdout);
	n=0;
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		printf("%d ",rand()+1);
	}
	return 0;
}
