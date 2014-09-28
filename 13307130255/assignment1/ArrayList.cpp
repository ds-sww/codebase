
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include <stdexcept>
#include "List.h"

#define _default_size 10000

using namespace std;

template <typename T>
class ArrayList : public List<T> {
    int _size,_max;
    T * _A;
    

    void resize(int n)
    {
        int i;
        T * _B;
        _B = new T[n];
        for(i=0;i<_size;i++) _B[i] = _A[i];
        _max = n;
        delete[] _A;
        _A = _B;
    }
    
    //Iterator Begin
    template <typename E>
    class ArrayIterator : public Iterator<E>{
        int _itp,_itsize;
        ArrayList<E> * outer;
    public:
        ArrayIterator(ArrayList<E> * outer)
        {
            _itp = 0;
            _itsize = outer->_size;
            this->outer = outer;
        }
        ~ArrayIterator()
        {
            outer = 0;
        }
        bool hasNext()
        {
            if(_itp<_itsize) return true;
            else return false;
        }
        T next()
        {
            if(_itsize!=outer->_size)
                throw logic_error("the host arrayList has been changed!");
            return outer->get(_itp++);
        }
    };
    //Iterator End
public:
    ArrayList()
    {
        _size = 0;
        _max = _default_size;
        _A = new T[_max];
    }
    ~ArrayList()
    {
        delete[] _A;
    }
    //Function Begin
    int size() const
    {
        return _size;
    }
    bool isEmpty() const
    {
        if(_size==0)
            return true;
        else
            return false;
    }
    T get(int index) const
    {
        if(index<_size && index>=0)
            return _A[index];
        else
            return 0;
    }
    void add(const T& element)
    {
        if(_size==_max) resize(_max * 2);
        _A[_size++] = element;
        
    }
    T remove(int index)
    {
        if(index>=_size || index<0) return 0;
        int i,temp;
        temp=_A[index];
        for(i=index;i<_size-1;i++) _A[i]=_A[i+1];
        _size--;
        if(_max>_default_size && _size * 3 <= _max) resize(_max / 2);
        return temp;
        
    }
    //Function End
    
    //iterator()
    Iterator<T>* iterator()
    {
        return new ArrayIterator<T>(this);
    }
};
