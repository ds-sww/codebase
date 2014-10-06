
/**
 * @author1 whimsycwd
 * @author2 XuanYuan
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> {

private :
    T* array;
    int cnt;
    int capacity;

    int modCnt;  // modification counter

    const static int initialCapacity = 16;

    void arrayCopy(T* dest, T* sou, int num) {
        for (int i = 0; i< num; ++i) {
            dest[i] = sou[i];
        }
    }

    void expandCapacity() {
        capacity = capacity * 2;
        T * newArray = new T[capacity];
        
        arrayCopy(newArray, array, cnt);
        
        delete [] array;
        array = newArray;
    }
    void shrinkCapacity() {
        // funny thing happen without this line
        if (capacity <= initialCapacity) {
            return;
        }

        capacity = capacity / 2;
        T * newArray = new T[capacity];
        
        arrayCopy(newArray, array, cnt);
        
        delete [] array;
        array = newArray;

    }

    void rangeCheck(int index) const {
        assert(index >= 0 && index < cnt);
    }
       
    /**
     * Iterator Implementation
     */

    template <typename E>
    class ArrayIterator : public Iterator<E> {
    private :
            int itCnt;
            int itModCnt;

            ArrayList<E>* outer;

            void modifiedCheck() {
                if (itModCnt != outer->modCnt) {
                    throw logic_error("the host arrayList has been changed!");
                }
            }
            
    public :
            ArrayIterator(ArrayList<E>* outer) {
                itCnt = 0;
                itModCnt = outer->modCnt;
                this->outer = outer;
            }
                
            //done
            bool hasNext() {
                modifiedCheck();
                if (itCnt >= outer->cnt) {
                    return 0;
                }
                return 1;
            }

            //done
            E next() {
                modifiedCheck();
                return outer->array[itCnt++];
            }
        
            ~ArrayIterator() {
                outer = 0;
            }
                 
    };

public :

    ArrayList() {
        capacity = initialCapacity;
        array = new T[capacity];
        cnt = 0;
    }

    ArrayList(int defaultCapacity) {
        if (defaultCapacity <= initialCapacity) {
            defaultCapacity = initialCapacity;
        }
        capacity = defaultCapacity;
        array = new T[capacity];
        cnt = 0;
            
    }
        
    //done
    int size() const {
        return cnt;
    }
    //done
    bool isEmpty() const {
        if (cnt == 0) {
            return 1;
        }
        return 0;
    }
    //done
    T get(int index) const {
        //这里其实应该加入index检测
        return array[index];
    }
    //done
    void add(T element) {
        modCnt++;
        if(cnt == capacity) {
            capacity = capacity + capacity;
            T* tmpList = new T [capacity];
            int i;
            for(i = 0; i < cnt; i++) {
                tmpList[i] = array[i];
            }
            delete[] array;
            array = tmpList;
        }
        array[cnt++] = element;
        return;
    }
    //done
    T remove(int index) {
        modCnt++;
        T result = array[index];
        int i;
        for(i = index; i < cnt-1; i++) {
            array[i] = array[i+1];
        }
        cnt--;
        if(cnt > 0 && cnt*5 < capacity) {
            capacity = capacity/2;
            T* tmpList = new T [capacity];
            int i;
            for(i = 0; i < cnt; i++) {
                tmpList[i] = array[i];
            }
            delete[] array;
            array = tmpList;
        }
        return result;
    }

    // tricky, return a pointer, how to ensure this ArrayIterator free properly
    // can we manage this allocated Iterators by self?
    Iterator<T>* iterator() {
        return new ArrayIterator<int>(this);
    }

    ~ArrayList() {
        delete [] array;
    }

};


