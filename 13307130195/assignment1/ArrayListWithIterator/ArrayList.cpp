
/**
 * @author forward
 * @date   2014.9.28
 * 类似Vector
 */
#include <cstring>
#include <stdexcept>
#include <algorithm>
#include "List.h"


template <typename Item>
class ArrayList : public List<Item> {

    const static int INIT_CAP = 1024;
    const static int BUFF_LEN = 256;

    Item *_arr;
    int _cap, _size;
    long long _ver; //version number to validate iterators

    void _resize(bool _enlarge)
    {
        int new_cap = _enlarge ? (_cap << 1) : (_cap >> 1);
        Item *_tmp = new Item[new_cap];
        memcpy(_tmp, _arr, std::min(_cap, new_cap) * sizeof(Item));
        std::swap(_arr, _tmp);
        _cap = new_cap;
        delete[] _tmp;
    }


public:

    ArrayList ()
    {
        _cap = INIT_CAP;
        _arr = new Item[_cap];
        _size = 0;
        _ver = 0;
    }

    ~ArrayList ()
    {
        delete[] _arr;
        _cap = 0;
        _size = 0;
    }

    int size() const
    {
        return _size;
    }

    bool isEmpty() const
    {
        return _size == 0;
    }
    
    Item get(int index) const
    {
        if (index < 0 || index >= _size) {
            throw std::logic_error("out of range");
        }
        return _arr[index];
    }
    
    void add(const Item &element)
    {
        if (_size == _cap) _resize(true);
        _arr[_size++] = element;
        _ver ++;
    }

    Item remove(int index)
    {
        if (index < 0 || index >= _size) {
            throw std::logic_error("out of range");
        }
        _ver ++;
        Item _ret = _arr[index];
        for (int i = index; i < _size - 1; i++) _arr[i] = _arr[i + 1];
        _size --;
        if (_size <= (_cap >> 1) - BUFF_LEN && _cap > INIT_CAP) _resize(false);
        return _ret;
    }

    class ArrayListIterator : public Iterator<Item>{
        ArrayList<Item> *list;
        int pos, end;
        long long ver;

            void validateIterator()
            {
                if (ver != list->_ver) 
                    throw std::logic_error("this iterator is not valid anymore!");
            }

        public:
            ArrayListIterator(ArrayList<Item> *_list)
            {
                pos = 0;
                list = _list;
                ver = _list->_ver;
                end = _list->_size;
            }

            ~ArrayListIterator()
            {
                list = NULL;
            }

            bool hasNext()
            {
                validateIterator();
                return pos < end - 1;
            }

            Item next()
            {
                validateIterator();
                return list->get(pos++);
            }
    };

    Iterator<Item>* iterator()
    {
        return new ArrayListIterator(this);
    }

};
