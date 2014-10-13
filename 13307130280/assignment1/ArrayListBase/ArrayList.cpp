
/**
 * @author qini7
 * @date   2014.10.07
 * 类似Vector
 */
#include<iostream>
#include<cassert>
#include<stdexcept>
#include"List.h"
using namespace std;

template <typename T>
class ArrayList:public List<T>
{

public:
	ArrayList()
	{
		array=new T;
		list_size=0;
		list_msize=1;
	}
	~ArrayList()
	{
		delete[] array;
	}
	int size() const
	{	
		return list_size;
	}
	bool isEmpty() const
	{
		return (!list_size);
	}
	T get(int index) const
	{
		assert(index>=0 && index<list_size);
		return array[index]; 
	}
	void add(const T& element)
	{
		if (list_msize>list_size)
		{
			array[list_size++]=element;
		}
		else
		{
			T *tarray;
			tarray=array;
			list_msize+=list_msize;
			array=new T[list_msize];
			for (int i=0;i<list_size;i++)
				array[i]=tarray[i];
			delete[] tarray;
			array[list_size++]=element;
		}
	}
	T remove(int index)
	{

		T temp;
		assert(index>=0 && index<list_size);
		temp=array[index];
		if (list_size<=(list_msize>>2))
		{	
			list_msize>>1;
			T *tarray;
			tarray=array;
			array=new T[list_msize];
			for (int i=0;i<list_size;i++)
			{
				if (i<index) array[i]=tarray[i];
				else array[i]=tarray[i+1];
			}
			delete[] tarray;
		}
		else
		{
			for (int i=index;i<list_size-1;i++)
				array[i]=array[i+1];
		}
		array[--list_size]=0;
		return temp;
	}
private:
	T *array;
	int list_size,list_msize;
};
