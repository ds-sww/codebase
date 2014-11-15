#include <iostream>
#include <string>
using namespace std;

const int N = 100005;

int partition (int a[], int l, int r) {
    int i = l-1, j = r;
    int temp = a[r];
    for (;;) {
        while(a[++i] < temp) if (i == r-1) break;
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
    int a[N];
    int i;
    int n,k;
    cin >> n;

    int index;
    for (i = 0; i < n; i++)
        cin >> a[i];

    quicksort(a,0,n-1);

    string seperate;
    cin >> seperate;
    cin >> k;
    for (i = 0; i < k; i++) {
        cin >> index;
        cout << a[index-1] << endl;
    }

}
