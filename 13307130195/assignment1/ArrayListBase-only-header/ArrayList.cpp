
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> {

    T *_M;
    int _L, _Size;

    void _resize(bool _enlarge)
    {
        int __L = _enlarge ? (_L << 1) : (_L >> 1);
        T *_tmp = new T[__L];
        if (_enlarge) memcpy(_tmp, _M, _L * sizeof(T));
        else memcpy(_tmp, _M, __L * sizeof(T));

        delete[] _M;
        _M = _tmp;
        _L = __L;
    }


public:

    ArrayList ()
    {
        _M = new T[100000];
        _L = 100000;
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
            cerr<<"out of range!"<<endl;
            exit(1);
        }
        return _M[index];
    }
    
    void add(T element)
    {
        if (_Size == _L) _resize(true);
        _M[_Size++] = element;
    }

    T remove(int index)
    {
        if (index < 0 || index >= _Size) {
            cerr<<"out of range!"<<endl;
            exit(1);
        }
        T _ret = _M[index];
        for (int i = index; i < _Size - 1; i++) _M[i] = _M[i + 1];
        _Size --;
        if (_Size <= (_L >> 1)) _resize(false);
        return _ret;
    }

    ~ArrayList ()
    {
        delete[] _M;
    }
};



int main(int argc, char const *argv[])
{
    // ArrayList<int> list;
    // for (int i = 0; i < 1000000; i++) list.add(i);

    // cout<<list.size()<<endl;
    
    //     for (int i = 0; i< 1000000; ++i) {
    //     // assert(list.get(i) == i);
    //     cout<<list.get(i)<<endl;
    // }

    ArrayList<int> list;
    for (int i = 0; i< 1000; ++i) {
        list.add(i);
    }
    
    assert(list.size() == 1000);
    for (int i = 0; i< 1000; ++i) {
        assert(list.get(i) == i);
    }

    for (int i = 0; i<100; ++i) {
        list.remove(0);
    }
    
    assert(list.size() == 900);

    for (int i = 100; i<1000; ++i) {
        assert(list.get(i-100) == i);
    }

    for (int i = 100; i<1000; ++i) {
        list.remove(0);
    }
    
    assert(list.isEmpty());

    return 0;
}
