#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20005;

int main()
{
    int t,n;
    int p[N];
    int i,j;
    int sum;

    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        for (j = 0; j < n; j++)
            cin >> p[j];
        sort(p, p+n);
        for (j = n-1; j >= 0; j--) {
            if ((n-j) % 3 == 0)
                sum += p[j];
            p[j] = 0;
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}
