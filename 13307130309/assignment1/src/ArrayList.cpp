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
		int cnt; 
		int time;
		int er[30];
		T *a;
		void repose()
		{
			T *b;
			b=new T[er[time]];
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
			a=new T[16];
			time=4;	
			int i=1;
			er[0]=1;
           		for(i=1;i<29;i++)
                		er[i]=er[i-1]*2;
		}
		ArrayList(const ArrayList <T> &x)
		{
			n=x.n;
			time=x.time;
			a=new T[er[x.time]];
			int i;
			cnt=0;
			for(i=0;i<n;i++)
				a[i]=x[i];
			er[0]=1;
           		for(i=1;i<29;i++)
                		er[i]=er[i-1]*2;
		}
		ArrayList <T> & operator = (const ArrayList <T> &x)
		{
			if(a!=x.a)
			{
				delete[] a;	
				a= new T[er[x.time]];
				n=x.n;
				cnt++;
				time=x.time;
				int i;
       				for(i=0;i<n;i++)
					a[i]=x.a[i];
			}
			return *this;
		}
		~ArrayList()
		{
			delete[] a;
			n=0;
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
        		if(n>=er[time])
       	 		{
        			time++;
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
        		if(n<er[time-1]&&time>4)
        		{
				time--;
				this->repose();
        		}
        		return o;
       	 	}
        	Iterator<T>* iterator()
        	{
        		return new AL_Iterator<T>(this);
        	}
};
