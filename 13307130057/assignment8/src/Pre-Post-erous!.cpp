#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int c[30][30],m;
string preorder,postorder;
void cal(int n)
{
	for (int i=0;i<n;i++) c[i][0]=1;
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		c[i][i]=1;
	}
}
int work(int lpre,int rpre,int lpost,int rpost)
{
	int i,j,sum,tot;
	i=lpre+1;j=lpost;sum=0;tot=1;
	while (i<=rpre)
	{
		while (j<rpost)
		{
			if (preorder[i]==postorder[j])
			{
				sum++;
				break;
			}
			j++;
		}
		tot=tot*work(i,i+j-lpost,lpost,j);
		lpre=i+j-lpost;
		i=lpre+1;
		j++;lpost=j;
	}
	return tot*c[m][sum];
}
int main()
{
	cin>>m;
	while (m)
	{
		cal(m+1);
		cin>>preorder>>postorder;
		cout<<work(0,preorder.length()-1,0,postorder.length()-1)<<endl;
		cin>>m;
	}
	return 0;
}