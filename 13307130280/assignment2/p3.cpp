#include<iostream>
using namespace std;
struct score
{
	int c,m,e,s,h;
};
score a[500],temp;
int n;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		a[i].h=i;
		cin>>a[i].c>>a[i].m>>a[i].e;
		a[i].s=a[i].c+a[i].m+a[i].e;
	}
	for (int i=1;i<n;i++)
	for (int j=i;j<=n;j++)
	if ((a[i].s<a[j].s)||(a[i].s==a[j].s)&&(a[i].c<a[j].c)||
		(a[i].s==a[j].s)&&(a[i].c==a[j].c)&&(a[i].h>a[j].h))
	{
		temp=a[i];a[i]=a[j];a[j]=temp;
	}
	for (int i=1;i<=5;i++)
	cout<<a[i].h<<" "<<a[i].s<<endl;
	return 0;
}

