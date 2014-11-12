#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct node {
    char DNA[25];
};

node line[20010];
int num[20010];
int n,m;

bool cmp(node a, node b) {
    for (int i = 0; i < m; i++) {
        if (a.DNA[i] != b.DNA[i])
            return a.DNA[i] < b.DNA[i];
    }
    return true;
}

int main()
{
    int temp = 0;
    while(scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) return 0;
        for (int i = 0; i < n; i++) {
            num[i] = 0;
            scanf("%s", line[i].DNA);
        }
        sort(line, line+n, cmp);
        for (int i = 0; i < n-1; i++) {
            if (strcmp(line[i].DNA, line[i+1].DNA) == 0)
                temp++;
            else {
                num[temp]++;
                temp = 0;
            }
        }
        num[temp]++;
        temp = 0;
        for (int i = 0; i < n; i++)
            printf("%d\n",num[i]);
    }
}
