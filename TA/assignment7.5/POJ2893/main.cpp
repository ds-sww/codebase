/**
 * @author whimsycwd
 * @date   2014.11.7
 *
 */

#include<iostream>
#include<cstdio>
#include<vector>


using namespace std;




void mergeSort(int * data, int l, int r, int * aux, int& reversePair) {
    
    // printf("%d %d\n", l, r);

    if (l + 1 ==  r) return;
    
    int mid = (l+r) / 2;

    mergeSort(data, l, mid, aux, reversePair);
    mergeSort(data, mid, r, aux, reversePair);

    // left part and right part is sorted, merge them.
    
    int lp = l;
    int rp = mid;
    
    for (int i = l; i < r; ++i) {
        if (lp == mid) {
            aux[i] = data[rp++];
        } else {
            if (rp == r) {
                aux[i] = data[lp++];
            } else {
                if (data[lp] <= data[rp]) {
                    aux[i] = data[lp++];
                } else {
                    aux[i] = data[rp++];

                    // calc reversPair here
                    reversePair += (mid - lp);

                }
            }
        }
    }

    for (int i = l; i< r; ++i) {
        data[i] = aux[i];
    }

}


int n, m;

void work() {
    int * grid = new int[n*m];
    int * aux = new int[n*m];
    
    int zeroPos = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &grid[i * m + j]);           
            if (grid[i * m + j] == 0) {
                zeroPos = i + j;
            }
        }
    }
    int reversePair = 0;
    mergeSort(grid, 0, n*m, aux, reversePair);

    if ((zeroPos + m + n + reversePair + m * n + 1) % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    delete [] grid;
    delete [] aux;
}

int main() {
    while (cin >> n >> m && n && m) {
        work();
    }
    return 0;
}
