#include<cstdio>
#include<iostream>
const int MAXN = 10001;
int next[MAXN],ans[MAXN];
int l1,l2,i,j,k,num;
char a[MAXN],b[MAXN];
int main()
{
	while (scanf("%s",a)!=-1)
	{
		scanf("%s",b);
		num = 0;
		l1 = 0;
		while (a[l1]!='\0') l1++;
		l2 = 0;
		while (b[l2]!='\0') l2++;
		next[0] = -1;
		j = 0;
		k = -1;
		while (j<l2)
		{
			if (k==-1 || b[j]==b[k])
			{
				j++;
				k++;
				next[j] = k;
			}
			else k = next[k];
		}
		i = 0;
		j = 0;
		while (i<l1)
		{
			if (j==-1 || a[i]==b[j])
			{
				i++;
				j++;
				if (j==l2)
				{
					ans[num] = i - j;
					num++;
					j = next[j];
				}
			}
			else j = next[j];
		}
		if (num==0) printf("-1\n");
		else
		{
			for (int i = 0; i< num - 1; i++)
			{
				printf("%d ",ans[i]);
			}
			printf("%d\n",ans[num - 1]);
		}
	}
	return 0;
}
