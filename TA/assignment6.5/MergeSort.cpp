/**
 * @author whimsycwd
 * @date   2014.11.1
 *
 */

#include<iostream>
#include<cstdio>
#include<vector>

#include "Sortable.h"

using namespace std;

class MergeSort : public Sortable {

    private:
        vector<int> aux;
    
        void mergeSort(vector<int> & data, int l, int r) {
            
            // printf("%d %d\n", l, r);

            if (l + 1 ==  r) return;
            
            int mid = (l+r) / 2;

            mergeSort(data, l, mid);
            mergeSort(data, mid, r);

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
                        if (data[lp] < data[rp]) {
                            aux[i] = data[lp++];
                        } else {
                            aux[i] = data[rp++];
                        }
                    }
                }
            }

            for (int i = l; i< r; ++i) {
                data[i] = aux[i];
            }

        }

    public :
      virtual void sort(vector<int> & data) {
        aux = vector<int>(data.size(), 0);
        mergeSort(data, 0, data.size());
      }  
};
