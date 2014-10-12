/*
*	Copyright (C)	Lyq root#lyq.me
*	File Name     : ArrayList.cpp
*	Creation Time : 2014/10/12 00:39:59
*	Environment   : Ubuntu 14.04-64bit
*	Hompage       : http://www.lyq.me
*/

#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

template <typename T>
class TypeArray
{
public:
	T t;
	TypeArray *next;
	TypeArray() {next=NULL;}
	TypeArray(const TypeArray &x)
	{
		t = x->t;
		next = x->next;
	}
};
template <typename T>
class ArrayList : public List<T> 
{
private:
	int length;
	TypeArray<T> *head, *tail;

public:
	ArrayList()
	{
		length = 0;
		head = new TypeArray<T>;
		tail = head;
	}
	int size() const
	{
		return length;
	}
	bool isEmpty() const
	{
		if (length == 0) return true;
		return false;
	}
	T& get(int index) const
	{
		int c = 0;
		TypeArray<T> *element = head;
		while (c <= index)
		{
			if (element == NULL)
			{
				cout << endl;
			}
			element = element->next;
			c++;
		}
		return element->t;
	}
	void add(T element)
	{
		TypeArray<T> *one = new TypeArray<T>;
		one->t = element;
		length++;
		tail->next = one;
		tail = one;
	}
	T remove(int index)
	{
		TypeArray<T> *one = head;
		T value;
		length--;
		while (index--) one = one->next;
		TypeArray<T> *second = one->next;
		value = second->t;
		one->next = second->next;
		if (one->next == NULL) tail = one;
		delete second;
		return value;
	}
};
