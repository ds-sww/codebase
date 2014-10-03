#include Iterable.h
#include Iterator.h

template typename T
class List  public IterableT {
    public 
        virtual int size() const = 0;
        virtual bool isEmpty() const = 0;
        virtual T get(int index) const = 0;
        virtual void add(const T& element) = 0;
        virtual T remove(int index) = 0;

};