/**
 * @author XuanYuan
 * @date   2014.11.5
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
        	if(l >= r - 1)
        		return;
        	int m = ( l + r + 1 ) / 2;
        	mergeSort(data, l, m);
        	mergeSort(data, m, r);
        	int i = l, j = m, k = 0;
        	while(i < m && j < r) {
        		if(data[i] < data[j])
        			aux[k++] = data[i++];
        		else
        			aux[k++] = data[j++];
        	}
        	while(i < m)
        		aux[k++] = data[i++];
        	while(j < r)
        		aux[k++] = data[j++];
        	for(int t = 0; t < k; t++)
        		data[l+t] = aux[t];
        }

    public :
      virtual void sort(vector<int> & data) {
        aux = vector<int>(data.size(), 0);
        mergeSort(data, 0, data.size());
      }  
};
