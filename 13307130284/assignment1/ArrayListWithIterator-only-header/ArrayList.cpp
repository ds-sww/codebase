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
    int size() const override;
    bool isEmpty() const override;
    T get(int index) const override;
    void add(T element) override;
    T remove(int index) override;
    ArrayList () { cnt = 0; max_cnt = 0; A = NULL; }
protected :
    std :: size_t cnt;
    std :: size_t max_cnt;
    T*A;
};

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
    if (cnt < max_cnt) {
        A[cnt++] = element; 
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
}

template <typename T>
T ArrayList<T> :: remove(int index) {
    assert(0 <= index && index < cnt);
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
        delete[] (A + max_cnt);
    }
}