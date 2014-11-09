/**
 * @author whimsycwd
 * @date   2014.11.1
 *
 */


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

#include "Sortable.h"

using namespace std;

class QuickSort : public Sortable {
   
    private :
        void quick_sort(vector<int> & data, int l, int r) {
            if (l >= r) return;
            int i = l;
            int j = r;
            int mid = data[(i + j) / 2];
            while (i <= j) {
                while (data[i] < mid) ++i;
                while (data[j] > mid) --j;
                if (i <= j) {
                    swap(data[i], data[j]);
                    ++i;
                    --j;
                }
            }
            quick_sort(data, l, j);
            quick_sort(data, i, r);
        }

    public :
        virtual void sort(vector<int>& data) {
            quick_sort(data, 0, data.size() -1);
        }
};
