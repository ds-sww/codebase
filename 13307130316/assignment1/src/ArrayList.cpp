
/**
 * @author Minjun-Li
 * @date   2104.09.28
 */
 
#include <iostream>
#include <cassert>
#include <cstring>
#include "List.h"

using namespace std;



template <typename T>
class ArrayList : public List<T> 
{
    private:
    	T* Array;
    	int ArraySize;
    	int UsedSize;
    	//int const DefaultSize;

    	void getspace()
    	{
            ;
    	}

    	void resize(int size)
    	{
            T *retptr = new T[size];
            if (size <= 0)
            {
                cerr << "Invalid Array Size" << endl;
                return;
            }
            if (retptr == NULL)
            {
                cerr << "Memory Allocation Error" << endl;
                return;
            }
            for (int i = 0; i < ArraySize && i < size; i++)
                retptr[i] = Array[i];
            ArraySize = size;
            Array = retptr;
    	}


    public:
    	ArrayList(int size = 1000)
    	{
    		if(size >= 0)
    		{
                UsedSize = 0;
    			ArraySize = size;
    			Array = new T [ArraySize];
    		}
    		//else
    			//TODO Error
    	}

    	ArrayList(const ArrayList <T> &sourse)
    	{
    		ArraySize = sourse.ArraySize;
    		UsedSize = sourse.UsedSize;
    		Array = new T [ArraySize];
    		T* scrptr = sourse.Array;
    		T* destptr = Array;
            memcpy(destptr,scrptr,UsedSize);
    	}

    	~ArrayList()
    	{
    		delete [] Array;
    	}

        Iterator<T>* iterator()
        {
            ;
        }

    	int size() const
    	{
    		return UsedSize;
    	}

    	bool isEmpty() const
    	{
    		if(UsedSize == 0)
                return 1;
    		else
                return 0;
    	}

    	T get(int index) const
    	{
    		if(index >= 0 && index < UsedSize)
    		{
    			return Array[index];
    		}
    		// TODO Error
    	}

    	void add(T element)
    	{
    		if(UsedSize >= ArraySize)
    		{
                resize(ArraySize * 2);
    		}
    		Array[UsedSize] = element;
            UsedSize++;
    	}

    	T remove(int index)
    	{
            T ret = Array[index];
            for(int i = index + 1; i < UsedSize; i++)
            {
                Array[i - 1] = Array[i];
            }
            UsedSize--;
            if(UsedSize < ArraySize / 3)
            {
                resize(ArraySize / 3);
            }
            return ret;
    	}
};
