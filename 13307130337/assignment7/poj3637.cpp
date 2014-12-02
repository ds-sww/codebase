#include <iostream>
#include <cstdio>
using namespace std;

void QuickSort(int a[], int l, int r)
{
    int i = l;
    int j = r;
    int mid = a[(l + r) / 2];

    while(i <= j)
    {
        while (a[i] > mid) i++;
        while (a[j] < mid) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    
    if (i < r) QuickSort(a, i, r);
    if (l < j) QuickSort(a, l, j);
    return;
}

void Work()
{
    int n;
    int * money;
    int ans = 0;
    
    scanf("%d", &n);
    money = new int [n + 1];
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &money[i]);
    }    
    
    QuickSort(money, 1, n);
    
    for(int i = 1; i <= n; i++)
    {
        if(i % 3 == 0) ans += money[i];
    }
    cout << ans << endl;
    
    delete [] money;

    return;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        Work();
    }
    return 0;
}
