#include <iostream>
#include <deque>
using namespace std;

const int N = 1000005;
struct Node {
    Node(int v = 0, int i = 0) : value(v), index(i) {}
    int value;
    int index;
};
deque <Node> d;
int num[N];
int ans[N];
int n,k,i;

void min(int &n, int &k) {
    while (!d.empty())
        d.pop_front();
    for (i = 0; i < k; i++) {
        while (!d.empty() && d.back().value > num[i])
            d.pop_back();
        d.push_back(Node(num[i],i));
    }
    ans[0] = d.front().value;

    for (i = k; i < n; i++) {
        while (i - d.front().index >= k){
            d.pop_front();
        }
        while (!d.empty() && d.back().value > num[i])
            d.pop_back();
        d.push_back(Node(num[i],i));
        ans[i-k+1] = d.front().value;
    }
}


int main() {
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> num[i];

    min(n,k);
    for (i = 0; i <= n-k; i++)
        cout << ans[i] << ' ';
    cout << endl;

    for (i = 0; i < n; i++)
        num[i] = -num[i];
    min(n,k);
    for (i = 0; i <= n-k; i++)
        cout << -ans[i] << ' ';

    return 0;
}

