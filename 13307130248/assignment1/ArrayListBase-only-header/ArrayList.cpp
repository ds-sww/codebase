
/**
 * @author ChenYuxin
 * @date   2014.10.8
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

const int MINCAPACITY = 10;

template <typename T>
class ArrayList : public List<T> {

private:

	T *array;
	int mCapacity, mSize;

	void resize(int n, T val = T())
	{
		T *old_array = array;
		
		mCapacity = n;

		array = new T[mCapacity]();

		for(int i = 0; i < mSize; i++)
		{
			array[i] = old_array[i];
		}

		delete[] old_array;
	}

public:

	ArrayList()
	{
		mSize = 0;
		mCapacity = MINCAPACITY;
		array = new T[mCapacity]();
	}

	~ArrayList()
	{
		delete[] array;
	}

	int size() const
	{
		return mSize;
	}

	bool isEmpty() const
	{
		return mSize == 0;
	}

	T get(int index) const
	{
		return array[index];
	}

	void add(T& element)
	{
		// capacity is not enough
		if(mSize == mCapacity)
		{
			resize(mCapacity << 1);
		}

		array[mSize++] = element;
	}

	T remove(int index)
	{
		int element = array[index];
		
		mSize--;
		
		for(int i = index; i < mSize; i++)
		{
			array[i] = array[i + 1];
		}

		if(mCapacity > MINCAPACITY && double(mSize) / mCapacity < 0.20)
		{
			resize(max(MINCAPACITY, mSize << 1));
		}

		return element;
	}

};
