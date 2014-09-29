#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N = 23;
char map[N][N];

struct Stat
{
	int x, y;
	int key; // 0: never meet a key, 1: carry a key, 2: have used a key
	int step;
	Stat() {}
	Stat(int ix, int iy, int ikey, int istep)
	{
		x = ix;
		y = iy;
		key = ikey;
		step = istep;
	}
	friend bool operator ==(Stat A, Stat B)
	{
		return A.x == B.x && A.y == B.y;
	}
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool vis[N][N][3];
int BFS(int n, int m)
{
	Stat S, T;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(map[i][j] == 'S')
			{
				S = Stat(i, j, 0, 0);
				map[i][j] = '*';
			}
			else if(map[i][j] == 'T')
			{
				T = Stat(i, j, 0, 0);
				map[i][j] = '*';
			}
	memset(vis, 0, sizeof(vis));
	queue <Stat> q;
	q.push(S);
	vis[S.x][S.y][0] = true;
	while(!q.empty())
	{

		Stat TS = q.front(); q.pop();
		//cout << TS.x << ' ' << TS.y << ' ' << TS.key << ' ' << TS.step << '\n';
		if(TS == T) return TS.step;
		
		for(int k = 0; k < 4; k++)
		{
			TS.x += dx[k];
			TS.y += dy[k];
			int keyStat = TS.key;
			TS.step++;

			bool flag = true;
			if(map[TS.x][TS.y] == 'K')
				if(TS.key == 0)
					TS.key = 1;
				else {}
			else if(map[TS.x][TS.y] == 'D')
				if(TS.key == 1)
					TS.key = 0;
				else flag = false;
			else if(map[TS.x][TS.y] == '#')
				flag = false;

			if(flag && !vis[TS.x][TS.y][TS.key])
			{
				vis[TS.x][TS.y][TS.key] = true;
				q.push(TS);
			}

			TS.x -= dx[k];
			TS.y -= dy[k];
			TS.key = keyStat;
			TS.step--;
		}
		
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			map[i][j] = '#';
	for(int i = 1; i <= n; i++)
	{
		string s; cin >> s;
		for(int j = 0; j < s.size(); j++)
			map[i][j+1] = s[j];
	}
	cout << BFS(n, m) << '\n';
	return 0;
}