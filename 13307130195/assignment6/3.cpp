#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[21000], b[21000];

void sorta(int i, int j)
{
    int l = i, r = j, m = a[(i+j)/2];
    while (i<=j)
    {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (i < r) sorta(i,r);
    if (j > l) sorta(l,j);
}

void sortb(int i, int j)
{
    int l = i, r = j, m = b[(i+j)/2];
    while (i<=j)
    {
        while (b[i] < m) i++;
        while (b[j] > m) j--;
        if (i <= j)
        {
            swap(b[i], b[j]);
            i++;
            j--;
        }
    }
    if (i < r) sortb(i,r);
    if (j > l) sortb(l,j);
}



int main()
{
  //  freopen("a.in", "r", stdin);


    int n, m;
    while (cin>>n>>m)
    {
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++) cin>>a[i];
        for (int i = 0; i < m; i++) cin>>b[i];

        sorta(0, n - 1);
        sortb(0, m - 1);

        int k = 0, g = 0;
        long long ans = 0;
        while (k < m && g < n)
        {
            if (b[k] < a[g])
            {
                k++;
                continue;
            }
            ans += (long long)b[k];
            k++;
            g++;
        }

        if (g != n)
        {
            cout<<"Loowater is doomed!"<<endl;
        }
        else {
            cout<<ans<<endl;
        }
    }



}