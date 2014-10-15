#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,m,i,j,k,l,i1,j1,k1,sx,sy,tx,ty,kx,ky,dx,dy,tf,min1,min2,a[20][20][20][20];
	char map[20][20];
	cin>>n>>m;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			for (k=0;k<n;k++)
				for (l=0;l<m;l++)
					if ((i==k)&&(j==l)) a[i][j][k][l]=0;
					else a[i][j][k][l]=10000;
	tf=0;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
		{
			cin>>map[i][j];
			if (map[i][j]=='S')
			{
				map[i][j]='*';
				sx=i;sy=j;
			}
			if (map[i][j]=='T')
			{
				map[i][j]='*';
				tx=i;ty=j;
			}
			if (map[i][j]=='K')
			{
				map[i][j]='*';
				kx=i;ky=j;
			}
			if (map[i][j]=='D')
			{
				dx=i;dy=j;
				tf=1;
			}
			if (map[i][j]=='*')
			{
				if (i>0)
					if (map[i-1][j]=='*') 
					{
						a[i-1][j][i][j]=1;
						a[i][j][i-1][j]=1;
					}
				if (j>0)
					if (map[i][j-1]=='*')
					{
						a[i][j-1][i][j]=1;
						a[i][j][i][j-1]=1;
					}
			}
		}
	for (k=0;k<n;k++)
		for (k1=0;k1<m;k1++)
			for (i=0;i<n;i++)
				for (i1=0;i1<n;i1++)
					for (j=0;j<n;j++)
						for (j1=0;j1<n;j1++)
							if (a[i][i1][k][k1]+a[k][k1][j][j1]<a[i][i1][j][j1])
								a[i][i1][j][j1]=a[i][i1][k][k1]+a[k][k1][j][j1];
	if (tf)
	{
		min1=10000;min2=10000;
		if (dx>0)
		{
			if (a[kx][ky][dx-1][dy]<min1) min1=a[kx][ky][dx-1][dy];
			if (a[tx][ty][dx-1][dy]<min2) min2=a[tx][ty][dx-1][dy];
		}
		if (dy>0)
		{
			if (a[kx][ky][dx][dy-1]<min1) min1=a[kx][ky][dx][dy-1];
			if (a[tx][ty][dx][dy-1]<min2) min2=a[tx][ty][dx][dy-1];
		}
		if (dx<n-1)
		{
			if (a[kx][ky][dx+1][dy]<min1) min1=a[kx][ky][dx+1][dy];
			if (a[tx][ty][dx+1][dy]<min2) min2=a[tx][ty][dx+1][dy];
		}
		if (dy<m-1)
		{
			if (a[kx][ky][dx][dy+1]<min1) min1=a[kx][ky][dx][dy+1];
			if (a[tx][ty][dx+1][dy]<min2) min2=a[tx][ty][dx+1][dy];
		}
		if (a[sx][sy][tx][ty]>a[sx][sy][kx][ky]+min1+min2+2) 
			a[sx][sy][tx][ty]=a[sx][sy][kx][ky]+min1+min2+2;
	}
	if (a[sx][sy][tx][ty]>=1000) cout<<-1<<endl;
	else cout<<a[sx][sy][tx][ty]<<endl;
	return 0;
}