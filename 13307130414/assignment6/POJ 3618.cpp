#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

priority_queue <int, vector<int>, greater<int> > a;
priority_queue <int> b;

int main() {
    int T,N;
    int i;
    int n;
    int temp = 0;
    int time = 0;
    int count = -1;
    cin >> T >> N;

    for (i = 0; i < N; i++) {
        cin >> n;
        if (n > 0)
            a.push(n);
        else
            b.push(n);
    }

    while (!a.empty() && !b.empty()) {
        if (abs(a.top()) < abs(b.top()) ) {
            time = time + abs(a.top() - temp);
            temp = a.top();
            a.pop();
        }
        else {
            time = time + abs(temp - b.top());
            temp = b.top();
            b.pop();
        }
        count++;
        if (time > T) {
            cout << count;
            return 0;
        }
    }

    while (!a.empty()) {
        time = time + abs(temp - a.top());
        temp = a.top();
        a.pop();
        count++;
        if (time > T) {
            cout << count;
            return 0;
        }
    }

    while (!b.empty()) {
        time = time + abs(temp - b.top());
        temp = b.top();
        b.pop();
        count++;
        if (time > T) {
            cout << count;
            return 0;
        }
    }
}
