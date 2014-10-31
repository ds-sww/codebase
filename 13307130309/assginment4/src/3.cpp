#include<cstdio>
#include<cstdlib>
int n,k,num,que_min[2000001],que_max[2000001],pos_min[2000001],pos_max[2000001],st_min,en_min,st_max,en_max,min[2000001],max[2000001];
int main()
{
	int i,j;
	scanf("%d %d",&n,&k);
	st_max=en_max=0;
	st_min=en_min=0;
	//预先进队 
	for(i=0;i<k-1;i++)
	{
		scanf("%d",&num);
		while(st_max<en_max&&num>=que_max[en_max-1])
			en_max--;
		pos_max[en_max]=i;
		que_max[en_max++]=num;
		
		while(st_min<en_min&&num<=que_min[en_min-1])
			en_min--;
		pos_min[en_min]=i;
		que_min[en_min++]=num;
	}
	for(i=k-1;i<n;i++)
	{
		//队首前进 
		while(i-k>=pos_max[st_max])
			st_max++;
		while(i-k>=pos_min[st_min])
			st_min++;
		
		scanf("%d",&num);
		//队尾退回，进队 
		while(st_max<en_max&&num>=que_max[en_max-1])
			en_max--;
		pos_max[en_max]=i;
		que_max[en_max++]=num;
		
		while(st_min<en_min&&num<=que_min[en_min-1])
			en_min--;
		pos_min[en_min]=i;
		que_min[en_min++]=num;
		
		//记录之 
		max[i]=que_max[st_max];
		min[i]=que_min[st_min];
	}
	for(i=k-1;i<n-1;i++)
		printf("%d ",min[i]);
	printf("%d\n",min[i]);
	
	for(i=k-1;i<n-1;i++)
		printf("%d ",max[i]);
	printf("%d\n",max[i]);
	
	return 0;
}
