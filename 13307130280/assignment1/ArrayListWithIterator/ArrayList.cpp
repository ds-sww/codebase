#include<iostream>
#include<cstdio>
#include<cassert>
#include<stdexcept>
#include"List.h"
using namespace std;

template <typename T>
class ArrayList:public List<T>
{

	template <typename E>
	class ArrayIterator:public Iterator<E>
	{
	public:
		ArrayIterator(ArrayList<E>* outer)
		{
			It_Size=0;
			It_Time=outer->List_Time;
			this->outer=outer;
		}
		~ArrayIterator()
		{
			outer=0;
		}
		bool hasNext()
		{
			TimeCheck();
			return It_Size < outer->List_Size;
		}
		E next()
		{
			TimeCheck();
			if (It_Size >= outer->List_Size)
				throw out_of_range("ArrayIterator");
			return outer->get(It_Size++);
		}
	private:
		int It_Size,It_Time;
		ArrayList<E>* outer;
		void TimeCheck()
		{
			if (It_Time != outer->List_Time)
				throw logic_error("the host arrayList has been changed!");
		}
	};
public:
	ArrayList()
	{
		Array=new T;
		List_Size=0;
		List_MSize=1;
		List_Time=0;
	}
	~ArrayList()
	{
		delete[] Array;
	}
	int size() const
	{	
		return List_Size;
	}
	bool isEmpty() const
	{
		if (List_Size==0) return true;
		else return false;
	}
	T get(int index) const
	{
		assert(index>=0 && index<List_Size);
		return Array[index]; 
	}
	void add(const T& element)
	{
		List_Time++;
		if (List_MSize>List_Size)
		{
			Array[List_Size]=element;
			List_Size++;
		}
		else
		{
			T *TArray;
			TArray=Array;
			List_MSize+=List_MSize;
			Array=new T[List_MSize];
			for (int index=0;index<List_Size;index++)
				Array[index]=TArray[index];
			delete[] TArray;
			Array[List_Size]=element;
			List_Size++;
		}


		return;
	}
	T remove(int index)
	{

		T Temp;
		assert(index>=0 && index<List_Size);
		Temp=Array[index];
		List_Time++;
		if (List_Size<=(List_MSize/4))
		{	
			List_MSize/=2;
			T *TArray;
			TArray=Array;
			Array=new T[List_MSize];
			for (int Index=0;Index<List_Size;Index++)
			{
				if (Index<index) Array[Index]=TArray[Index];
				else Array[Index]=TArray[Index+1];
			}
			delete[] TArray;
		}
		else
		{
			for (int Index=index;Index<List_Size-1;Index++)
				Array[Index]=Array[Index+1];
		}
		Array[--List_Size]=0;
		return Temp;
	}
        Iterator<T>* iterator() {
            return new ArrayIterator<T>(this);
        }
private:
	T *Array;
	int List_Size,List_MSize,List_Time;
};
