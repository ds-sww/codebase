/**
 * @author whimsycwd
 * @date   2014.11.1
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
        int * heap;
        int heapSize;
        const static int ROOT = 0;


        void restoreUp(int idx) {
            while (idx != ROOT && heap[(idx - 1) / 2] > heap[idx]) {
                swap(heap[(idx - 1) / 2], heap[idx]);
                idx = (idx - 1) / 2;
            }
        }
        void restoreDown(int idx) {
            while (idx < heapSize) {

                int minIndex = idx;
                if (idx * 2 + 1 < heapSize && 
                        heap[idx * 2 + 1] < heap[minIndex])  {
                    minIndex = idx * 2 + 1;
                } 
                if (idx * 2 + 2 < heapSize && 
                        heap[idx * 2 + 2] < heap[minIndex]) {
                    minIndex = idx * 2 + 2;
                }

                if (idx == minIndex) break;
                else {
                    swap(heap[idx], heap[minIndex]);
                    idx = minIndex;
                }
            
            }
        }

        void push(int x) {
            heap[heapSize] = x;
            restoreUp(heapSize);
            heapSize++; 
        }
        int pop() {
            assert(heapSize > 0);
            int retValue = heap[ROOT];
            
            swap(heap[ROOT], heap[--heapSize]);

            restoreDown(ROOT);  
            return retValue;   
        }
 
    public :
        virtual void sort(vector<int>& data) {
            heap = new int[data.size()];
            heapSize = 0;

            for (int i = 0; i < data.size(); ++i) {
                push(data[i]);
            }

            for (int i = 0; i < data.size(); ++i) {
                data[i] = pop();
            } 
        }
};



