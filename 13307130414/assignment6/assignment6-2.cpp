#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int N = 50005;

int partition (int a[], int l, int r) {
    int i = l-1, j = r;
    int temp = a[r];
    for (;;) {
        while(abs(a[++i]) < abs(temp)) if (i == r) break;
        while(abs(a[--j]) > abs(temp)) if (j == l) break;
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
    int a[N];
    int i;
    int t,n;
    int count;
    int time = 0;
    cin >> t >> n;

    for (i = 0; i < n; i++)
        cin >> a[i];

    quicksort(a,0,n-1);

    time = abs(a[0]);
    for (i = 1; i < n; i++){
        if (time > t) break;
        count++;
        time = time + abs(a[i]-a[i-1]);
    }
    cout << count;
}
