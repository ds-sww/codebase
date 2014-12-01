#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;
string pre, post;
int c[30][30];
int m;

int calc(int sp, int ss, int n)
{
    sp ++;
    n--;
    int p = 0, c0 = 0, c1 = 1;
    for (int i = 0; i <= n; i++)
    if (pre[sp + p] == post[ss + i])
    {
        c0 ++;
        c1 *= calc(sp + p, ss + p, i - p + 1);
        p = i + 1;
    }
    return c1 * c[m][c0];
}


int main()
{
   // freopen("a.in", "r", stdin);

    for (int i = 0; i < 30; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
    }


    while (cin >> m)
    {
        if (m == 0) break;
        cin>>pre>>post;
        cout<<calc(0,0,pre.length())<<endl;
    }
}