#include <iostream>
#include <queue>

using namespace std;

const int N = 20;
char map[N][N];
int move[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool visit[N][N][2];

struct Node {
    int x,y,step;
    int key;
    Node(int x1, int y1, int step1, int key1): x(x1), y(y1), step(step1), key(key1) {}
};

int BFS(int n, int m) {
    int sx,sy,tx,ty;
    int i,j;
    queue <Node> q;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            if (map[i][j] == 'S') {
                sx = i;
                sy = j;
                map[i][j] = '*';
            }
            if (map[i][j] == 'T') {
                tx = i;
                ty = j;
                map[i][j] = '*';
            }
        }

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (int k = 0; k < 2; k++)
                visit[i][j][k] = false;

    Node node (sx,sy,0,0);
    q.push(node);
    visit[node.x][node.y][node.key] = true;

    while (!q.empty()) {
        node = q.front();
        q.pop();
        if (node.x == tx && node.y == ty)
            return node.step;

        for (i = 0; i < 4; i++) {
            int x = node.x + move[i][0];
            int y = node.y + move[i][1];
            if (x >= 0 && y >=0 && x <= n && y <= m && visit[x][y][node.key] == false) {
                if (map[x][y] == '*') {
                    visit[x][y][node.key] = true;
                    Node next(x,y,node.step + 1,node.key);
                    q.push(next);
                }
                if (map[x][y] == 'K') {
                    visit[x][y][node.key] = true;
                    map[x][y] = '*';
                    node.key = 1;
                    Node next(x,y,node.step + 1,node.key);
                    q.push(next);
                }
                if (map[x][y] == 'D' && node.key == 1) {
                    visit[x][y][node.key] = true;
                    map[x][y] = '*';
                    node.key = 0;
                    Node next(x,y,node.step + 1,node.key);
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n,m;
    cin >> n >> m;

    int i,j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            map[i][j] = '#';

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            char x;
            cin >> x;
            map[i][j] = x;
        }

    cout << BFS(n,m) << endl;
    return 0;
}
