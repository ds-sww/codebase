/**
 * @author whimsycwd
 * @date   2014.10.26
 * LinkedList deque
 *
 * @update
 * @date   2014.11.1
 * add MergeSort, Not recursive way.
 */

#include<iostream>
#include<cstdio>
#include<cassert>
#include<algorithm>

#include "Sortable.h"

using namespace std;

class LinkedList : public Sortable {
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
            ++cnt;
        }
        void del(ListNode* & node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            --cnt;
        }

        // merge sort start
        ListNode * advance(ListNode * cur, int steps) {
            for (int i = 0; i<steps; ++i) {
                cur = cur->next;
                if (cur == head) 
                    return head;
            }
            return cur;
        }
        void connectAndAdvance(ListNode *& outer, ListNode * &cur, int &cnt) {
            outer->next = cur;
            cur->prev = outer;
            outer = outer->next;
            cur = cur->next;
            ++cnt;
        }

        void merge(ListNode * left, int lenLeft, 
                ListNode * right, int lenRight) {
          
            int lp = 0;
            int rp = 0;
            ListNode * outerLeft = left->prev;
            ListNode * outerRight = advance(right, lenRight);

            for (int i = 0; i < lenLeft + lenRight; ++i) {
                if (lp == lenLeft) {
                    connectAndAdvance(outerLeft, right, rp);
                } else {
                    if (rp == lenRight) {
                        connectAndAdvance(outerLeft, left, lp);
                    } else {
                        if (left->data < right->data) {
                            connectAndAdvance(outerLeft, left, lp);
                        } else {
                            connectAndAdvance(outerLeft, right, rp);
                        }                        
                    }
                }
            }


            // repair connection
            outerLeft->next = outerRight;
            outerRight->prev = outerLeft;
        }
        
        void mergeSort() {
            int len = 1;
            while (len < cnt) {
                int curLen = 0;
                
                ListNode * left = head->next;
                ListNode * right = advance(left, len);

                while (curLen < cnt) { 

                    ListNode * nextLeft = advance(left, len * 2);
                    ListNode * nextRight = advance(right, len * 2);

                    int lenLeft  = min(len, (cnt - curLen < 0) ? 0 : (cnt - curLen));
                    int lenRight = min(len, (cnt - curLen - len < 0) ? 0 : (cnt - curLen - len));

                    merge(left, lenLeft, right, lenRight);

                    left = nextLeft;
                    right = nextRight;

                    curLen += len * 2;
                }

                //walk();

                len *= 2;
            }          
        }

        // mergesort end.

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
        }
        void push_front(int x) {
            ListNode * node = new ListNode(x, head, head->next);
            insert(node);
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
        }
        void pop_front() {
            assert(cnt > 0);
            ListNode * node = head->next;
            del(node);
        }
        

        // Assume all element in LinkedList is inserted by method `sort`.
        // in order to fit in the test.
        virtual void sort(vector<int> &data) {
            for (int i = 0; i < data.size(); ++i) {
                push_back(data[i]);
            }

            mergeSort();

            for (int i = 0; i< data.size(); ++i) {
                data[i] = front();
                pop_front();
            }
            
        }

        ~LinkedList() {
            while (cnt > 0) pop_front();
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

