#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,i,j,k,p,tf,a[1000],b[1000];
	cin>>n;
	while (n)
	{
		while (1)
		{
			p=0;
			for (i=0;i<n;i++)
			{
				cin>>a[i];
				if (a[i]==0)
				{
					p=1;
					break;
				}
			}
			if (p) break;
			k=0;tf=1;
			for (i=0;i<n;i++)
			{
				if (a[i]>p)
				{
					for (j=p;j<a[i]-1;j++)
						b[k++]=j+1;
					p=j+1;
				}
				else
				{
					if (b[k-1]==a[i]) k--;
					else
					{
						tf=0;
						cout<<"No"<<endl;
						break;
					}
				}
			}
			if (tf) cout<<"Yes"<<endl;
		}
		cout<<endl;
		cin>>n;
	}
	return 0;
}