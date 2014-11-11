#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return (a > b);
}

int main() {
    int n,m;
    int i,j;
    long long stamp;
    int num[2000];
    int temp;
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "Scenario #" << i+1 << ":" << endl;
        cin >> stamp >> m;
        temp = 0;
        for (j = 0; j < m; j++)
            cin >> num[j];
        sort(num, num+m, cmp);
        for (j = 0; j < m; j++) {
            temp += num[j];
            if (temp >= stamp) {
                cout << j+1 << endl;
                break;
            }
        }
        if (j == m)
            cout << "impossible" << endl;
        cout << endl;
    }
    return 0;
}
