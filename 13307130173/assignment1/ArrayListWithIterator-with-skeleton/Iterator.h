
#ifndef _ITERATOR_H
#define _ITERATOR_H 1

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
};

#endif
