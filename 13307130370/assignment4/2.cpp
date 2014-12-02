#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,tempmin,square=0,k;
	while(1)
	{
		square=0;
		cin>>n;
		if(n==0)
			break;
		int *a=new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int m=n;m>=1;m--)
		{
			for(k=0;k+m<=n;k++)
			{
				tempmin=a[k];
				for(int q=k;q<m+k;q++)
					tempmin=min(tempmin,a[q]);
				square=max(square,m*tempmin);
			}
		}
		cout<<square<<endl;
		delete[] a;
	}
	return 0;
}
