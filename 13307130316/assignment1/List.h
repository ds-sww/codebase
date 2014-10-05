/**
 *  @author whimsycwd
 *  @date   2014.9.26
 *
 *  List Interface
 */

#ifndef _LIST_H
#define _LIST_H 1

// #include "Iterable.h"
// #include "Iterator.h"
// 不知道为什么，用include就一直Error，是编译器的问题？


template <typename T>
class Iterator {
    public :
        /**
        * Return true if the iteration has more elements
        */
        virtual bool hasNext() = 0;
        /**
        *  Returns the next element in the iteration
        */
        virtual T next() = 0;

        // get warn if without this.
        // http://stackoverflow.com/questions/461203/when-to-use-virtual-destructors        
        virtual ~Iterator() {
        }        
};

template <typename T>
class Iterable{
    public :
        virtual Iterator<T>* iterator() = 0;
};


template <typename T>
class List : public Iterable<T> {
    


    public :
        virtual int size() const = 0;
        virtual bool isEmpty() const = 0;
        virtual T get(int index) const = 0;
        virtual void add(const T& element) = 0;
        virtual T remove(int index) = 0;


};

#endif

