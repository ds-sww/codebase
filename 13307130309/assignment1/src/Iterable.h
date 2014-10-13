/**
 * @author whimsycwd
 * @date   2014.9.27
 * 实现该接口的容器拥有迭代的能力
*/

#ifndef _ITERABLE_H
#define _ITERABLE_H 1

#include "Iterator.h"

template <typename T>
class Iterable{
    public :
        virtual Iterator<T>* iterator() = 0;
};
#endif

