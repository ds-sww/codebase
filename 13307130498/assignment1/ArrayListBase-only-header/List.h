#ifndef __List__H__
#define __List__H__

template <typename T>
class List {
    
    
    
    public :
    virtual int size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual T get(int index) const = 0;
    virtual void add(T element) = 0;
    virtual T remove(int index) = 0;
    
};


#endif
