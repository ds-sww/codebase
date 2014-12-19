#include <iostream>
#include <cstring>
using namespace std;

bool str[26]; // to mark if a letter has existed
bool num[10]; // to mark if a number is used
string buf[10];
int a[10];
int cnt; // count how many different characters
int ans;

struct Node {
    char c;
    int n;
    bool flag; // to mark if this letter is the leftmost one
    Node() : flag(false) {}
} node[10];

bool check() {
    for (int i = 0; i < cnt; i++) {
        if (node[i].flag == true && a[i] == 0)
            return false;
    }
    int temp = 0;
    for (int i = 0; i < cnt; i++)
        temp += a[i] * node[i].n;
    if (temp == 0) return true;
    else return false;
}

void dfs(int i) {
    if (i > cnt) return;
    for(int j = 0; j < 10; j++) {
        if (i == 0) memset(num, false, sizeof(num));
        if (num[j] == true) continue;
        a[i] = j;
        num[j] = true;
        if (i == cnt-1 && check()) ans++;
        dfs(i+1);
        num[j] = false;
    }
}

int main() {
    int n;
    cin >> n;
    memset(str, false, sizeof(str));
    cnt = 0;
    ans = 0;
    for (int i = 0; i < n; i++)
        cin >> buf[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buf[i].length(); j++) {
            int t;
            if (str[buf[i][j]-'A'] == true) {
                for (t = 0; node[t].c != buf[i][j]; t++) ;
            }
            else {
                t = cnt;
                str[buf[i][j]-'A'] = true;
                cnt++;
            }
            node[t].c = buf[i][j];
            int temp = 1;
            for (int l = 0; l < buf[i].length()-j-1; l++)
                temp *= 10;
            if (i != n-1) node[t].n += temp;
            else node[t].n -= temp;
            if (j == 0) node[t].flag = true;
        }
    }
    dfs(0);
    cout << ans << endl;
}
