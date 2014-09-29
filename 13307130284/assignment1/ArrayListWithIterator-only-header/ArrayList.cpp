#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <ctime>
#include <cstdlib>
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