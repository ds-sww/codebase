#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int input[55];
int flag[55];
int root;
int parent[55];
priority_queue <int, vector<int>, greater<int> > q;
queue <int> child[55];

void init() {
    memset(parent, 0, sizeof(parent));
    memset(input, 0, sizeof(input));
    memset(flag, 0, sizeof(flag));
    root = 0;
    while (!q.empty())
        q.pop();
    for (int i = 0; i < 55; i++)
        while (!child[i].empty())
            child[i].pop();
}

void output(int r) {
    if (r != root) cout << ' ';
    cout << '(' << r;
    while (!child[r].empty()) {
        output(child[r].front());
        child[r].pop();
    }
    cout << ')';
    return;
}

int main() {
    //freopen("2568.txt", "r", stdin);
    string buf;
    while(getline(cin, buf)) {
        init();
        int n;
        stringstream ss(buf);
        for (n = 0; ss >> input[n]; n++)
            flag[input[n]]++;
        n++;
        for (int i = 1; i <= n; i++) {
            if (flag[i] == 0)
                q.push(i);
        }
        for (int i = 0; i < n-1; i++) {
            int x = q.top();
            child[input[i]].push(x);
            parent[x] = input[i];
            q.pop();
            if (--flag[input[i]] == 0)
                q.push(input[i]);
        }
        for (root = 1; parent[root] != 0; root++) ;
        output(root);
        cout << endl;
    }
    return 0;
}
