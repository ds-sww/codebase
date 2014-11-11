/**
 * @author Xuan Yuan
 * @date   2014.11.5
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<cassert>
#include<algorithm>
#include<cmath>
#include "Sortable.h"


using namespace std;

class HeapSort : public Sortable {

    private :
        int * heap;
        int heapSize;
		
		//Up用于将最后一个元素向上放到恰当的位置
		void Up() {
			int tmp;
			int i = heapSize - 1;
			while(i > 0) {
				if(heap[i] < heap[(i-1)/2)] {
					tmp = heap[i];
					heap[i] = heap[(i-1)/2];
					heap[(i-1)/2] = tmp;
				} else {
					break;
				}
				i = ( i - 1 ) / 2;
			}
		}
		
		//Down用于将第一个元素向下放到恰当的位置
		void Down() {
			int tmp;
			int i = 0;
			for(int t = 0; t < (int)log2(heapSize); t++) {
				if(heap[i] > heap[2*i+2] && heap[2*i+1] > heap[2*i+2]) {
					tmp = heap[i];
					heap[i] = heap[2*i+2];
					heap[2*i+2] = tmp;
					i = 2 * i + 2;
				}
				else if(heap[i] > heap[2*i+1] && heap[2*i+1] < heap[2*i+2]) {
					tmp = heap[i];
					heap[i] = heap[2*i+1];
					heap[2*i+1] = tmp;
					i = 2 * i + 1;
				}
			}
		}
		
        void push(int x) {
        	heap[heapSize++] = x;
        	Up();
        }
        
        int pop() {
        	int result = heap[0];
        	heap[0] = heap[--heapSize];
        	Down();
        	return result;
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



