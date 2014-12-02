/**
 * @author whimsycwd
 * @date   2014.11.7
 *
 */

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

int n, m;

void push(vector<int> & datas, vector<int> & toPush) {
    for (int i = 0; i < toPush.size(); ++i) {
        datas.push_back(toPush[i]);
    }
    toPush.clear();
}

const int N = 200001;
const int M = 21;

char datas[N][M];
vector<int> idMap;
vector<int> buckets[26];

void work() {

    for (int i = 0; i < n; ++i) {
        scanf("%s", (char*) &datas[i]);
        idMap.push_back(i);
    }



    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            buckets[datas[idMap[i]][j] - 'A'].push_back(idMap[i]);
        }
        idMap.clear();
        push(idMap, buckets['A' - 'A']);
        push(idMap, buckets['C' - 'A']);
        push(idMap, buckets['T' - 'A']);
        push(idMap, buckets['G' - 'A']);
    }
   /* 
    for (int i = 0; i < n; ++i) {
        cout << datas[idMap[i]] << endl;
    }
    */

    int * count = new int[n + 1];
    memset(count, 0, sizeof(int) * (n+1));

    int cur = 0;
    while (cur < n) {
        int cnt = 1;
        while (cur + cnt < n && 
                strcmp(datas[idMap[cur]], datas[idMap[cur + cnt]]) == 0) {
            ++cnt;
        }
      //  printf("%s %d\n", datas[cur].c_str(), cnt);
        count[cnt]++;
        cur += cnt;
    } 

    for (int i = 1; i <= n; ++i) {
        printf("%d\n", count[i]);
    }
    

    delete [] count;
}

int main() {
    while (cin >> n >> m) {
        work();
    }
    return 0;
}
