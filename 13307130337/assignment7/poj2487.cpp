#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void QuickSort(int a[], int l, int r)
{
    int i = l;
    int j = r;
    int mid = a[(l+r) / 2];

    while (i <= j)
    {
        while (a[i] > mid) i++;
        while (a[j] < mid) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if(i <= r) QuickSort(a, i, r);
    if(l <= j) QuickSort(a, l, j);
}

void Work()
{
    int need;
    int n;
    cin >> need >> n;
    
    int * stamp = new int [n + 1];
    for (int i = 1; i <= n; i++)
        cin >> stamp[i];

    QuickSort(stamp, 1, n);

    int cur = 0;
    int ans = 0;
    bool isPossible = false;

    for (int i = 1; i <= n; i++)
    {
        cur += stamp[i];
        ans++;

        if (cur >= need)
        {
            isPossible = true;
            break;
        }
    }

    if (isPossible == true)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "impossible" << endl;
    }

    delete [] stamp;
    return;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Scenario #" << i << ":" << endl;
        Work();
        cout << endl;
    }

    return 0;
}
