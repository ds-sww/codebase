/**
 * @author forward
 * @date   2014.10.07
 * 类似Vector
 */

#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#include <cstring>
#include <stdexcept>
#include <algorithm>
#include <cstddef>

template <typename Item>
class ArrayList {

    const static int INIT_CAP = 1024;

    Item *_arr;
    int _cap, _size;

    void _resize(bool _enlarge)
    {
        int new_cap = _enlarge ? (_cap << 1) : (_cap >> 1);
        Item *_tmp = new Item[new_cap];
        memcpy(_tmp, _arr, std::min(_cap, new_cap) * sizeof(Item));
        std::swap(_arr, _tmp);
        _cap = new_cap;
        delete[] _tmp;
    }

    void _copy(const ArrayList& other)
    {
        _cap = other._cap;
        _size = other._size;
        _arr = new Item[_cap];
        memcpy(_arr, other._arr, _cap * sizeof(Item));
    }

public:

    ArrayList ()
    {
        _cap = INIT_CAP;
        _arr = new Item[_cap];
        _size = 0;
    }

    ArrayList (const ArrayList & other)
    {
        _copy(other);
    }

    ArrayList & operator=(const ArrayList &other)
    {
        if (this != &other) {
            _copy(other);
        }
        return *this;
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
    
    const Item & operator [] (int index)
    {
        return _arr[index];
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
        if (_size + 1 == _cap) _resize(true);
        _arr[_size++] = element;
    }

    Item remove(int index)
    {
        if (index < 0 || index >= _size) {
            throw std::logic_error("out of range");
        }
        Item _ret = _arr[index];
        for (int i = index; i < _size - 1; i++) _arr[i] = _arr[i + 1];
        _size --;
        if (_size <= (_cap >> 2) && _cap > INIT_CAP) _resize(false);
        return _ret;
    }

    struct iterator {
    private:
        const ArrayList<Item> *list;
        const int end;
        int pos;

    public:
        iterator(ArrayList<Item> *_list, bool isEnd) : end(_list->_size)
        {
            list = _list;
            pos = isEnd ? end : 0;
        }

        iterator (const iterator & other) : end(other.end)
        {
            list = other.list;
            pos = other.pos;
        }

        iterator & operator=(const iterator &other)
        {
            if (this != &other) {
                list = other.list;
                pos = other.pos;
                *const_cast<int*>(&end) = other.end;
            }
            return *this;
        }


        Item * operator ->() const
        {
            return &(list->_arr[pos]);
        }

        Item & operator *() const 
        {
            return list->_arr[pos];
        }

        iterator & operator ++()
        {
            pos++;
            return *this;
        }

        iterator operator ++(int)
        {
            iterator _tmp = *this;
            pos++;
            return _tmp;
        }

        iterator & operator --()
        {
            pos--;
            return *this;
        }

        iterator operator --(int)
        {
            iterator _tmp = *this;
            pos--;
            return _tmp;
        }

        ptrdiff_t operator -(const iterator &other) const
        {
            return (this->pos - other.pos);
        }

        bool operator ==(const iterator & other) const
        {
            return (this->list == other.list && this->pos == other.pos);
        }

        bool operator !=(const iterator & other) const
        {
            return (this->list != other.list || this->pos != other.pos);
        }
    };


    iterator begin()
    {
        return iterator(this, false);
    }

    iterator end()
    {
        return iterator(this, true);
    }
};

#endif
