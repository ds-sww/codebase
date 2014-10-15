/**
 *  @author forward
 *  @date   2014.9.29
 *
 */

#include "iostream"
#include "cstdio"
#include "cstring"
#include "memory"
#include "algorithm"



using namespace std;
const int inf = 32768;
char map[25][25];
int n, m;
int f[500][500], g[500][500];

int xy2p(int x, int y)
{
    return x * m + y;
}

bool valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (map[x][y] == '#') return false;
    return true;
}

void add(int x, int y)
{
    f[x][y] = f[y][x] = 1;
}

void rm(int x, int y)
{
    f[x][y] = f[y][x] = inf;
}

void addall(int i, int j)
{
    int p = xy2p(i, j);
    if (valid(i - 1, j)) add(p, xy2p(i-1, j));
    if (valid(i, j - 1)) add(p, xy2p(i, j-1));
    if (valid(i + 1, j)) add(p, xy2p(i+1, j));
    if (valid(i, j + 1)) add(p, xy2p(i, j+1));
}

void rmall(int i, int j)
{
    int p = xy2p(i, j);
    if (valid(i - 1, j)) rm(p, xy2p(i-1, j));
    if (valid(i, j - 1)) rm(p, xy2p(i, j-1));
    if (valid(i + 1, j)) rm(p, xy2p(i+1, j));
    if (valid(i, j + 1)) rm(p, xy2p(i, j+1));
}

int main(int argc, char const *argv[])
{
    //freopen("1.txt", "r", stdin);

    scanf("%d %d\n",&n,&m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%c",&map[i][j]);
        scanf("\n");
    }


    for (int i = 0; i < n*m; i++)
        for (int j = 0; j < n*m; j++) f[i][j] = inf;

    bool door = false;
    int pd, pk, ps, pt;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        if (map[i][j] != '#') {
            if (map[i][j] == 'D') {
                door = true;
                pd = xy2p(i, j);
            }
            if (map[i][j] == 'K') {
                pk = xy2p(i, j);
            }
            if (map[i][j] == 'S') {
                ps = xy2p(i, j);
            }
            if (map[i][j] == 'T') {
                pt = xy2p(i, j);
            }
            addall(i, j);
        }
    memcpy(g, f, sizeof(f));    
    for (int k = 0; k < n*m; k++)
            for (int i = 0; i < n*m; i++)
                for (int j = 0; j < n*m; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);


    if (!door) {
        for (int k = 0; k < n*m; k++)
            for (int i = 0; i < n*m; i++)
                for (int j = 0; j < n*m; j++)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

        if (f[ps][pt] == inf) cout<<-1<<endl;
        else cout<<f[ps][pt]<<endl;
    }
    else {
        
        rmall(pd/m, pd%m);
        for (int k = 0; k < n*m; k++)
            for (int i = 0; i < n*m; i++)
                for (int j = 0; j < n*m; j++)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        if (f[ps][pk] == inf) {
            if (f[ps][pt] == inf) cout<<-1<<endl;
            else cout<<f[ps][pt]<<endl;
        }
        else {
            int ans = min(f[ps][pk] + g[pk][pd] + g[pd][pt], f[ps][pt]);
            if (ans >= inf) cout<<-1<<endl;
            else cout<<ans<<endl;
        }
    }
    

    return 0;
}