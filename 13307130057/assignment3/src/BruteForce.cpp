#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int pos(char s[],char s0[])
{
	int n,m,i,j,t,tf;
	n=0;m=0;t=-1;
	while (s[n]!='\0') n++;
	while (s0[m]!='\0') m++;
	for (i=0;i<n-m+1;i++)
	{
		tf=1;
		for (j=0;j<m;j++)
			if (s[i+j]!=s0[j])
			{
				tf=0;break;
			}
		if (tf)
		{
			t=i;break;
		}
	}
	return t;
}
int main()
{
	char s[1000],s0[100];
	int t;
	cin>>s;
	cin>>s0;
	t=pos(s,s0);
	if (t==-1) cout<<"Not Found!"<<endl;
	else cout<<"Position:"<<t<<endl;
	return 0;
}