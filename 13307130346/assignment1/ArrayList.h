//
//  ArrayList.h
//  assignment1
//
//  Created by billlai on 14-9-28.
//  Copyright (c) 2014年 billlai. All rights reserved.
//

#ifndef __assignment1__ArrayList__
#define __assignment1__ArrayList__

#include <stdio.h>

#endif /* defined(__assignment1__ArrayList__) */
#include <iostream>

using namespace std;

template <typename T>
class List {
    public :
    virtual int size() const = 0;
    virtual bool is_Empty() const = 0;
    virtual T get(int index) const = 0;
    virtual void add(const T& element) = 0;
    virtual T remove(int index) = 0;
    
};

template <typename T>
class ArrayList: public List<T>
{
    int the_size;
    T * elements;
    int contain_size;
public:
    ArrayList()
    {
        elements = NULL;
        the_size = 0;
        contain_size = 0;
    }
    ArrayList(const ArrayList& tocopy)
    {
        if (tocopy.elements==NULL || tocopy.the_size==0)
        {
            elements = NULL;
            the_size = 0;
            contain_size = 0;
        }
        else if (tocopy.contain_size<tocopy.the_size)
            cerr << "Error!" << endl;
        else
        {
            the_size = tocopy.the_size;
            contain_size = tocopy.contain_size;
            elements = new T[contain_size];
            for(int i = 0;i<the_size;i++)
            {
                elements[i] = tocopy.elements[i];
            }
        }
    }
    ~ArrayList()
    {
        delete []elements;
    }
    virtual int size() const
    {
        return the_size;
    }
    virtual bool is_Empty() const
    {
        if (elements==NULL || the_size==0)
            return true;
        return false;
    }
    virtual T get(int index) const
    {
        if (index<the_size)             // 需要检查是否越界！
            return elements[index];
        else
        {
            cerr << "Error." <<endl;
            return -1;
        }
    }
    /*T* listcopy(const ArrayList& forcopy)         //确实用函数来实现更好
     {
     T *temp = new T[forcopy.contain_size];
     for(int i = 0;i<forcopy.the_size;i++)
     {
     temp[i] = forcopy.elements[i];
     }
     return temp;
     }*/
    virtual void add(const T& element)
    {
        if (contain_size==0)
        {
            contain_size = 100;
            elements = new T[100];
        }
        if (contain_size==the_size+1)
        {
            contain_size = 2*contain_size;
            T *temp = new T[contain_size];
            for(int i = 0;i<the_size;i++)
            {
                temp[i] = elements[i];
            }
            delete []elements;
            elements = temp;
        }
        elements[the_size] = element;
        the_size++;
    }
    virtual T remove(int index)
    {
        T tempT = elements[index];
        for(int i = index;i<the_size-1;i++)
        {
            elements[i] = elements[i+1];
        }
        the_size--;
        if (the_size<contain_size/4)            //如果小于1/4而只收缩1/2或许更好~ 可以避免又再次增长
        {
            contain_size = contain_size/2;
            T *temp = new T[contain_size];
            for(int i = 0;i<the_size;i++)
            {
                temp[i] = elements[i];
            }
            delete []elements;
            elements = temp;
        }
        return tempT;
    }
};
