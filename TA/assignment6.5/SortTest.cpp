/**
 * @author whimsycwd
 * @date   2014.11.1
 * 
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<ctime>

#include "HeapSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "LinkedList.cpp"

#include "Sortable.h"

using namespace std;
int type;

Sortable * getImpl() {
    if (type == 1) 
        return new HeapSort();

    if (type == 2) 
        return new MergeSort();

    if (type == 3) 
        return new QuickSort();
    
    if (type == 4) 
        return new LinkedList();
    return NULL;
}

int getNumber() {
 // you shound't presume element in [-10^6, 10^6)
    return rand() % 2000000 - 1000000;
}

// note: add element to `data`
void genRandomData(vector<int> &data, int size) {
    for (int i = 0; i < size; ++i) {
        data.push_back(getNumber());  
    }

}

// note: add element to `data`
void genSameData(vector<int> &data, int size) {
    int t = getNumber();
    for (int i = 0; i < size; ++i) {
        data.push_back(getNumber());
    }
}

int testcase = 0;


// for debug
//
void print(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        printf("%d ", vec[i]);
    }
    printf("\n");

}

typedef void (*Fun)(vector<int> &data, int size); 

void single_test(Sortable * impl, Fun func, int cnt) {
    
    printf("testcase %d start, %d element\n", ++testcase, cnt);
    vector<int> data;
    func(data, cnt);
    vector<int> copy = data;
    clock_t start_time = clock();
    impl->sort(data);
    clock_t end_time = clock();
    sort(copy.begin(), copy.end());

    // print(data);
    // print(copy);

    assert(data.size() == copy.size());
    for (int i = 0; i < copy.size(); ++i) {
        assert(data[i] == copy[i]);
    }

    printf("testcase end execution time %lfs\n\n", 
            ((double) end_time - start_time) / CLOCKS_PER_SEC);
}

void test() {
    Sortable * impl = getImpl();

    single_test(impl, genRandomData,  10);
    single_test(impl, genRandomData, 100);

    single_test(impl, genRandomData, 1000000);
    single_test(impl, genRandomData,  10000000);

    single_test(impl, genSameData, 10000000);


    delete impl;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    type = -1;

    if (argc == 2) { 
        if (strcmp(argv[1], "HeapSort") == 0) {
            type = 1;
            cout << "HeapSort" << endl;
        } 
        if (strcmp(argv[1], "MergeSort") == 0) {
            type = 2;
            cout << "MergeSort" << endl;
        }
        if (strcmp(argv[1], "QuickSort") == 0) {
            type = 3;
            cout << "QuickSort" << endl;
        }
        if (strcmp(argv[1], "LinkedList") == 0) {
            type = 4;
            cout << "LinkedList MergeSort" << endl;
        }
    }

    if (type == -1) {
        cout << "Only one parameter in (MegerSort | QuickSort | HeapSort)" << endl;
    } else {
        test(); 
    }

    return 0;
}

