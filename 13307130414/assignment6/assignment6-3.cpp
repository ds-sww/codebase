#include <iostream>
#include <string>
using namespace std;

const int N = 20005;

int partition (int a[], int l, int r) {
    int i = l-1, j = r;
    int temp = a[r];
    for (;;) {
        while(a[++i] < temp) if (i == r) break;
        while(a[--j] > temp) if (j == l) break;
        if (i >= j) break;
        swap(a[i],a[j]);
    }
    swap(a[i],a[r]);
    return i;
}

void quicksort (int a[], int l, int r) {
    int i;
    if ((r-l) < 1) return;
    i = partition(a, l, r);
    quicksort(a,l,i-1);
    quicksort(a,i+1,r);
}

int main()
{
    int n,m;
    int dragon[N];
    int knights[N];
    int i,j;
    int cost;
    bool flag = true;

    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;

        cost = 0;
        flag = true;
        for (i = 0; i < n; i++)
            cin >> dragon[i];
        for (i = 0; i < m; i++)
            cin >> knights[i];

        quicksort(dragon,0,n-1);
        quicksort(knights,0,m-1);

        j = 0;
        for (i = 0; i < n; i++) {
            while (dragon[i] > knights[j] && j < m)
                j++;
            if (j == m) {
                flag = false;
                break;
            }
            cost = cost + knights[j];
            j++;
        }
        if (flag == false)
            cout << "Loowater is doomed!" << endl;
        else
            cout << cost << endl;
    }
}
