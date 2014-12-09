#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

char cnt[27];
char s[1000];
priority_queue <int, vector<int>, greater<int> > q;

int main() {
    int ans;
    int temp;
    while (cin >> s) {
        ans = 0;
        temp = 0;
        if (s[0] == 'E' && s[1] == 'N' && s[2] == 'D') return 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '_')
                cnt[26]++;
            else
                cnt[s[i]-'A']++;
        }
        for (int i = 0; i < 27; i++)
            if (cnt[i]) {
                q.push(cnt[i]);
                cnt[i] = 0;
            }
        while (1) {
            temp = q.top();
            q.pop();
            if (q.empty()) {
                if (!ans) ans = temp;
                break;
            }
            temp += q.top();
            q.pop();
            ans += temp;
            q.push(temp);
        }
        printf("%d %d %.1f\n", int(strlen(s))*8, ans, double(strlen(s)*8.0/ans));
    }
}
