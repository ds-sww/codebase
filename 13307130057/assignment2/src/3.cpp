#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,i,j,a[300][3],x,y;
	cin>>n;
	for (i=0;i<n;i++)
	{
		a[i][0]=i+1;
		cin>>a[i][1]>>x>>y;
		a[i][2]=x+y+a[i][1];
	}
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
			if ((a[i][2]<a[j][2])||(a[i][2]==a[j][2])&&(a[i][1]<a[j][1])||(a[i][2]==a[j][2])&&(a[i][1]==a[j][1])&&(a[i][0]>a[j][0])){
			x=a[i][0];a[i][0]=a[j][0];a[j][0]=x;
			x=a[i][1];a[i][1]=a[j][1];a[j][1]=x;
			x=a[i][2];a[i][2]=a[j][2];a[j][2]=x;
			}
	for (i=0;i<5;i++)
		cout<<a[i][0]<<' '<<a[i][2]<<endl;
	return 0;
}