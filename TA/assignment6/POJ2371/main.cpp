/**
 * @author whimsycwd
 * @date   2014.11.2
 *
 */

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,k;

void work() {
    int * data = new int[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
    }

    sort(data, data + n);
    
    string sep;
    cin >> sep;

    cin >> k;
    int idx;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &idx);
        printf("%d\n", data[idx - 1]);
    }

    delete [] data;
}

int main() {
    while (cin >> n) {
        work();
    } 
    return 0;
}
