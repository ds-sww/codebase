
/**
 * @author Minjun-Li
 * @date   2104.09.28
 */

#ifndef _ARRAYLIST_CPP
#define _ARRAYLIST_CPP

#include <iostream>
#include <cassert>
#include <stdexcept>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> 
{
    private:
    	T* Array;
    	int ArraySize;
    	int UsedSize;

        int ModifiedTimes;

        T* get_array(int size)
        {
            T* ret = new T[size];
            if (ret == NULL)
            {
                cerr << "Memory Allocation Error" << endl;
            }
            return ret;
        }

    	void resize(int size)
    	{
            if (size <= 0)
            {
                cerr << "Invalid Array Size" << endl;
                size = ArraySize;
            }

            T *retptr = get_array(size);
            for(int i = 0; i < ArraySize && i < size; i++)
            {
                retptr[i] = Array[i];
            }
            delete [] Array;
            ArraySize = size;
            Array = retptr;
    	}

        template <typename E>
        class ArrayIterator : public Iterator<E>
        {
            private:
                int Index;
                int ModifiedTimes;
                ArrayList<E> *Outer;

                void modified_check()
                {
                    if(ModifiedTimes != Outer->ModifiedTimes)
                    {
                        throw std::logic_error("the host arrayList has been changed!");
                    }
                }

            public:
                ArrayIterator(ArrayList<E> *sourse)
                {
                    Index = 0;
                    ModifiedTimes = sourse->ModifiedTimes;
                    this->Outer = sourse;
                }

                ~ArrayIterator()
                {
                    Outer = NULL;
                }

                bool hasNext()
                {
                    modified_check();
                    return Index < Outer->UsedSize;
                }

                E next()
                {
                    modified_check();
                    E ret = Outer->Array[Index];
                    Index++;
                    return ret;
                }

        };

    public:
    	ArrayList(int size = 1000)
    	{
    		if(size < 0)
    		{
                cerr << "Invalid Array Size" << endl;
                size = 1000;
    		}
            ModifiedTimes = 0;
            ArraySize = size;
            UsedSize = 0;
            Array = new T [ArraySize];
    	}

    	ArrayList(const ArrayList <T> &sourse)
    	{
            ModifiedTimes = sourse.ModifiedTimes;
    		ArraySize = sourse.ArraySize;
    		UsedSize = sourse.UsedSize;
    		Array = new T [ArraySize];

    		T* scrptr = sourse.Array;
    		T* destptr = Array;
            for(int i = 0; i < UsedSize; i++)
            {
                destptr[i] = scrptr[i];
            }
    	}

    	~ArrayList()
    	{
    		delete [] Array;
    	}

        Iterator<T>* iterator() 
        {
            return new ArrayIterator<int>(this);
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
    		else
            {
                cerr << "Invalid Array Element" << endl;
                exit(0);
            }
    	}

    	void add(const T &element)
    	{
    		if(UsedSize >= ArraySize)
    		{
                resize(ArraySize * 2);
    		}
    		Array[UsedSize] = element;
            UsedSize++;
            ModifiedTimes++;
    	}

    	T remove(int index)
    	{
            if(index <0 || index >= UsedSize)
            {
                cerr << "Invalid Array Element" << endl;
                exit(0);
            }

            T ret = Array[index];
            for(int i = index + 1; i < UsedSize; i++)
            {
                Array[i - 1] = Array[i];
            }
            UsedSize--;
            ModifiedTimes++;
            if(UsedSize < ArraySize / 3)
            {
                resize(ArraySize / 2);
            }
            return ret;
    	}
};

#endif

