#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;
const int size=1005;
int n;
int a[size],stk[size];
int main()
{
	//freopen("1.in","r",stdin);
	while (scanf("%d",&n),n)
	{
		while (scanf("%d",&a[0]),a[0])
		{
			if (a[0]==0) break;
			for (int i=1;i<n;i++) scanf("%d",&a[i]);
			int top=0,cur=0;
			for (int i=0;i<n;i++)
			{
				while (cur<a[i]) stk[++top]=++cur;
				if (stk[top]==a[i]) top--;
					else break;
			}		
			printf(top?"No\n":"Yes\n");
		}
		printf("\n");
	}
	return 0;
}
