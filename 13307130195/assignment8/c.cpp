#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int c[1100][2];
vector<int> v;

void dfs(int i)
{
    v.push_back(i);
    if (c[i][0]) dfs(c[i][0]);
    if (c[i][1]) dfs(c[i][1]);
}

int main()
{
    while (cin >> n)
    {
        if ( n== 0) break;
        memset(c, 0, sizeof(c));
        for (int i = 2; i <= n; i++) c[i>>1][i&1] = i;
        dfs(1);
        for (auto i = v.begin(); i != v.end(); i++)
        {
            if (i+1 == v.end()) cout<<*i;
            else cout<<*i<<" ";
        }
        cout<<endl;
        v.clear();
    }

    return 0;
}