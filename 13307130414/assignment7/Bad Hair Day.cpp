#include <iostream>
#include <stack>
using namespace std;

struct node {
    long long  height;
    int index;
};

node cow[80005];
int num[80005];
stack <node> s;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cow[i].height;
        cow[i].index = i;
    }
    for (int i = 0; i < n; i++) {
        if (s.empty() || cow[i].height < s.top().height)
            s.push(cow[i]);
        else {
            while (!s.empty() && cow[i].height >= s.top().height) {
                num[s.top().index] = cow[i].index - s.top().index - 1;
                s.pop();
            }
            s.push(cow[i]);
        }
    }
    int x = s.top().index;
    while (!s.empty()) {
        num[s.top().index] = x - s.top().index;
        s.pop();
    }
    for (int i = 0; i < n; i++)
        ans += num[i];
    cout << ans << endl;
    return 0;
}
