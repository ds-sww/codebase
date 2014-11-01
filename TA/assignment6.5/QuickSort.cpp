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
            if (l + 1 >= r) 
                return;

            int i = l;            
            int j = r;
            int pole = data[(l + r) / 2];
            while (i < j) {
                while (i<r && data[i] < pole) ++i;
                while (j>l && data[j-1] > pole) --j; 
                
                if (i<j) {
                    swap(data[i], data[j-1]);
                    ++i;
                    --j;
                }
            }

            quick_sort(data, i, r);
            quick_sort(data, l, j);

        }

    public :
        virtual void sort(vector<int>& data) {
            quick_sort(data, 0, data.size());
        }
};
