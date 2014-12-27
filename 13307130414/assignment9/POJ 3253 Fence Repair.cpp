#include <iostream>
#include <queue>
using namespace std;

priority_queue <int, vector<int>, greater<int> > p;

int main() {
    int n;
    int x;
    long long ans = 0;
    long long temp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        p.push(x);
    }
    while(1) {
        temp = p.top();
        p.pop();
        if(p.empty()) break;
        temp += p.top();
        p.pop();
        ans += temp;
        p.push(temp);
    }
    cout << ans << endl;
}
