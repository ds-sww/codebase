<<<<<<< HEAD


#ifndef _ITERABLE_H
#define _ITERABLE_H 1

#include "Iterator.h"

template <typename T>
class Iterable{
    public :
        virtual Iterator<T>* iterator() = 0;
};

#endif
=======


#ifndef _ITERABLE_H
#define _ITERABLE_H 1

#include "Iterator.h"

template <typename T>
class Iterable{
    public :
        virtual Iterator<T>* iterator() = 0;
};

#endif
>>>>>>> 8bffb9679e44469c6ebc032e686acbaee19a8507
