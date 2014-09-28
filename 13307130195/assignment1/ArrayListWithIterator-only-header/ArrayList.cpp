
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <memory>
#include <stdexcept>
#include "List.h"

#define CAP 1000

using namespace std;

template <typename T>
class ArrayList : public List<T> {

    T *_M;
    int _L, _Size;
    long long _Ver; //version number to validate iterators

    void _resize(bool _enlarge)
    {
        int __L = _enlarge ? (_L << 1) : (_L >> 1);
        T *_tmp = new T[__L];
        memcpy(_tmp, _M, min(_L, __L) * sizeof(T));
        swap(_M, _tmp);
        _L = __L;
        delete[] _tmp;
    }


public:

    ArrayList ()
    {
        _L = CAP;
        _M = new T[_L];
        _Size = 0;
        _Ver = 0;
    }

    ~ArrayList ()
    {
        delete[] _M;
        _L = 0;
        _Size = 0;
    }

    int size() const
    {
        return _Size;
    }

    bool isEmpty() const
    {
        return _Size == 0;
    }
    
    T get(int index) const
    {
        if (index < 0 || index >= _Size) {
            throw logic_error("out of range");
        }
        return _M[index];
    }
    
    void add(const T &element)
    {
        if (_Size == _L) _resize(true);
        _M[_Size++] = element;
        _Ver ++; // version updated
    }

    T remove(int index)
    {
        if (index < 0 || index >= _Size) {
            throw logic_error("out of range");
        }
        T _ret = _M[index];
        for (int i = index; i < _Size - 1; i++) _M[i] = _M[i + 1];
        _Size --;
        _Ver ++; // version updated
        if (_Size <= (_L >> 1) && _L > CAP) _resize(false);
        return _ret;
    }

    class ArrayListIterator : public Iterator<T>{
        ArrayList<T> *_al;
        int pos;
        int size;
        long long ver;

            void iteratorIsValid()
            {
                if (ver != _al->_Ver)
                    throw logic_error("this iterator is not valid anymore!");
            }

        public:
            ArrayListIterator(ArrayList<T> *_outer)
            {
                _al = _outer;
                pos = 0;
                ver = _outer->_Ver;
                size = _outer->_Size;
            }

            ~ArrayListIterator()
            {
                _al = NULL;
            }

            bool hasNext()
            {
                iteratorIsValid();
                return pos < size - 1;
            }

            T next()
            {
                iteratorIsValid();
                return _al->get(pos++);
            }
    };

    Iterator<T>* iterator()
    {
        return new ArrayListIterator(this);
    }

};
