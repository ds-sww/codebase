#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
char a[30][30],ch;
const int MAXN=99999;
int f1[30][30],f2[30][30];
int qx[1001],qy[1001];
bool v[30][30];
int gx[4],gy[4];
int n,m,sx,sy,tx,ty,kx,ky,h,t,x,y,ans;
using namespace std;
int main()
{
	cin>>n>>m;
	gx[0]=1;gy[0]=0;
	gx[1]=0;gy[1]=1;
	gx[2]=-1;gy[2]=0;
	gx[3]=0;gy[3]=-1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if (a[i][j]=='S') {sx=i;sy=j;}
			if (a[i][j]=='T') {tx=i;ty=j;}
			if (a[i][j]=='K') {kx=i;ky=j;}
		}
	}
	f1[tx][ty]=MAXN;
	f2[tx][ty]=MAXN;
	memset(v,0,sizeof(v));
	h=0;t=1;qx[1]=sx;qy[1]=sy;v[sx][sy]=1;
	while (h<t)
	{
		h++;
		for (int i=0;i<4;i++)
		{
			x=qx[h]+gx[i];
			y=qy[h]+gy[i];
			if ((x>0)&&(y>0)&&(x<=n)&&(y<=m)&&(!v[x][y])&&(a[x][y]!='#')&&(a[x][y]!='D'))
			{
				v[x][y]=1;
				t++;
				qx[t]=x;qy[t]=y;
				f1[x][y]=f1[qx[h]][qy[h]]+1;
			}
		}
	}
	ans=f1[tx][ty];
	memset(v,0,sizeof(v));
	h=0;t=1;qx[1]=kx;qy[1]=ky;v[kx][ky]=1;f2[kx][ky]=f1[kx][ky];
	while (h<t)
	{
		h++;
		for (int i=0;i<4;i++)
		{
			x=qx[h]+gx[i];
			y=qy[h]+gy[i];
			if ((x>0)&&(y>0)&&(x<=n)&&(y<=m)&&(!v[x][y])&&(a[x][y]!='#'))
			{
				v[x][y]=1;
				t++;
				qx[t]=x;qy[t]=y;
				f2[x][y]=f2[qx[h]][qy[h]]+1;
			}
		}
	}
	if (ans>f2[tx][ty]) ans=f2[tx][ty];
	if (ans==MAXN)	cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
