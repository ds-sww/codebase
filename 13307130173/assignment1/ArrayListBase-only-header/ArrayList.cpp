
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> 
{
private:
	int cnt, nowsize;
	T *id;
	void copyarray(T *dest, T *src, int num)
	{
		for (int i = 0; i < num; i++) dest[i] = src[i];
	}
	void expand()
	{
		nowsize <<= 1;
		T *tmp = new T[nowsize];
		copyarray(tmp, id, cnt);
		delete[] id;
		id = tmp;
	}
	void narrow()
	{
		nowsize >>= 1;
		T *tmp = new T[nowsize];
		copyarray(tmp, id, cnt);
		delete[] id;
		id = tmp;
	}
	void rangecheck(int index)const
	{
		assert(index >= 0 && index < cnt);
	}

public:
	ArrayList()
	{
		cnt = 0; nowsize = 1;
		id = new T[nowsize];
	}
	ArrayList(int capacity)
	{
		cnt = 0; nowsize = capacity;
		id = new T[nowsize];
	}
	int size()const
	{
		return cnt;
	}
	bool isEmpty()const
	{
		return cnt == 0;
	}
	T get(int index)const
	{
		rangecheck(index);
		return id[index];
	}
	void add(T element)
	{
		//cout << cnt << " " << nowsize << "\n";
		if (cnt + 1 > nowsize) expand();
		id[cnt++] = element;
	}
	T remove(int index)
	{
		//cout << cnt << " " << nowsize << "\n";
		rangecheck(index);
		T ret = id[index];
		for (int i = index; i < cnt - 1; i++) id[i] = id[i + 1];
		id[--cnt] = 0;
		if (cnt <= nowsize / 4 && nowsize>1) narrow();
		return ret;
	}
	~ArrayList() 
	{
		delete[] id;
	}
};
