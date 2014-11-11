#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[110000];

void msort(int i, int j)
{
    int l = i, r = j, m = abs(a[(i+j)/2]);
    while (i<=j)
    {
        while (abs(a[i]) < m) i++;
        while (abs(a[j]) > m) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (i < r) msort(i,r);
    if (j > l) msort(l,j);
}

int main()
{

   // freopen("a.in", "r", stdin);
    int n, t;
    cin >> t>> n;
    for (int i = 0; i < n; i++) cin>>a[i];
    msort(0, n-1);

    int ans = 0, pre = 0, p = 0;
    while (t > 0)
    {
        if (t < abs(a[p] - pre)) break;
        t-= abs(a[p] - pre);
        ans++;
        pre = a[p++];
    }

    cout<<ans<<endl;


}