#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>

#define MAX 30

using namespace std;

char map[MAX][MAX];

class point
{
	public:
		int x, y, key;
		point()
		{
			x = 0; y = 0; key = 0;
		}
		bool check() const
		{
            if(x < 0 || y < 0)
                return 0;
			if(map[x][y] == '*' || map[x][y] == 'K' || (map[x][y] == 'D' && key))
				return 1;
			else
				return 0;
		}
};

int bfs(point start, point end)
{
	int ans[MAX][MAX][2];
	int vect[2][4]={{-1, 0, 1, 0},
					{ 0,-1, 0, 1}};
	memset(ans,-1,sizeof(ans));
	
	queue<point> Q;
	ans[start.x][start.y][start.key] = 0;
	Q.push(start);
	while(!Q.empty())
	{
		point now = Q.front();
		Q.pop();
		for(int i = 0; i < 4 ; i++)
		{
			point next = now;
			next.x += vect[0][i]; next.y += vect[1][i];
			if(next.check() && ans[next.x][next.y][next.key]<=0)
			{
				if(map[next.x][next.y] == 'K')
					next.key = 1;
				ans[next.x][next.y][next.key] = ans[now.x][now.y][now.key] + 1;
				if(next.x == end.x && next.y == end.y)
					return ans[next.x][next.y][next.key];
				Q.push(next);
			}
		}
	}
	return -1;
}

int main()
{
	point start, end;
	
	int n, m;
	memset(map, 0, sizeof(map));
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> map[i];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(map[i][j] == 'S')
			{
				start.x = i; start.y = j;
				map[i][j] = '*';
			}
			else if(map[i][j] == 'T')
			{
				end.x = i; end.y = j;
				map[i][j] = '*';
			}
		}
	}
	
	cout << bfs(start, end) << endl;
	return 0;
}