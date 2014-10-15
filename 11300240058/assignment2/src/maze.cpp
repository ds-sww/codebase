/**
 * Author   : Ryannnnnnn
 * Date     : Sep 30, 2014
 */

#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y): x(_x), y(_y) {}
};

struct State {
    Point p;
    bool hasKey;
    int step;
    State(Point _p, int _hasKey, int _step): p(_p), hasKey(_hasKey), step(_step) {}
};

class Maze {
private:
    static const int MAXN = 20, MAXM = 20;

    Point startPoint;
    bool visited[MAXN][MAXM][2];

public:
    int shortestTime(int n, int m, vector <string> map) {
        // initialize
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (map[i][j] == 'S')
                    startPoint = Point(i, j);

        // Breadth-First Search (BFS)
        queue <State> q;
        q.push(State(startPoint, false, 0));
        visited[startPoint.x][startPoint.y][0] = true;

        while (!q.empty()) {
            State current = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                State next = State(Point(current.p.x + dx[dir], current.p.y + dy[dir]),
                                   current.hasKey, current.step + 1);

                if (next.p.x < 0 || next.p.x >= n || next.p.y < 0 || next.p.y >= m) continue; // Range check

                if (map[next.p.x][next.p.y] == 'K') next.hasKey = true; // Key
                if (map[next.p.x][next.p.y] == '#') continue; // Blocked
                if (!next.hasKey && map[next.p.x][next.p.y] == 'D') continue; // Door
                if (map[next.p.x][next.p.y] == 'T') return next.step; // Destination

                // If not visited, push to queue
                if (!visited[next.p.x][next.p.y][next.hasKey]) {
                    q.push(next);
                    visited[next.p.x][next.p.y][next.hasKey] = true; // Mark the statement as visited
                }
            }
        }
        return -1;
    }
};

int main() {
    int n, m;
    string line;
    vector <string> map;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> line;
        map.push_back(line);
    }

    Maze *maze = new Maze();
    cout << maze->shortestTime(n, m, map) << endl;
    return 0;
}
