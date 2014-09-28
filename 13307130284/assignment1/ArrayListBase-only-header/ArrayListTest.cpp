/**
 * @author whimsycwd
 * @date   2014.9.26
 * 只测试了Type = int 的情况
 */


#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "ArrayList.cpp"

using namespace std;


void insert_million_entry() {
    cout << "insert_million_entry start" << endl;

    ArrayList<int> list;

    for (int i = 0; i< 1000000; ++i) {
        list.add(i); 
    }
    assert(list.size() == 1000000);
    for (int i = 0; i< 1000000; ++i) {
        assert(list.get(i) == i);
    }

    cout << "insert_million_entry end" << endl;
    
}

void delete_after_insert_entrys() {
    cout << "delete_after_insert_entrys start" << endl;

    ArrayList<int> list;
    for (int i = 0; i< 1000; ++i) {
        list.add(i);
    }
    
    assert(list.size() == 1000);
    for (int i = 0; i< 1000; ++i) {
        assert(list.get(i) == i);
    }

    for (int i = 0; i<100; ++i) {
        list.remove(0);
    }
    
    assert(list.size() == 900);

    for (int i = 100; i<1000; ++i) {
        assert(list.get(i-100) == i);
    }

    for (int i = 100; i<1000; ++i) {
        list.remove(0);
    }
    
    assert(list.isEmpty());
        
    cout << "delete_after_insert_entrys end" << endl;
}


void erase(vector<int> & vec, int index) {
    vec.erase(vec.begin() + index);
}

void random_insert_delete_entrys(double insertFactor) {
    cout << "random_insert_delete_entrys start   insertFactor : " << insertFactor <<  endl;

    srand((unsigned long) time(NULL));    

    ArrayList<int> list;
    vector<int> vec;  


    int numOfOp = 100000;

    for (int i = 0; i < numOfOp; ++i) {
        int op = rand() % 10; 
        if (op <= insertFactor) {
            int num = rand() % 1000000;
            list.add(num);            
            vec.push_back(num);
        } else {
            if (vec.size() > 0) {
                int num = rand() % vec.size();

                erase(vec, num);
                list.remove(num);
            }           
        }
        assert(vec.size() == list.size());
    }

    assert(vec.size() == list.size());
    for (int i = 0; i < vec.size(); ++i) {
        assert(vec[i] == list.get(i));    
    }

    cout << "random_insert_delete_entrys end." << endl;
}


int main() {
    
    insert_million_entry();
    delete_after_insert_entrys();
    
    for (int i = 0; i< 10; ++i) {
        random_insert_delete_entrys(i);
    }
    
    return 0;
}


