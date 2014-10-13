#include Iterator.h

template typename T
class Iterable{
    public 
        virtual IteratorT iterator() = 0;
};