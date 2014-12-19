#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10010;

vector <int> v;
char str[N];
pair <int, int> p[N];
int len;

void init() {
    len = strlen(str);
    for (int i = 0; i < len; i++)
        p[i].first = p[i].second = -1;
    v.clear();
}

void output() {
    string ans = "";
    queue <int> q;
    q.push(len-1);
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        ans += str[t];
        if (p[t].first != -1) {
            q.push(p[t].first);
            q.push(p[t].second);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    //freopen("3367.txt", "r", stdin);
    int cas;
    cin >> cas;
    while(cas--) {
        cin >> str;
        init();
        for (int i = 0; i < len; i++) {
            if (islower(str[i])) {
                v.push_back(i);
            }
            else {
                int a = v.back();
                v.pop_back();
                int b = v.back();
                v.pop_back();
                p[i] = make_pair(b,a);
                v.push_back(i);
                //cout << str[i] << ' ' << str[b] << ' ' << str[a] << endl;
            }
        }
        output();
    }
}
