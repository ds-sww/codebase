/**
 * @author whimsycwd
 * @date   2014.10.26
 * LinkedList deque
 */

#include<iostream>
#include<cstdio>
#include<cassert>

using namespace std;

class LinkedList {
    struct ListNode {
        int data = 0;
        ListNode * prev = NULL;
        ListNode * next = NULL;
        ListNode() {} 
        ListNode(int _data, ListNode * _prev, ListNode * _next) :
            data(_data), prev(_prev), next(_next) {
            }
    };

    private :
        
        ListNode * head; 
        ListNode * tail;
        int cnt;

        void insert(ListNode* & node) {
            node->prev->next = node;
            node->next->prev = node;
        }
        void del(ListNode* & node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

    public :
        LinkedList() {
            head = new ListNode();    // sentinel
            head->prev = head;
            head->next = head;
            tail = head;
            cnt = 0;
        }
        bool isEmpty() {
            return cnt == 0;
        }
        int size() {
            return cnt;
        }

        void push_back(int x) {
            ListNode * node = new ListNode(x, tail->prev, tail);
            insert(node);
            ++cnt;
        }
        void push_front(int x) {
            ListNode * node = new ListNode(x, head, head->next);
            insert(node);
            ++cnt;
        } 
       
        int back() {
            return tail->prev->data; 
        }
        int front() {
            return head->next->data;
        }

        void pop_back() {
            assert(cnt > 0);
            ListNode * node = tail->prev;
            del(node);
            delete node;
            --cnt;
        }
        void pop_front() {
            assert(cnt > 0);
            ListNode * node = head->next;
            del(node);
            delete node;
            --cnt;
        }

        ~LinkedList() {
            delete head;
        }

        // === for debug === 

        void walk() {
            for (auto ptr = head->next; ptr != tail; ptr = ptr->next) {
                cout << ptr->data << " "; 
            }
            cout << endl;
        }
};

// simply test
int main() {
    LinkedList list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    } 
    list.walk();
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    list.walk();

    for (int i = 0; i< 5; ++i) {
        list.pop_front();
    }
    list.walk();

    for (int i = 0; i < 5; ++i) {
        list.pop_back();
    }
    list.walk();

    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    } 
    list.walk();
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    list.walk();

    for (int i = 0; i< 5; ++i) {
        list.pop_front();
    }
    list.walk();

    for (int i = 0; i < 5; ++i) {
        list.pop_back();
    }
    list.walk();

    return 0;
}
