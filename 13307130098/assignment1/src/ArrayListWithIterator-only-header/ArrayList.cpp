
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <cstring>
#include <cassert>
#include <stdexcept>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> {
private:
	int version;
	T *link[30];
	int sz;
	int pow2[30];
	
	int getPos(int index) const
	{
		assert(0<index&&index<pow2[29]);
		int l=0,r=29;
		while(l<r)
		{
			int md=(l+r)/2;
			if(pow2[md]>index)r=md;
			else l=md+1;
		}
		return r-1;
	}


	void change(int index,T element)
	{
		assert(index>=0&&index<sz);
		
		index++;
		int pos=getPos(index);
		link[pos][index-pow2[pos]]=element;
	}
	//extra
	template <typename E>
	class MyIterator : public Iterator<E>
	{
	private:
		int version;
		int index;
		E value;
		ArrayList<E>* root;
	public:
		MyIterator(int v,int i,ArrayList<E>* r)
		{
			version=v;
			index=i;
			root=r;
			if(i==-1)
			{
				value=0;
			}
			else
			{
				value=root->get(i);
			}
		}
		T next()
		{
			//version check
			if(version!=root->getVersion())
			{
				throw logic_error("fff");
			}

			index++;
			assert(0<=index&&index<root->sz);
			value=root->get(index);
			return value;
		}
		bool hasNext()
		{
			//version check
			if(version!=root->getVersion())
			{
				throw logic_error("fff");
			}
			return index<root->sz-1;
		}

	};

public:
	ArrayList()
	{
		version=sz=0;
		memset(link,0,sizeof(link));
		pow2[0]=1;
		for(int i=1;i<30;i++)
			pow2[i]=pow2[i-1]*2;
	}

	int size() const
	{
		return sz;
	}

	bool isEmpty() const
	{
		return sz==0;
	}

	T get(int index) const
	{
		assert(index>=0&&index<sz);
		
		index++;
		int pos=getPos(index);
		return link[pos][index-pow2[pos]];
	}

	void add(T element)
	{
		sz++;
		int pos=getPos(sz);
		if(sz==pow2[pos]&&link[pos]==NULL)
		{
			link[pos]=new int[pow2[pos]];
		}
		version++;
		link[pos][sz-pow2[pos]]=element;
	}

	T remove(int index)
	{
		assert(index>=0&&index<sz);

		index++;
		int pos=getPos(index);
		T res=link[pos][index-pow2[pos]];
		
		for(int i=index;i<sz;i++)
		{
			change(i-1,get(i));
		}

		pos=getPos(sz);
		if(sz==pow2[pos]&&link[pos+1]!=NULL)
		{
			delete [] link[pos+1];
			link[pos+1]=NULL;
		}
		sz--;
		version++;
		return res;
	}
	//extra
	int getVersion()
	{
		return version;
	}

	Iterator<T>* iterator()
	{
		return new MyIterator<T>(version,-1,this);
		
	}

};

