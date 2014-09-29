#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

struct Eve {
	int x, y, stat;
	Eve() {}
	Eve(int _x, int _y, int _stat) : x(_x), y(_y), stat(_stat) {}
}q[MaxN];

const int pi[] = {1,0,-1,0};
const int pj[] = {0,1,0,-1};

int n,m;
char A[233][233];
bool vis[233][233][2];
int d[233][233][2];
int main() {
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	int n, m;
	cin >> n >> m;
	For(i,1,n) For(j,1,m) {
		scanf(" %c", &A[i][j]);
	}
	PII s = MP(-1, -1), t = MP(-1, -1);
	For(i,1,n) For(j,1,m) {
		if (A[i][j] == 'S') {
			s = MP(i,j);
		} else if (A[i][j] == 'T') {
			t = MP(i,j);
		}
	}
	Fill(vis, 0);
	vis[s.FI][s.SE][0] = true;
	Fill(d,INF);
	d[s.FI][s.SE][0] = 0;
	int hd = 0, tl = 1;
	q[1] = Eve(s.FI, s.SE, 0);
	while (hd < tl) {
		Eve vex = q[++hd];
		For(p,0,3) {
			int ni = vex.x + pi[p], nj = vex.y + pj[p];
			int ns = vex.stat || (A[ni][nj] == 'K');
			if (1 <= ni && ni <= n && 1 <= nj && nj <= m && !vis[ni][nj][ns]) {
				if (A[ni][nj] == '#' || A[ni][nj] == 'D' && !vex.stat) {
					continue ;
				}
				vis[ni][nj][ns] = true;
				d[ni][nj][ns] = d[vex.x][vex.y][vex.stat] + 1;
				q[++tl] = Eve(ni,nj,ns);
			}
		}
	}
	if (!vis[t.FI][t.SE][0] && !vis[t.FI][t.SE][1]) {
		puts("-1");
	} else {
		cout << min(d[t.FI][t.SE][0], d[t.FI][t.SE][1]) << endl;
	}
	return 0;
}

