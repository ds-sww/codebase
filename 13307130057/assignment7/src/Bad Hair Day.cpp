#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,i,top,a[100000],stack[100000];
	long long sum;
	cin>>n;sum=0;
	for (i=0;i<n;i++) cin>>a[i];
	top=0;stack[0]=a[0];
	for (i=1;i<n;i++)
	{
		while ((top>=0)&&(a[i]>=stack[top])) top--;
		stack[++top]=a[i];
		sum=sum+top;
	}
	cout<<sum<<endl;
	return 0;
}