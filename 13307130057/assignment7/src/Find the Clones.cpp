#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s[20000],a[4][20000];
int f(char x)
{
	switch (x)
	{
	case 'A':return 0;
	case 'C':return 1;
	case 'G':return 2;
	case 'T':return 3;
	}
	return -1;
}
int main()
{
	int n,m,i,j,x,k,sum,digit[4],count[20000];
	cin.sync_with_stdio(false);
	cin>>n>>m;
	while ((n)||(m))
	{
		for (i=0;i<n;i++)
			cin>>s[i];
		for (i=0;i<m;i++)
		{
			for (j=0;j<4;j++) digit[j]=0;
			for (j=0;j<n;j++)
			{
				x=f(s[j][i]);
				a[x][digit[x]++]=s[j];
			}
			sum=0;
			for (j=0;j<4;j++)
				for (k=0;k<digit[j];k++)
					s[sum++]=a[j][k];
		}
		for (i=0;i<n;i++) count[i]=0;
		i=0;
		while (i<n)
		{
			j=i;k=0;
			while ((j<n)&&(s[i]==s[j]))
			{
				j++;k++;
			}
			count[k-1]++;
			i=j;
		}
		for (i=0;i<n;i++)
			cout<<count[i]<<endl;
		cin>>n>>m;
	}
	return 0;
}