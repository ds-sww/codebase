/**
 * @author whimsycwd
 * @date   2014.11.2
 */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int totalDistance;
int n;


bool cmp(int &a, int &b) {
    return abs(a) < abs(b);
}

void work() {
    int * data = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
    }    

    sort(data, data+n, cmp);

    /*
    for (int i = 0; i < n; ++i) {
        printf("%d ", data[i]);
    }
    */

    int curPos = 0;
    int cnt = 0;
    while (cnt < n
            && totalDistance - abs(curPos - data[cnt]) >= 0) {
        
        // printf("%d %d %d %d\n",curPos, data[cnt],  totalDistance, abs(curPos-data[cnt]));    

        totalDistance -= abs(curPos - data[cnt]);
        curPos = data[cnt++];
    }
    cout << cnt << endl;
    delete [] data;
}

int main() {
    while (cin >> totalDistance >> n) {
        work();
    }
    return 0;
}
