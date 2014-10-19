#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[10000],s0[100];
	int i,n,m,h,hash,j,p;
	cin>>s;
	cin>>s0;
	n=0;m=0;h=0;
	while (s[n]) n++;
	while (s0[m])
	{
		h=h*2;
		h=h+s0[m];
		m++;
	}
	if ((n<m)||(m==0))
	{
		cout<<"Not Found!"<<endl;
		return 0;
	}
	hash=0;
	for (i=0;i<m-1;i++)
	{
		hash=hash*2;
		hash=hash+s[i];
	}
	for (i=m-1;i<n;i++)
	{
		hash=hash*2+s[i];
		if (hash==h)
		{
			p=1;
			for (j=0;j<m;j++)
				if (s0[j]!=s[i-m+j+1]) 
				{
					p=0;
					break;
				}
			if (p)
			{
				cout<<"Position:"<<i-m+1<<endl;
				return 0;
			}
		}
		p=1;
		for (j=0;j<m-1;j++) p=p*2;
		hash=hash-s[i-m+1]*p;
	}
	cout<<"Not Found!"<<endl;
	return 0;
}