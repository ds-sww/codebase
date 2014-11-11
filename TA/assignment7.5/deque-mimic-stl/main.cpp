/**
 * @author whimsycwd
 * @date   2014.11.9
 *
 */


#include<iostream>
#include<cstdio>
#include<cassert>

using namespace std;

class Deque {

 public :
     typedef int** map_node;
     typedef int* ptr;
     typedef int& ref;
     typedef int type;
     

 private : 
    const static int minimum_capacity = 8;
    const static int default_buffer_size = 1024;

    struct _deque_iterator {
        typedef _deque_iterator self;

        ptr cur;
        ptr first;
        ptr last;
        map_node node;

        ref operator*() const {
            return *cur;
        }

        ptr operator->() const {
            return &(operator*());
        }

        self& operator++() {
            ++cur;
            if (cur == last) {
                set_node(node + 1);
                cur = first;
            }
            return *this;
        }

        self operator++(int) {
            _deque_iterator tmp = *this;
            ++*this;
            return tmp;
        }

        self& operator--() {
            if (cur == first) {
                set_node(node - 1);
                cur = last - 1;
            } else {
                --cur;
            }
            return *this;
        }
        self operator--(int) {
            _deque_iterator tmp = *this;
            --*this;
            return tmp;
        }

        self& operator+=(int n) {
            int offset = n + (cur - first);
            if (offset >= 0 && offset < default_buffer_size) {
                cur += n;
            } else {
                int nodeOffsset = offset >= 0 ? offset / default_buffer_size 
                    : ((-offset) - 1) / default_buffer_size - 1;
                set_node(node + nodeOffsset);
                cur = first + (offset - nodeOffsset * default_buffer_size);
            }

            return *this;
        }
        self operator+(int n) const {
            _deque_iterator tmp = *this;
            return tmp += n;
        }

        self& operator-=(int n) {
            return *this += -n;
        }

        self operator-(int n) const {
            _deque_iterator tmp = *this;
            return tmp -= n;
        }

        ref operator[](int n) const {
            return *(*this + n);
        }

        bool operator==(const _deque_iterator& x) const {
            return cur == x.cur;
        }
        bool operator!=(const _deque_iterator& x) const {
            return !(*this == x);
        }
        bool operator<(const _deque_iterator& x) {
            return (node == x.node) ? cur < x.cur : (node < x.node);
        }

        void set_node(map_node new_node) {
            node = new_node;
            first = *new_node;
            last = first + default_buffer_size;
            cur = first;
        }

        void restore_node(map_node new_node) {
            int offset = cur - first;
            set_node(new_node);
            cur = first + offset;
        }
    };

 public : 
    
    typedef _deque_iterator iterator;

    map_node map;
    iterator start;
    iterator finish;
    
    int _size;
    int map_size;

    Deque () {
        _size = 0;
        map = new int*[minimum_capacity];
        memset(map, 0, sizeof(int*) * minimum_capacity);

        map[minimum_capacity / 2] = allocate_node();
        start.set_node(map + minimum_capacity / 2);
        finish.set_node(map + minimum_capacity / 2);
        map_size = minimum_capacity;
    }
    
    iterator begin() {
        return start;
    } 

    iterator end() {
        return finish;
    }
    int size() {
        return _size;
    }

    int& operator[](int n) {
        return start[n];
    }

    int& front() {
        return *start;
    } 
    
    int& back() {
        iterator tmp = finish;
        --tmp;

        return *tmp; 
    }

    void push_back(int data) {
        ++_size;
        if (finish.cur + 1 != finish.last) {
            *finish.cur = data;
            ++finish.cur;
        } else {
            push_back_aux(data);
            
        }

    }
    void push_back_aux(int data) {
        reserve_map_at_back();
        *finish.cur = data;
        
        *(finish.node + 1) = allocate_node();
        finish.set_node(finish.node + 1);
        finish.cur = finish.first;
    }

    void push_front(int data) {
        ++_size;
        if (start.cur != start.first) {
            --start.cur;
            *start.cur = data;
        } else {
            push_front_aux(data);
        }
    }

    void push_front_aux(int data) {
        reserve_map_at_front();
        
        *(start.node - 1) = allocate_node();
        start.set_node(start.node - 1);
        start.cur = start.last - 1;
        *start.cur = data;
    }

    int * allocate_node() {
        int * retArr = new int[default_buffer_size];
        memset(retArr, 0, default_buffer_size * sizeof(int));
        return retArr;
    }


    void reserve_map_at_back() {
        if (finish.node == map + map_size - 1) {
            map_node new_map = new ptr[map_size + 1];
            
            memcpy(new_map, map, map_size * sizeof(int*));
            new_map[map_size] = 0;

            start.restore_node(new_map + (start.node - map));
            finish.restore_node(new_map + (finish.node - map));
            
            delete [] map;
            
            map = new_map;
            map_size++;
        }
    }
    void reserve_map_at_front() {
        if (start.node == map) {
            map_node new_map = new ptr[map_size + 1];
            memcpy(new_map + 1, map, map_size * sizeof(int*));
            new_map[0] = 0;
   

            start.restore_node(new_map + 1 + (start.node - map));
            finish.restore_node(new_map + 1 + (finish.node - map));
            
            delete [] map;
            
            map = new_map;
            map_size++;
        }
    }

    ~Deque() {

        for (int i = 0; i < map_size; ++i) 
        if (map[i] != NULL) {
             delete [] map[i];
        }
        delete [] map;
    }

};



// simple test

void walk_forward(Deque & deq) {
    int cnt = 0;
    for (Deque::iterator it = deq.begin(); it != deq.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
}
void walk_backward(Deque & deq) {
    for (int i = deq.size() - 1; i >= 0; --i) {
        printf("%d ", deq[i]);
    }

    printf("\n");
}

void test0(int tot) {
    Deque deq;
    
    for (int i = 0; i < tot; ++i) {
        deq.push_back(i);
       // printf("%d\n", i);
    }
    
    walk_forward(deq);
  
    walk_backward(deq);
    
    
    for (int i = 0; i < tot; ++i) {
        deq.push_front(i);
       // printf("%d\n", i);
    }
  
    walk_forward(deq);
    walk_backward(deq);
    printf("size = %d\n", deq.size());
    
}

int main() {
    //test0(7);
   // test0(8);
   // test0(18);
   // test0(17);

//    test0(5000);
//    test0(1024); 
//    test0(1025);
//    test0(5000);
//    test0(50000);
//    test0(500000);

     

    return 0;
}
