#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <numeric>
#include <queue>

using namespace std;

int n, m;

struct status_t {
	int x, y, k;
	status_t() {
		x = y = k = 0;
	}
	status_t(const int &x, const int &y, const int &k) : x(x), y(y), k(k) {}
	inline bool valid() const {
		return ( ( (x) >= 0 && (x) < n ) && (y) >= 0 && (y) < m );

	}
};

int map[32][32];
int ans[32][32][2];
int sx, sy, tx, ty, kx, ky;

const int d[][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
};

int bfs() {
	memset(ans, -1, sizeof ans);
	queue<status_t> Q;
	Q.push(status_t(sx, sy, 0));
	ans[sx][sy][0] = 0;
	while(Q.size()) {
		status_t now = Q.front();
		Q.pop();
		for(int i = 0; i < 4; ++ i) {
			status_t next = now;
			next.x += d[i][0], next.y += d[i][1];
			if (!next.valid()) continue;
			if (next.k == 0 && map[next.x][next.y] == 2) continue; // no key.
			if (map[next.x][next.y] == 0) continue; // wall
			if (next.x == kx && next.y == ky) next.k = 1;
			if (ans[next.x][next.y][next.k] >= 0) continue;
			ans[next.x][next.y][next.k] = ans[now.x][now.y][now.k] + 1;
			if (next.x == tx && next.y == ty) return ans[next.x][next.y][next.k];
			Q.push(next);
		}
	}
	return -1;
}

int main(void) {
	scanf("%d%d", &n, &m);
	register int i, j;
	char buff[4096];
	gets(buff); // read tail eol
	for(i = 0; i < n; ++ i) {
		gets(buff);
		for(j = 0; j < m; ++ j) {
			switch(buff[j]) {
				case '*':
					map[i][j] = 1;
					break;
				case '#':
					map[i][j] = 0;
					break;
				case 'S':
					map[i][j] = 1;
					sx = i, sy = j;
					break;
				case 'T':
					map[i][j] = 1;
					tx = i, ty= j;
					break;
				case 'D':
					map[i][j] = 2;
					break;
				case 'K':
					map[i][j] = 1;
					kx = i, ky = j;
					break;
				default:
					abort();
			}
		}
	}
	printf("%d\n", bfs());
	return 0;
}
