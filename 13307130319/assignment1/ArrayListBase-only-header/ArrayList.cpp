#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList: public List<T>
{
	private:

	const static int sizeDefault=1024;
	int n, Maxn;
	T *arr;

	public:

	ArrayList()
	{
		Maxn=sizeDefault;
		n=0;
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
};

