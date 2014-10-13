
/**
 * @author sunqinzheng
 * @date   2014.10.2
 * 类似Vector
 */

#ifndef _ARRAYLIST_CPP
#define _ARRAYLIST_CPP 1

#include <cassert>
#include <algorithm>
#include "List.h"

#define MAX_LENGTH 30
#define RESERVE_LENGTH 10

template <typename T>
class ArrayList : public List<T> {

private:
	//var
	int sz;
	int pow2[MAX_LENGTH];
	T* link[MAX_LENGTH];
	//myfunc
	int getPos(int index) const;
	void change(int index, T element);

	public:
		//func
		ArrayList();
		int size() const;
	    bool isEmpty() const;
	    T get(int index) const;
	    void add(T& element);
	    T remove(int index);

	};

//private
template <typename T>
int ArrayList<T>::getPos(int index) const
{
	return std::upper_bound(pow2, pow2+MAX_LENGTH, index+1) - pow2 - 1;
}

template <typename T>
void ArrayList<T>::change(int index, T element)
{
	assert(index >= 0);
	assert(index < sz);

	int linkPos = getPos(index);
	link[linkPos][index + 1 - pow2[linkPos]] = element;
}

//public
template <typename T>
ArrayList<T>::ArrayList()
{
	sz = 0;
	for(int i = 0; i < MAX_LENGTH; i++)
	{
		link[i] = NULL;
	}
	pow2[0] = 1;
	for(int i = 1; i < MAX_LENGTH; i++)
	{
		pow2[i] = pow2[i-1] << 1;
	}
}

template <typename T>
int ArrayList<T>::size() const
{
	return sz;
}

template <typename T>
bool ArrayList<T>::isEmpty() const
{
	return sz == 0;
}

template <typename T>
T ArrayList<T>::get(int index) const
{
	//check
	assert(index >= 0);
	assert(index < sz);

	int linkPos = getPos(index);
	return link[linkPos][index + 1 - pow2[linkPos]];
}

template <typename T>
void ArrayList<T>::add(T& element)
{
	//check
	assert(sz < pow2[MAX_LENGTH-1]);

	int linkPos = getPos(sz);
	//new
	if(link[linkPos]==NULL)
	{
		link[linkPos] = new T[pow2[linkPos]];
	}

	link[linkPos][(++sz) - pow2[linkPos]] = element;
}

template <typename T>
T ArrayList<T>::remove(int index)
{
	//check
	assert(index >= 0);
	assert(index < sz);

	int linkPos = getPos(index);
	T res = get(index);
	for(int i = index; i < sz-1; i++)
	{
		change(i, get(i+1));
	}
	//delete
	if(sz == pow2[linkPos] &&
	link[linkPos+1] != NULL &&
	linkPos+1 > RESERVE_LENGTH)
	{
		delete [] link[linkPos+1];
		link[linkPos+1] = NULL;
	}

	sz--;
	return res;
}

#endif
