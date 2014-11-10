/*
*	Copyright (C)	Lyq root#lyq.me
*	File Name     : List.h
*	Creation Time : 2014/10/12 00:37:10
*	Environment   : Ubuntu 14.04-64bit
*	Hompage       : http://www.lyq.me
*/


template <typename T>
class List 
{
public :
    virtual int size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual T& get(int index) const = 0;
    virtual void add(T element) = 0;
    virtual T remove(int index) = 0;

};

