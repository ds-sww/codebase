#include <iostream>
#include <cassert>
#include <stdexcept>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList: public List<T>
{
	private:

	const static int sizeDefault=1024;
	int n, Maxn, revision;
	T *arr;

	template <typename T_it>
	class ArrayIterator: public Iterator<T_it>
	{
		private:

		T_it *pt, *arr_end;
		int revision_origin;
		ArrayList<T_it> *list_origin;

		public:

		ArrayIterator() {}

		ArrayIterator(ArrayList<T> *list)
		{
			pt=list->arr;
			arr_end=(list->arr)+(list->n);
			revision_origin=list->revision;
			list_origin=list;
		}

		bool hasNext() const
		{
			if (revision_origin!=(list_origin->revision))
				throw logic_error("The ArrayList has been modified!");
			return pt!=arr_end;
		}

		T_it next()
		{
			assert(hasNext());
			return *(pt++);
		}
	};

	public:

	ArrayList()
	{
		Maxn=sizeDefault;
		n=revision=0;
		arr=new int[Maxn];
	}

	~ArrayList()
	{
		delete[] arr;
	}

	int size() const
	{
		return n;
	}

	bool isEmpty() const
	{
		return n==0;
	}

	T get(int index) const
	{
		assert(0<=index && index<n);
		return arr[index];
	}

	void add(const T &element)
	{
		++revision;
		if (n==Maxn)
		{
			Maxn<<=1;
			T *temp=new T[Maxn];
			for (int i=0; i<n; ++i) temp[i]=arr[i];
			delete[] arr;
			arr=temp;
		}
		arr[n++]=element;
	}

	T remove(int index)
	{
		++revision;
		T element=get(index);
		for (int i=index+1; i<n; ++i) arr[i-1]=arr[i];
		--n;
		if (n*4<=Maxn && Maxn/2>=sizeDefault)
		{
			Maxn>>=1;
			T *temp=new T[Maxn];
			for (int i=0; i<n; ++i) temp[i]=arr[i];
			delete[] arr;
			arr=temp;
		}
		return element;
	}

	Iterator<T>* iterator()
	{
		return new ArrayIterator<T>(this);
	}
};

