#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int x,y;
    int next;
    Node() : next(-1) {}
} node[1005];

int x[1005];
int y[1005];
int ans;
const int H = 20005;
int hashtable[H];

void init() {
    memset(hashtable, -1, sizeof(hashtable));
    ans = 0;
}

void insertHash(int a, int b, int i) {
    int h = (a*a + b*b) % H;
    node[i].x = a;
    node[i].y = b;
    node[i].next = hashtable[h];
    hashtable[h] = i;
}

bool searchHash(int a, int b) {
    int h = (a*a + b*b) % H;
    int next = hashtable[h];
    while (next != -1) {
        if (node[next].x == a && node[next].y == b)
            return true;
        else
            next = node[next].next;
    }
    return false;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) return 0;
        init();
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            insertHash(x[i], y[i], i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                    // case1:
                    int x1 = x[i] + (y[i] - y[j]);
                    int y1 = y[i] - (x[i] - x[j]);
                    int x2 = x[j] + (y[i] - y[j]);
                    int y2 = y[j] - (x[i] - x[j]);
                    // case2:
                    int x3 = x[i] - (y[i] - y[j]);
                    int y3 = y[i] + (x[i] - x[j]);
                    int x4 = x[j] - (y[i] - y[j]);
                    int y4 = y[j] + (x[i] - x[j]);
                    if (searchHash(x1, y1) && searchHash(x2, y2))
                        ans++;
                    if (searchHash(x3, y3) && searchHash(x4, y4))
                        ans++;
            }
        }
        ans /= 4;
        cout << ans << endl;
    }
}
