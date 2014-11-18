#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char pre[30];
char mid[30];
int n = -1;

void maketree(int i, int j) {
    if (i > j) return;
    int k;
    n++;
    for (k = i; k < j; k++) {
        if (pre[n] == mid[k])
            break;
    }
    maketree(i, k-1);
    maketree(k+1, j);
    cout << mid[k];
}

int main() {
    while (scanf("%s%s", pre, mid) == 2) {
        maketree(0, strlen(pre)-1);
        cout << endl;
        n = -1;
    }
    return 0;
}
