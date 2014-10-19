#include<iostream>
#include <algorithm>
using namespace std;
bool compare(int a,int b)
{
      return a>b;  
}
int apple(int n,int *a,int sum)
{
	if(n==2)
		return sum+a[0]+a[1];
	sort(a,a+n,compare);
	
	a[n-2]=a[n-2]+a[n-1];
	sum+=a[n-2];
	n--;
	return apple(n,a,sum);
}
int main()
{
	int n,sum=0;
	cin>>n;
	int *a=new int(n);
	for(int k=0;k<n;k++)
		cin>>a[k];
	cout<<apple(n,a,sum)<<endl;
}
