
/**
 * @author whimsycwd
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
        
        // TODO : fill it.
        int size() const {
	    return cnt;
        }
        bool isEmpty() const {
            return cnt == 0;
        }

        // TODO : fill it.
        T get(int index) const {
	   
            return array[index];	
        }

        // TODO : fill it.
        void add(T element) {
	    if(cnt==capacity)
	    {
 	        expandCapacity();
	    }
	    array[cnt++]=element;
        } 
        
        // TODO : fill it. 
        T remove(int index) {
	    int element=array[index];
	    cnt--;
	    for(int i=index;i<cnt;i++)
	    {
	        array[i]=array[i+1];
	    }
	    while(capacity>initialCapacity&&double(cnt)/capacity<0.20)
	    {
			shrinkCapacity();
        }
		}


        ~ArrayList() {
            delete [] array;
        }

};


