#include<cstdio>
#include<cstdlib>
int n,num,st[1000001],height[1000001],pos[1000001],p;
long long  max;
int main()
{
	int i,j;
	scanf("%d",&n);
	while(n!=0)
	{
		max=0;
		p=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num);
  			//退栈,维护单调性 
			while(p>0&&num<height[p-1])
			{
				if(max<(long long)height[p-1]*(i-st[p-1]))
					max=(long long)height[p-1]*(i-st[p-1]);
				p--;
			}
			//=========================== 
			if(num>=height[p-1]||p==0)
			{
				//记录高度 
				height[p]=num;
				//计算起始位置 
				if(p==0)
					st[p]=0;
				else
					st[p]=pos[p-1]+1;
				//记录位置信息 
				pos[p]=i;
				p++;
			}
		}
		//最后退栈 
		while(p>0)
		{
			if(max<(long long)height[p-1]*(n-st[p-1]))
				max=(long long)height[p-1]*(n-st[p-1]);
			p--;
		}
		printf("%I64d\n",max);
		//=========================== 
		scanf("%d",&n);
	}
	return 0;
}
