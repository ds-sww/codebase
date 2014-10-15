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

#define random rand


void insert_million_entry(List<int>& list) {
    cout << "insert_million_entry start" << endl;

    for (int i = 0; i< 1000000; ++i) {
        list.add(i); 
    }
    assert(list.size() == 1000000);
    for (int i = 0; i< 1000000; ++i) {
        assert(list.get(i) == i);
    }

    cout << "insert_million_entry end" << endl;
    
}

void delete_after_insert_entrys(List<int>& list) {
    cout << "delete_after_insert_entrys start" << endl;

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

void random_insert_delete_entrys(List<int>& list, double insertFactor) {
    cout << "random_insert_delete_entrys start   insertFactor : " << insertFactor <<  endl;

    srand((unsigned long) time(NULL));    

    vector<int> vec;  


    int numOfOp = 100000;

    for (int i = 0; i < numOfOp; ++i) {
        int op = random() % 10; 
        if (op <= insertFactor) {
            int num = rand() % 1000000;
            list.add(num);            
            vec.push_back(num);
        } else {
            if (vec.size() > 0) {
                int num = random() % vec.size();

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

void iterate_through_list(List<int>& list) {
    cout << "iterate_through_list start" << endl;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }

    Iterator<int>* iter = list.iterator();
    
    int cnt = 0;
    while (iter->hasNext()) {
        assert(list.get(cnt++) == iter->next());
    }

    delete iter;
    cout << "iterate_through_list end" << endl;

}

void iterator_fast_fail_feature(List<int>& list) {
    cout << "iterator_fast_fail_feature start" << endl;

    list.add(1);
    Iterator<int>* iter = list.iterator();
    try {    
        while (iter->hasNext()) {
            iter->next();
            list.add(2);
        }
    } catch (logic_error e) {
        cout << e.what() << endl;
    }

    delete iter;

    cout << "iterator_fast_fail_feature end" << endl;
}

int main() {
   
    ArrayList<int> list;
    insert_million_entry(list);
    
    ArrayList<int> list2;
    delete_after_insert_entrys(list2);
    
    for (int i = 0; i< 10; ++i) {
        ArrayList<int> list3;
        random_insert_delete_entrys(list3, i);
    }

    ArrayList<int> list4;
    iterate_through_list(list4);

    ArrayList<int> list5;
    iterator_fast_fail_feature(list5);
    
    return 0;
}


