/**
 * @author irmo
 * @date   2014.11.9
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
            
            
            if (l >= r) return;
            int mid = (l + r) / 2;
            mergeSort(data, l, mid);
            mergeSort(data, mid + 1, r);
            for (int i = l; i <= mid; ++i) aux[i] = data[i];
            for (int i = mid + 1; i <= r; ++i) aux [r + mid + 1 - i] = data[i];
            int i = l;
            int j = r;
            for (int k = l; k <= r; ++k) {
                if (aux[i] < aux[j])
                    data[k] = aux[i++];
                else
                    data[k] = aux[j--];
            }
        }
    public :
      virtual void sort(vector<int> & data) {
          aux = vector<int>(data.size(), 0);
          mergeSort(data, 0, data.size() - 1);
      }  
};
