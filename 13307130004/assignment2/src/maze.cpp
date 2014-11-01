#include <iostream>
#define N 22
using namespace std;

class maze{
private:
	int change[2][N][N],distance[2][N][N];
	char map[N][N];
	bool totalchange;
	int n,m;
	void move0(int x,int y)
	{
		if(x>0&&map[x-1][y]!='#'&&map[x-1][y]!='D')
		{
			if(map[x-1][y]=='*'||map[x-1][y]=='S'||map[x-1][y]=='T')
			{
				if(distance[0][x][y]+1<distance[0][x-1][y]||distance[0][x-1][y]==-1)
				{
					distance[0][x-1][y]=distance[0][x][y]+1;
					change[0][x-1][y]=1;
				}
			}
			else
			{
				if((distance[0][x][y]+1<distance[1][x-1][y])||distance[1][x-1][y]==-1)
				{
					distance[1][x-1][y]=distance[0][x][y]+1;
					change[1][x-1][y]=1;
				}
			}
		}
		if(y>0&&map[x][y-1]!='#'&&map[x][y-1]!='D')
		{
			if(map[x][y-1]=='*'||map[x][y-1]=='S'||map[x][y-1]=='T')
			{
				if(distance[0][x][y]+1<distance[0][x][y-1]||distance[0][x][y-1]==-1)
				{
					distance[0][x][y-1]=distance[0][x][y]+1;
					change[0][x][y-1]=1;
				}
			}
			else
			{
				if((distance[0][x][y]+1<distance[1][x][y-1])||distance[1][x][y-1]==-1)
				{
					distance[1][x][y-1]=distance[0][x][y]+1;
					change[1][x][y-1]=1;
				}
			}
		}
		if(x<n-1&&map[x+1][y]!='#'&&map[x+1][y]!='D')
		{
			if(map[x+1][y]=='*'||map[x+1][y]=='S'||map[x+1][y]=='T')
			{
				if(distance[0][x][y]+1<distance[0][x+1][y]||distance[0][x+1][y]==-1)
				{
					distance[0][x+1][y]=distance[0][x][y]+1;
					change[0][x+1][y]=1;
				}
			}
			else
			{
				if((distance[0][x][y]+1<distance[1][x+1][y])||distance[1][x+1][y]==-1)
				{
					distance[1][x+1][y]=distance[0][x][y]+1;
					change[1][x+1][y]=1;
				}
			}
		}
		if(y<m-1&&map[x][y+1]!='#'&&map[x][y+1]!='D')
		{
			if(map[x][y+1]=='*'||map[x][y+1]=='S'||map[x][y+1]=='T')
			{
				if(distance[0][x][y]+1<distance[0][x][y+1]||distance[0][x][y+1]==-1)
				{
					distance[0][x][y+1]=distance[0][x][y]+1;
					change[0][x][y+1]=1;
				}
			}
			else
			{
				if((distance[0][x][y]+1<distance[1][x][y+1])||distance[1][x][y+1]==-1)
				{
					distance[1][x][y+1]=distance[0][x][y]+1;
					change[1][x][y+1]=1;
				}
			}
		}
	change[0][x][y]=0;
	};
	void move1(int x,int y)
	{
		if(x>0&&(map[x-1][y]!='#'))
			if(distance[1][x][y]+1<distance[1][x-1][y]||distance[1][x-1][y]==-1)
				{
					distance[1][x-1][y]=distance[1][x][y]+1;
					change[1][x-1][y]=1;
				}
		if(y>0&&(map[x][y-1]!='#'))
			if(distance[1][x][y]+1<distance[1][x][y-1]||distance[1][x][y-1]==-1)
				{
					distance[1][x][y-1]=distance[1][x][y]+1;
					change[1][x][y-1]=1;
				}
		if(x<n-1&&(map[x+1][y]!='#'))
			if(distance[1][x][y]+1<distance[1][x+1][y]||distance[1][x+1][y]==-1)
				{
					distance[1][x+1][y]=distance[1][x][y]+1;
					change[1][x+1][y]=1;
				}
		if(y<n-1&&(map[x][y+1]!='#'))
			if(distance[1][x][y]+1<distance[1][x][y+1]||distance[1][x][y+1]==-1)
				{
					distance[1][x][y+1]=distance[1][x][y]+1;
					change[1][x][y+1]=1;
				}
		change[1][x][y]=0;
	};
public:
	maze(int nn,int mm)
	{
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			{
				map[i][j]='#';
				change[0][i][j]=0;
				change[1][i][j]=0;
				distance[0][i][j]=-1;
				distance[1][i][j]=-1;
			}
		n=nn;m=mm;
		totalchange=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>map[i][j];
	};
	int solve(){
		int i,j,x,y;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(map[i][j]=='S')
				{
					change[0][i][j]=1;
					distance[0][i][j]=0;
				}
		while(1)
		{
			totalchange=false;
			for(i=0;i<n;i++)
				for(j=0;j<m;j++)
				{
					if(change[0][i][j]==1)
					{
						totalchange=true;
						move0(i,j);
					}
					if(change[1][i][j]==1)
					{
						totalchange=true;
						move1(i,j);
					}
				}
			if(!totalchange)
				break;
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(map[i][j]=='T')
				{
					x=i;
					y=j;
					break;
				}
		if(distance[0][x][y]==-1)
			return distance[1][x][y];
		else if(distance[1][x][y]==-1)
			return distance[0][x][y];
		else if(distance[1][x][y]<=distance[0][x][y])
			return distance[1][x][y];
		else
			return distance[0][x][y];
	};
};
int main(){
	int n,m;
	cin>>n>>m;
	maze ma(n,m);
	cout<<ma.solve()<<endl;
	return 0;
}
