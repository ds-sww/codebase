#include<iostream>
#include<cstdio>
#include <cstdlib>
#include <cassert>
#include "List.h"
#include "Iterator.h"
#include "Iterable.h"
using namespace std;

class logic_error
{
	string ch;
	public:
		logic_error(string a)
		{
			ch=a;
		}
		string what()
		{
			return ch;
		}
};
template<typename T>
class ArrayList: public List<T>
{
	private:
  		int n;
		int million;
		int cnt; 
		T *a;
		void repose()
		{
			T *b;
			b=new T[million*10000];
			int i;
			for(i=0;i<n;i++)
				b[i]=a[i];
			delete[] a;
			a=b;
		}
		template <typename E> 
		class AL_Iterator: public Iterator<E>
		{
			private:
				int itCnt;
				int pos;
				ArrayList<E> *pointer;
				void WrongReport()
				{
					if(itCnt!=pointer->cnt)
					{
					    throw logic_error("the host arrayList has been changed!");
					}
					return;
				}
			public:
				AL_Iterator(ArrayList<E> *outer)
				{
					pos=0;
					itCnt=outer->cnt;
					pointer=outer;
				}
				E next()
				{
					this->WrongReport();
					pos++;
					return pointer->a[pos-1];
				}
				bool hasNext()
				{
					this->WrongReport();
					if(pos==pointer->n-1)
						return 0;
					return 1;
				}
		};
		
	public:
		ArrayList()
		{
			n=0;
			cnt=0;
			million=1;
			a=new T[million*10000];	
		}
		ArrayList(const ArrayList <T> &x)
		{
			n=x.n;
			million=x.million;
			a=new T[million*10000];
			int i;
			cnt=0;
			for(i=0;i<n;i++)
				a[i]=x[i];
		}
		ArrayList <T> & operator = (const ArrayList <T> &x)
		{
			delete[] a;
			a= new T[x.million*10000];
			n=x.n;
			cnt++;
			million=x.million;
			int i;
        	for(i=0;i<n;i++)
				a[i]=x.a[i];
			return *this;
		}
		~ArrayList()
		{
			delete[] a;
			n=0;
			million=1;
		}
		int size() const
        {
			return n;
		}
        bool isEmpty() const
        {
        	if(n==0)
	        	return 1;
        	return 0;
        }
        T get(int index) const
        {
        	return a[index];
        }
        void add(T element)
        {
        	n++;
			cnt++;
        	if(n>=million*10000)
        	{
        		million++;
	        	this->repose();
	        }
	        a[n-1]=element;
        }
        T remove(int index)
        {
        	int i;
			cnt++;
			T o=a[index];
        	for(i=index;i<n;i++)
        	{
        		a[i]=a[i+1];
        	}
        	n--;
        	if(n<(million-1)*10000)
        	{
				million--;
				this->repose();
        	}
        	return o;
        }
        Iterator<T>* iterator()
        {
        	return new AL_Iterator<T>(this);
        }
};
/*
int main()
{
	ArrayList<int> R,S;

	int i,j;
	
	for(i=0;i<100;i++)
	{
		R.add(i);
	}
	S=R;
	Iterator<int>* iter = R.iterator();
	i=0;
    while (iter->hasNext()) {
        if(R.get(i++) == iter->next())
        printf("WIN WIN WIN!");
    }
	
    printf("%d %d %d %d %d\n",S.get(0),S.get(1),S.get(2),S.get(3),S.isEmpty()); 
	return 0;
}*/
