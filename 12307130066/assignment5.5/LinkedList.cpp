#include<iostream>

using namespace std;

struct ListNode {
	int number;
	ListNode* next;
};

class LinkedList {
public:
	LinkedList() {
		head = new ListNode;
		//用head中存储的数字来记录链表长度
		head->number = 0;
		head->next = NULL;
		tail = head->next;
	}
	~LinkedList() {
		if(head->number == 0) {
			delete head;
			return;
		}
		ListNode* curr;
		while(head != NULL) {
			curr = head;
			head = head->next;
			delete curr;
		}
	}
	void push_back(int a) {
		if(head->number == 0) {
			head->next = new ListNode;
			head->next->number = a;
			head->next->next = NULL;
			tail = head->next;
			head->number++;
		} else {
			tail->next = new ListNode;
			tail->next->number = a;
			tail->next->next = NULL;
			tail = tail->next;
			head->number++;
		}
	}
	void push_front(int a) {
		ListNode* tmp = new ListNode;
		tmp->number = a;
		tmp->next = head->next;
		head->next = tmp;
		head->number++;
	}
	void pop_front() {
		ListNode* tmp = head->next;
		head->next = head->next->next;
		delete tmp;
		head->number--;
	}
	void pop_back() {
		ListNode* tmp = head;
		while(tmp->next != tail)
			tmp = tmp->next;
		tail = tmp;
		delete tmp->next;
		head->number--;
	}
	void walk() {
		if(head->number != 0) {
			ListNode* curr = head->next;
			while(curr != NULL) {
				cout << curr->number << " ";
				curr = curr->next;
			}
		}
		cout << endl;
	}
private:
	ListNode* head;
	ListNode* tail;
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