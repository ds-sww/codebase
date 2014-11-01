#include<cstdio>
int n,m;
char g[31][31];
int c[31][31],sx,sy,tx,ty,kx,ky,dx,dy,b[34][34];
int min,min1;
void floodfill(int xx,int yy,int e)
{
	int x=xx,y=yy;
	c[x][y]=e;
	if(x+1<n&&!b[x+1][y]&&c[x+1][y]>c[x][y]+1)
		floodfill(x+1,y,e+1);
	if(y+1<m&&!b[x][y+1]&&c[x][y+1]>c[x][y]+1)
		floodfill(x,y+1,e+1);
	if(x-1>=0&&!b[x-1][y]&&c[x-1][y]>c[x][y]+1)
		floodfill(x-1,y,e+1);
	if(y-1>=0&&!b[x][y-1]&&c[x][y-1]>c[x][y]+1)
		floodfill(x,y-1,e+1);
}
int main()
{
	int i,j,u=0; 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",g[i]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		if(g[i][j]=='S')
		{
			sx=i;sy=j;
		}
		else
		if(g[i][j]=='T')
		{
			tx=i;ty=j;
		}
		else
		if(g[i][j]=='K')
		{
			kx=i;ky=j;
			u=1;
		}
		else
		if(g[i][j]=='D')
		{
			dx=i;dy=j;
		}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		if(g[i][j]=='*'||g[i][j]=='K'||g[i][j]=='S'||g[i][j]=='T')
			b[i][j]=0;
		else
			b[i][j]=1;
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		c[i][j]=100000000;
	floodfill(sx,sy,0);
	min=c[tx][ty];
	if(u==0)
	{
		if(min>9000000)
			printf("-1\n");
		else
			printf("%d\n",min);
		return 0;
	}
	min1=c[kx][ky];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		c[i][j]=100000000;
	b[dx][dy]=0;
	floodfill(kx,ky,0);
	b[dx][dy]=1;
	min1+=c[dx][dy];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		c[i][j]=100000000;
	floodfill(dx,dy,0);
	min1+=c[tx][ty];
	if(min>9000000&&min1>900000)
			printf("-1\n");
	else
		if(min1<min)
		printf("%d\n",min1);
	else
		printf("%d\n",min);
	return 0;
} 
