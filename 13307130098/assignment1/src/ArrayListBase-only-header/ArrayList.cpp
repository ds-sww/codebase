
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <cstring>
#include <cassert>
#include "List.h"

using namespace std;
#define the_magic_number 30
template <typename T>
class ArrayList : public List<T> {
private:
	int version;
	T *link[the_magic_number];
	int sz;
	int pow2[the_magic_number];
	
	int getPos(int index) const
	{
		assert(0<index&&index<pow2[the_magic_number-1]);
		int l=0,r=the_magic_number-1;
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

public:
	ArrayList()
	{
		version=sz=0;
		memset(link,0,sizeof(link));
		pow2[0]=1;
		for(int i=1;i<the_magic_number;i++)
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
		int reserved = 6;
		if(sz==pow2[pos]&&link[pos+1]!=NULL&&pos>reserved)
		{
			delete [] link[pos+1];
			link[pos+1]=NULL;
		}
		sz--;
		version++;
		return res;
	}
};
