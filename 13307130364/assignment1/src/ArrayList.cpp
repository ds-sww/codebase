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

        void add(T element) {
        	if(cnt>=capacity-1)
        		expandCapacity();
        	array[cnt++]=element;
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
        	
        	return tmp;
        }

        ~ArrayList() {
            delete [] array;
        }

};
