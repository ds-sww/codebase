#include <iostream>
#include <cassert>
#include "List.h"
#include <stdexcept>

using namespace std;

template <typename T>
class ArrayList : public List<T> {
public:
    int cnt;
    private :
        T* array;
        int capacity;

        int modCnt = 0;  // modification counter

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

        //template<typename T>
        class ArrayIterator : public Iterator<T> {
            private :
                int itCnt;
                int itModCnt;

                ArrayList<T>* outer;



                void modifiedCheck() {
                    if (itModCnt != outer->modCnt) {
                        throw logic_error("the host arrayList has been changed!");
                    }
                }

            public :
                ArrayIterator(ArrayList<T>* outer) {
                    itCnt = 0;
                    itModCnt = outer->modCnt;
                    this->outer = outer;
                }

                bool hasNext() {
                	return itCnt!=outer->cnt;
                }

                T next() {
                	modifiedCheck();
                	return outer->get(itCnt++);
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

                Iterator<T>* iterator(){
                	return new ArrayIterator(this);
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
                	if(cnt>=capacity-1)
                		expandCapacity();
                	array[cnt++]=element;
                	modCnt++;
                }

                T remove(int index) {
                	rangeCheck(index);
                	T tmp=array[cnt];
                	for(int i=index;i<cnt-1;i++){
                		array[i]=array[i+1];
                	}
                	if(cnt<capacity/2-1){
                		shrinkCapacity();
                	}
                	cnt--;
                	modCnt++;

                	return tmp;
                }

                ~ArrayList() {
                    delete [] array;
                }

        };