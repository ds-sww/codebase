#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for (int k=0;k<t;k++)
	{
		long long n,m,l,r,ans;
		cin>>n>>m;
		l=-n*100000;r=n*n*3+100000*n;
		while (l<=r)
		{
			long long mid,sum;
			mid=(l+r)>>1;
			sum=0;
			for (long long j=1;j<=n;j++)
			{
				long long delta,i;
				delta=(j+100000)*(j+100000)-(j*j-100000*j-mid)*4;
				if (delta>=0) 
				{
					i=((long long)sqrt((double)delta)-(j+100000))/2;
					if (i>0) 
						if (i<n) sum=sum+i;
						else sum=sum+n;
				}
			}
			if (sum>=m) 
			{
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}