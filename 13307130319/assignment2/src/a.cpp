#include <cstdio>

const int Maxn=30;
const int Way[4][2]={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

struct Node
{
	int x, y;
	bool flag;

	Node(int x0=0, int y0=0, int flag0=false)
	{
		x=x0; y=y0; flag=flag0;
	}
};

int n, m, sx, sy, tx, ty;
char map[Maxn][Maxn];
bool u[Maxn][Maxn][2];
Node o[Maxn*Maxn*2];

int bfs()
{
	int q1=0, q2=0, q3, step=0, x, y, i, j;
	bool flag;
	Node v;
	o[0]=Node(sx, sy, false);
	u[sx][sy][0]=true;
	while (q1<=q2)
	{
		q3=q2+1;
		++step;
		for (i=q1; i<q3; ++i)
		{
			v=o[i];
			for (j=0; j<4; ++j)
			{
				x=v.x+Way[j][0];
				y=v.y+Way[j][1];
				flag=v.flag;
				if (x<0 || x==n || y<0 || y==m || map[x][y]=='#') continue;
				if (map[x][y]=='D' && !flag) continue;
				if (map[x][y]=='K') flag=true;
				if (u[x][y][flag]) continue;
				if (tx==x && ty==y) return step;
				o[++q2]=Node(x, y, flag);
				u[x][y][flag]=true;
			}
		}
		q1=q3;
	}
	return -1;
}

int main()
{
	freopen("a.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i)
	{
		scanf("%s", map[i]);
		for (int j=0; j<m; ++j)
			if (map[i][j]=='S') sx=i, sy=j;
			else if (map[i][j]=='T') tx=i, ty=j;
	}
	printf("%d\n", bfs());
	return 0;
}

