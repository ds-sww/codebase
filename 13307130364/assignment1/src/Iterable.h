#include "Iterator.h"

template <typename T>
class Iterable{
    public :
        virtual Iterator<T>* iterator() = 0;
};
