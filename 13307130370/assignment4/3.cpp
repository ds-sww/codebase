#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,k,tempmin,tempmax;
	cin>>n>>k;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int *minnumber=new int[n-k+1];
	int *maxnumber=new int[n-k+1];

	for(int i=0;i<n-k+1;i++)
	{
		tempmin=a[i];
		tempmax=a[i];
		for(int t=i;t<i+k;t++)
		{
			tempmin=min(tempmin,a[t]);
			tempmax=max(tempmax,a[t]);
		}
		minnumber[i]=tempmin;
		maxnumber[i]=tempmax;
	}

	for(int i=0;i<n-k+1;i++)
		cout<<minnumber[i]<<"  ";
	cout<<endl;
	for(int i=0;i<n-k+1;i++)
		cout<<maxnumber[i]<<"  ";
	delete[] a;
	delete[] minnumber;
	delete[] maxnumber;
	return 0;
}

