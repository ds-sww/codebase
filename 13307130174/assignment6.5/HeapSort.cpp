/**
 * @author irmo
 * @date   2014.11.9
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<cassert>
#include<algorithm>
#include "Sortable.h"


using namespace std;

class HeapSort : public Sortable {

    private :
        void Fixdown(vector<int> &data,int heap, int size) {
            int lchild = heap * 2 + 1;
            int rchild = heap * 2 + 2;
            while (rchild < size) {
                if (data[lchild] <= data[heap] && data[rchild] <= data[heap]) return;
                    if (data[lchild] > data[rchild]) {
                        swap(data[lchild], data[heap]);
                        heap = lchild;
                    }
                    else {
                        swap(data[rchild], data[heap]);
                        heap = rchild;
                    }
                lchild = heap * 2 + 1;
                rchild = heap * 2 + 2;
            }
            if (lchild < size && data[lchild] > data[heap]) swap(data[lchild], data[heap]);
            return;
        }
    
        void heapSort(vector<int> &data, int l, int r) {
            int size = r - l + 1;
            for (int i = r; i >= l; --i) {
                Fixdown(data, i, size);
            }
            while (size > 0) {
                swap(data[0], data[size - 1]);
                Fixdown(data, 0, --size);
            }
            return;
        }
    
    public :
        virtual void sort(vector<int>& data) {
            int size = data.size();
            heapSort(data, 0, size - 1);
        }
};



