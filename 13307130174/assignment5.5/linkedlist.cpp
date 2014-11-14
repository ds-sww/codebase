//
//  linkedlist.cpp
//  linkedlist deque
//
//  Created by irmo on 14/10/30.
//  Copyright (c) 2014年 apple. All rights reserved.
//

#include <iostream>

using namespace std;

class Linkedlist {
    struct list_node {
        int value;
        list_node *prev;
        list_node *next;
        list_node() { }
        list_node(int _value, list_node *_prev, list_node *_next) {
            value = _value;
            prev = _prev;
            next = _next;
        }
    };
private:
    int count = 0;
    list_node *head;
    list_node *tail;
    
public:
    Linkedlist () {
        head = new list_node;
        head->prev = NULL;
        head->next = NULL;
        tail = head;
    }
    bool isempty () {
        return count == 0;
    }
    void showlist () {
        list_node *p = head;
        if (isempty()) {
            cout << "The list is empty!" << endl;
            return;
        }
        while ((p = p->next)) {
            cout << p->value << " ";
        }
        cout << endl;
        cout << "The head of the list is " << head->next->value << endl;
        cout << "The tail of the list is " << tail->value << endl;
        cout << endl;
    }
    void push_front (int data) {
        list_node *node = new list_node(data, head, head->next);
        if (count) head->next->prev = node;
        if (!count) tail = node;
        head->next = node;
        ++count;
    }
    void push_back (int data) {
        list_node *node = new list_node(data,tail,NULL);
        tail->next = node;
        tail = tail->next;
        ++count;
    }
    void pop_front () {
        if (isempty()) {
            cout << "The list is empty!" << endl;
            return;
        }
        list_node *p = head->next;
        if (p->next) p->next->prev = head;
        head->next = p->next;
        delete p;
        --count;
    }
    void pop_back () {
        if (isempty()) {
            cout << "The list is empty!" << endl;
            return;
        }
        list_node *p = tail;
        tail = tail ->prev;
        p->prev->next = NULL;
        delete p;
        --count;
    }
    int front () {
        if (isempty()) {
            cout << "The list is empty!" << endl;
            return 0;
        }
        return head->next->value;
    }
    int back () {
        if (isempty()) {
            cout << "The list is empty!" << endl;
            return 0;
        }
        return tail->value;
    }
    
    ~Linkedlist() {
        list_node *p = head;
        list_node *temp;
        while (p) {
            temp = p;
            p = p->next;
            delete temp;
        }
    }
    
};
int main(int argc, const char * argv[]) {
    Linkedlist list;
    
    for (int i = 0; i < 5; ++i)  list.push_back(i);
    list.showlist();
    for (int i = 0; i < 5; ++i) list.push_front(i);
    list.showlist();
    for (int i = 0; i < 5; ++i) list.pop_front();
    list.showlist();
    for (int i = 0; i < 5; ++i) list.pop_back();
    list.showlist();

    return 0;
}
