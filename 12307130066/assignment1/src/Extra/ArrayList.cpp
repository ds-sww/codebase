
/**
 * @author XuanYuan
 * @date   2014.9.28
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"
#include "Iterable.h"
#include "Iterator.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> {
public:
    //List继承来的方法们
    int size() const;
    bool isEmpty() const;
    T get(int index) const;
    void add(T element);
    T remove(int index);
    
    //Iterable继承来的方法
    Iterator<T>* iterator();
    
    ArrayList();
    ~ArrayList();
private:
    int capacity;
    int eleCount;
    T* list;
    
    template <typename Q>
    class XYIterator: public Iterator<Q> {
    public:
        XYIterator() {
            this->outer = outer;
            curr = -1;
        }
        bool hasNext() {
            if (curr <= (outer->capacity)-1) {
                return 0;
            }
            return 1;
        }
        Q next() {
            return outer->list[++curr];
        }
    private:
        int curr;
        ArrayList<Q> *outer;
    };
};

template <typename T>
int ArrayList<T>::size() const {
    return eleCount;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    if(eleCount <= 0)
        return 1;
    else
        return 0;
}

template <typename T>
T ArrayList<T>::get(int index) const {
    return list[index];
}

template <typename T>
void ArrayList<T>::add(T element) {
    if(eleCount == capacity) {
        capacity = capacity + capacity;
        T* tmpList = new T [capacity];
        int i;
        for(i = 0; i < eleCount; i++) {
            tmpList[i] = list[i];
        }
        delete[] list;
        list = tmpList;
    }
    list[eleCount++] = element;
    return;
}

template <typename T>
T ArrayList<T>::remove(int index) {
    T result = list[index];
    int i;
    for(i = index; i < eleCount-1; i++) {
        list[i] = list[i+1];
    }
    eleCount--;
    if(eleCount > 0 && eleCount*5 < capacity) {
        capacity = capacity/2;
        T* tmpList = new T [capacity];
        int i;
        for(i = 0; i < eleCount; i++) {
            tmpList[i] = list[i];
        }
        delete[] list;
        list = tmpList;
    }
    return result;
}

template <typename T>
Iterator<T>* ArrayList<T>::iterator() {
    XYIterator<T>* newIter;
    newIter = new XYIterator<T>;
    return newIter;
}











