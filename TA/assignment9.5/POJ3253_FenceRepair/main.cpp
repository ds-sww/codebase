/**
 * @author whimsycwd
 * @date   2014.11.22
 */

#include<iostream>
#include<cstdio>
#include<queue>
#include<functional>
#include<vector>

using namespace std;


void work(int n) {
    priority_queue<int, vector<int>, greater<int> > pq;

    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        pq.push(x);
    } 

    long long ans = 0;
    while (pq.size() > 1) {
        int v1 = pq.top();
        pq.pop();
        int v2 = pq.top();
        pq.pop();
        ans += v1 + v2;
        pq.push(v1 + v2);
    }

    cout << ans << endl;

}

int main() {
    int n;
    while (cin >> n) {
        work(n);
    }
    return 0;
}

