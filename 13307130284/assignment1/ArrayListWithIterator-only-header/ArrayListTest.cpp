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
#include <stdexcept>
#include <cstring>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> {
public :
    Iterator<T>* iterator() override;
    int size() const override;
    bool isEmpty() const override;
    T get(int index) const override;
    void add(T element) override;
    T remove(int index) override;
    ArrayList () { cnt = 0; max_cnt = 0; A = NULL; }
    int cnt;
    int max_cnt;
    int version;
    T*A;
};


template <typename T>
class ArrayListIterator : public Iterator<T> {
public : 
    bool hasNext() override ;
    T next() override;
    ArrayListIterator() ;
    int current_index, version;
    ArrayList<T> *A;
    ArrayListIterator(int ti, int tv, ArrayList<T> *ta) ;
};

template <typename T>
ArrayListIterator<T> :: ArrayListIterator() {
}

template <typename T>
ArrayListIterator<T> :: ArrayListIterator(int ti, int tv, ArrayList<T> *ta)  {
    //printf("%d\n", tv);
    current_index = ti; version = tv;
    A = ta;
}

template <typename T>
bool ArrayListIterator<T> :: hasNext() {
    if (version != A->version) {
       // printf("%d %d\n", version, A->version);
        puts("ERROR!");
        throw "version doesn't match!";
    }
    return current_index < A->cnt - 1;
}

template <typename T> 
T ArrayListIterator<T> :: next() {
    //assert(version == A->version);
    if (version != A->version) {
        throw "version doesn't match!";
    }
    return A->get(++current_index);
}




template <typename T>
Iterator<T>* ArrayList<T> :: iterator() {
    ArrayListIterator<T> tmp(-1, version, this);
    Iterator<T>* ret = &tmp;
    return ret;
}

template <typename T>
int ArrayList<T> :: size() const {
    return cnt;
}

template <typename T>
bool ArrayList<T> :: isEmpty() const {
    return cnt == 0;
}

template <typename T>
T ArrayList<T> :: get(int index) const {
    assert(0 <= index && index < cnt);
    return A[index];
}

template <typename T>
void ArrayList<T> :: add(T element) {
    ++version;
    if (cnt < max_cnt) {
        A[cnt++] = element; 
        cout << version << ' ' << cnt << ' ' << max_cnt << endl;
        return ;
    } else {
        if (max_cnt == 0) {
            max_cnt = 2;
            A = new T[2];
            A[0] = element;
            cnt = 1;
        } else {
            T*B = new T[max_cnt << 1];
            memcpy(B, A, sizeof(T) * max_cnt);
            delete[] A;
            A = B;
            A[cnt++] = element;
            max_cnt <<= 1;
        }
    }
    cout << version << ' ' << cnt << ' ' << max_cnt << endl;
}

template <typename T>
T ArrayList<T> :: remove(int index) {
    assert(0 <= index && index < cnt);
    
    //printf("size = %d maxcnt = %d\n", cnt, max_cnt);

    T ret = A[index];
    for (int i = index; i < cnt - 1; ++i) {
        A[i] = A[i + 1];
    }
    --cnt;
    if (cnt == 0) {
        max_cnt = 0;
        delete[] A;
    }
    if ((max_cnt >> 2) >= cnt) {
        max_cnt >>= 1;
        T*B = new T[max_cnt];
        memcpy(B,A,sizeof(T) * max_cnt);
        delete[] A;
        A = B;
        //delete[] (A + max_cnt);
    }
}

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
        //fprintf(stderr, "i = %d \n", i);
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

void iterate_through_list(List<int>& list) {
    cout << "iterate_through_list start" << endl;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }

    Iterator<int>* iter = list.iterator();
    
    int cnt = 0;
    while (iter->hasNext()) {
        int a = list.get(cnt++);
        int b = iter->next();
        printf("%d %d\n", a, b);
        assert(a == b);
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
   
    /*ArrayList<int> list;
    insert_million_entry(list);
    
    ArrayList<int> list2;
    delete_after_insert_entrys(list2);
    
    for (int i = 0; i< 10; ++i) {
        ArrayList<int> list3;
        random_insert_delete_entrys(list3, i);
    }
    */
    ArrayList<int> list4;
    iterate_through_list(list4);

    ArrayList<int> list5;
    iterator_fast_fail_feature(list5);
    
    return 0;
}


