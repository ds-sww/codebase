#include <iostream>
#include <cstdio>
using namespace std;

int n;
int m;

void Merge(int a[], int temp[], int& tot, int l, int r)
{
    int mid = (l + r) / 2;
    int i = l;
    int j = mid + 1;
    int p = l;
    
    while(i <= mid && j <= r)
    {
        if(a[i] > a[j])
        {
            tot += mid - i + 1;
            temp[p++] = a[j++];
        }
        else
        {
            temp[p++] = a[i++];
        }
    }
    
    while(i <= mid) temp[p++] = a[i++];
    while(j <= r)   temp[p++] = a[j++];
    
    for (int k = l; k <= r; k++)
        a[k] = temp[k];
    return;
}

void MergeSort(int a[], int temp[], int& tot, int l, int r)
{
    if (l == r) return;
    
    int mid = (l + r) / 2;
    MergeSort(a, temp, tot, l, mid);
    MergeSort(a, temp, tot, mid+1, r);
    Merge(a, temp, tot, l, r);
    return;
}

void Work()
{
    int xPos = 0;
    int cnt = 0;
    int t;
    
    int tot = 0;
    int *map = new int [(n+1) * (m+1)];
    int *temp = new int [(n+1) * (m+1)];
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &t);
            if (t == 0)
            {
                xPos = i;
            }
            else
            {
                cnt++;
                map[cnt] = t;
            }
        }
        
    MergeSort(map, temp, tot, 1, cnt);

    if ((n & 1) == 1)
    {
        if ((tot & 1) == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        if((tot & 1) == ((m - xPos) & 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    delete [] map;
    delete [] temp;
}

int main()
{
    while (cin >> m >> n && n && m)
    {
        Work();
    }
    return 0;
}
