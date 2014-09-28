//
//  main.cpp
//  assignment1
//
//  Created by billlai on 14-9-28.
//  Copyright (c) 2014年 billlai. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
class List {
    public :
    virtual int size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual T get(int index) const = 0;
    virtual void add(T element) = 0;
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
        return elements[index];
    }
    /*T* listcopy(const ArrayList& forcopy)
    {
        T *temp = new T[forcopy.contain_size];
        for(int i = 0;i<forcopy.the_size;i++)
        {
            temp[i] = forcopy.elements[i];
        }
        return temp;
    }*/
    virtual void add(T element)
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
        if (the_size<contain_size/2)
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


void insert_million_entry() {
    cout << "insert_million_entry start" << endl;
    
    ArrayList<int> list;
    
    for (int i = 0; i< 1000000; ++i) {
        list.add(i);
    }
    assert(list.size() == 1000000);
    for (int i = 0; i< 1000000; ++i) {
        assert(list.get(i) == i);
    }
    
    cout << "insert_million_entry end" << endl;
    
}

void delete_after_insert_entrys() {
    cout << "delete_after_insert_entrys start" << endl;
    
    ArrayList<int> list;
    for (int i = 0; i< 1000; ++i) {
        list.add(i);
    }
    
    assert(list.size() == 1000);
    for (int i = 0; i< 1000; ++i) {
        assert(list.get(i) == i);
    }
    
    for (int i = 0; i<100; ++i) {
        list.remove(0);
    }
    
    assert(list.size() == 900);
    
    for (int i = 100; i<1000; ++i) {
        assert(list.get(i-100) == i);
    }
    
    for (int i = 100; i<1000; ++i) {
        list.remove(0);
    }
    
    assert(list.is_Empty());
    
    cout << "delete_after_insert_entrys end" << endl;
}


void erase(vector<int> & vec, int index) {
    vec.erase(vec.begin() + index);
}

void random_insert_delete_entrys(double insertFactor) {
    cout << "random_insert_delete_entrys start   insertFactor : " << insertFactor <<  endl;
    
    srand((unsigned int) time(NULL));
    
    ArrayList<int> list;
    vector<int> vec;
    
    
    int numOfOp = 100000;
    
    for (int i = 0; i < numOfOp; ++i) {
        int op = random() % 10;
        if (op <= insertFactor) {
            int num = rand() % 1000000;
            list.add(num);
            vec.push_back(num);
        } else {
            if (vec.size() > 0) {
                int num = random() % vec.size();
                
                erase(vec, num);
                list.remove(num);
            }
        }
        assert(vec.size() == list.size());
    }
    
    assert(vec.size() == list.size());
    for (int i = 0; i < vec.size(); ++i) {
        assert(vec[i] == list.get(i));
    }
    
    cout << "random_insert_delete_entrys end." << endl;
}

int main() {
    
    insert_million_entry();
    delete_after_insert_entrys();
    
    for (int i = 0; i< 10; ++i) {
        random_insert_delete_entrys(i);
    }
    
    return 0;
}
