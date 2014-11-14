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
    if (i < r) msort(i,r);
    if (j > l) msort(l,j);
}


int main()
{
   // freopen("a.in", "r", stdin);

    int n, num;
    multiset<int> s;
    cin>>n;
    for (int i = 0; i < n; i++) cin>>a[i];
    msort(0, n-1);
    //for (int i = 0; i < n; i++) cout<<a[i]<<" ";

    string whatever;
    cin>>whatever;
    //cout<<whatever<<endl;

    int k, q;
    cin>>k;
    while (k--){
        cin>>q;
        cout<<a[q - 1]<<endl;
    }



    return 0;
}