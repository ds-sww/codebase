#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,k;
int a[100001],b[100001],order[100001];
void qs_a(int l,int r)
{
	int i=l,j=r;
	int step=a[l];
	while(i<=j)
	{
		while(i<=j&&a[i]>step) i++;
		while(i<=j&&step>a[j]) j--;
		if(i<=j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			temp=b[i];
			b[i]=b[j];
			b[j]=temp;
			temp=order[i];
			order[i]=order[j];
			order[j]=temp;
			i++;j--;
		}
	}
	if(l<j)
	qs_a(l,j);
	if(i<r)
	qs_a(i,r);
}
void qs_b(int l,int r)
{
	int i=l,j=r;
	int step=b[l];
	while(i<=j)
	{
		while(i<=j&&b[i]>step) i++;
		while(i<=j&&step>b[j]) j--;
		if(i<=j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			temp=b[i];
			b[i]=b[j];
			b[j]=temp;
			temp=order[i];
			order[i]=order[j];
			order[j]=temp;
			i++;j--;
		}
	}
	if(l<j)
	qs_b(l,j);
	if(i<r)
	qs_b(i,r);
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		order[i]=i+1;
	}
	qs_a(0,n-1);
	qs_b(0,k-1);
	printf("%d\n",order[0]);
	return 0;
}
