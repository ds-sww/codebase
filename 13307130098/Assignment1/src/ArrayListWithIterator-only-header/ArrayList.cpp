
/**
 * @author sunqinzheng
 * @date   2014.10.2
 * 类似Vector
 */

#ifndef _ARRAYLIST_CPP
#define _ARRAYLIST_CPP 1

#include <cassert>
#include <algorithm>
#include <stdexcept>
#include "List.h"

#define MAX_LENGTH 30
#define RESERVE_LENGTH 10

template <typename T>
class ArrayList : public List<T> {

private:
	//var
	int sz;
	int version;
	int pow2[MAX_LENGTH];
	T* link[MAX_LENGTH];
	//myfunc
	ArrayList(const ArrayList&);
	int getPos(int index) const;
	void change(int index, T element);
	//class
	template <typename U>
	class ArrayIterator : public Iterator<U>
	{
	private:
		//var
		int version;
		int index;
		ArrayList<U>* root;

	public:
		//func
		ArrayIterator();
		ArrayIterator(ArrayList<U>* r);
		ArrayList& operator=(const ArrayList&);
		bool hasNext();
		U next();

	};

	public:
		//func
		ArrayList();
		~ArrayList();
		int size() const;
	    bool isEmpty() const;
	    T get(int index) const;
	    void add(T element);
	    T remove(int index);
	    Iterator<T>* iterator();
	    //myfunc
	    int getVersion();

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
	version = 0;
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
ArrayList<T>::~ArrayList()
{
	for(int i = 0; i < MAX_LENGTH; i++)
	{
		if(link[i] != NULL)
		{
			delete [] link[i];
		}
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
void ArrayList<T>::add(T element)
{
	//check
	assert(sz < pow2[MAX_LENGTH-1]);

	version++;
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

	version++;
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

template <typename T>
int ArrayList<T>::getVersion()
{
	return version;
}

template <typename T>
Iterator<T>* ArrayList<T>::iterator()
{
	return new ArrayIterator<T>(this);
}
//for ArrayIterator
template <typename T>
template <typename U>
ArrayList<T>::ArrayIterator<U>::ArrayIterator()
{
	index = 0;
	version = 0;
	root = NULL;
}

template <typename T>
template <typename U>
ArrayList<T>::ArrayIterator<U>::ArrayIterator(ArrayList<U>* r)
{
	root = r;
	index = -1;
	version = r->getVersion();
}

template <typename T>
template <typename U>
bool ArrayList<T>::ArrayIterator<U>::hasNext()
{
	//check
	if(version != root->getVersion())
	{
		throw std::logic_error("FFF");
	}

	return index < root->size() - 1;
}

template <typename T>
template <typename U>
U ArrayList<T>::ArrayIterator<U>::next()
{
	index++;
	//check
	assert(index >= 0);
	assert(index < root->size());
	if(version != root->getVersion())
	{
		throw std::logic_error("FFF");
	}

	return root->get(index);
}

#endif
