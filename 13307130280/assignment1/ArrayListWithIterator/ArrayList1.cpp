
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include <stdexcept>
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
                
                bool hasNext() {
                    modifiedCheck();
                    
                    return itCnt < outer->cnt;
                }
                E next() {
                    modifiedCheck();
                    
                    if (itCnt >= outer->cnt) {
                        throw out_of_range("ArrayIterator");
                    }

                    return outer->get(itCnt++);
                }
                virtual ~ArrayIterator() {
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

        int size() const {
            return cnt;
        }
        bool isEmpty() const {
            return cnt == 0;
        }
        T get(int index) const {
            rangeCheck(index);
        
            return array[index];
        }
        void add(const T& element) {
            if (cnt == capacity) {
                expandCapacity();
            }
            
            // for fast fail 
            ++modCnt;

            array[cnt++] = element; 
        } 
        
        T remove(int index) {
            rangeCheck(index);
            
            T retValue = array[index];

            for (int i = index; i < cnt-1; ++i) {
                array[i] = array[i + 1];
            }
            
            // for fast fail
            ++modCnt;

            // TODO: suitable? 
            // even if array store pointer, we can't free it in this container. 
            // or it will cause dangle pointer outside.
            // 0 is amazing~ stand for numeric and NULL!
            array[--cnt] = 0;

            if (cnt <= capacity / 4) {
                shrinkCapacity();
            }
            return retValue;
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


