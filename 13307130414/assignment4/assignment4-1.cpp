#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack <int> station;
    queue <int> B;
    int back,back1 = 1;
    int i;
    int A;

    while (1) {
        cin >> back;
        if (back1 == 0 && back == 0) break;
        B.push(back);
        back1 = back;
    }

    while (!B.empty()) {
        if (B.front() == 0) {
            B.pop();
            cout << endl;
            if (B.empty())
                break;
            else {
                n = B.front();
                B.pop();
            }
        }
        for (i = 0; i < n; i++) {
            if (i == 0) A = 1;
            if (B.front() >= A) {
                for (int j = A; j < B.front(); j++)
                    station.push(j);
                A = B.front() + 1;
            }
            else if (!station.empty()) {
                if (B.front() == station.top())
                    station.pop();
            }
            B.pop();
        }
        if (station.empty())
            cout << "Yes" << endl;
        else {
            cout << "No" << endl;
            while (!station.empty()) {
                station.pop();
            }
        }
    }

    return 0;
}
