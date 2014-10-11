
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

const int MINCAPACITY = 10;

template <typename T>
class ArrayList : public List<T> {

	template <typename U>
	class ArrayListIterator : public Iterator<U>
	{
	private:
		ArrayList<U> *arrayList;
		int index, version;

	public:
		ArrayListIterator()
		{
		}

		ArrayListIterator(ArrayList<U> *_arrayList)
		{
			index = 0;
			arrayList = _arrayList;
			version = arrayList->version;
		}

		~ArrayListIterator()
		{
		}

		// Iterator.h
        bool hasNext()
        {
        	return index < arrayList->mSize;
        }

        T next()
        {
        	if(version != arrayList->version)
        		throw logic_error("The arrayList has already been changed.");
        	return arrayList->array[index++];
        }
	};

private:

	T *array;
	int mCapacity, mSize, version;

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
		version = 0;
		mSize = 0;
		mCapacity = MINCAPACITY;
		array = new T[mCapacity]();
	}

	~ArrayList()
	{
		delete[] array;
	}

	// List.h

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

	void add(const T &element)
	{
		++version;
		// capacity is not enough
		if(mSize == mCapacity)
		{
			resize(mCapacity << 1);
		}

		array[mSize++] = element;
	}

	T remove(int index)
	{
		++version;

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

	// Iterable.h
	Iterator<T>* iterator()
	{
		ArrayListIterator<T> *_iterator= new ArrayListIterator<T>(this);
		return _iterator;
	}
};
