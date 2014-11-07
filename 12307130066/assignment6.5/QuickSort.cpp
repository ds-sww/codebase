/**
 * @author Xuan Yuan
 * @date   2014.11.5
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
            if(l >= r)
            	return;
            int i = l, j = r;
            int ctrl = data[l];
            while(i < j) {
            	while(data[j] >= ctrl && i != j)
            		j--;
            	data[i] = data[j];
            	
            	while(data[i] < ctrl && i != j)
            		i++;
            	data[j] = data[i];
            }
            data[i] = ctrl;
            quick_sort(data, l, i-1);
            quick_sort(data, i+1, r);
        }

    public :
        virtual void sort(vector<int>& data) {
            quick_sort(data, 0, data.size()-1);
        }
};
