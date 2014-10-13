

#ifndef _ITERABLE_H
#define _ITERABLE_H 1

#include "Iterator.h"

template <typename T>
class Iterable{
    public :
        virtual Iterator<T>* iterator() = 0;
};

#endif
