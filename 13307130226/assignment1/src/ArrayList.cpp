
/**
 * @author qzane
 * @date   2014.9.28
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList: public List<T> {
	T *list;
	int self_size,total_size;
public:
	ArrayList(){
		self_size = 0;
		total_size = 16;
		list = new T[16];
	}
	~ArrayList(){
		delete list;
	}
	
	int size() const {
		return self_size;
	}
	bool isEmpty() const {
		if(self_size == 0)
			return true;
		else
			return false;
	}
	T get(int index) const {
		//需要写边界检查吗...如果超出了要返回什么啊...
		return list[index];
	}
	void checkSize(){
		if(total_size <= self_size + 1){
			total_size <<= 1;
		}else if(total_size > self_size*5){
			total_size >>= 1;
			if(total_size == 0)
				total_size = 1;
		}else{
			return;
		}
		T *tmp = new T[total_size];
		for(int i=0;i<self_size;i++)
			tmp[i] = list[i];
		delete list;
		list = tmp;
	}
	void add(const T& element){
		checkSize();
		list[self_size] = element;
		++self_size;
		
	}
	T remove(int index){
		int re = get(index);
		for(int i=index+1;i<self_size;i++)
			list[i-1] = list[i];
		--self_size;
		checkSize();
		return re;
	}
};
/*
int main(){
	ArrayList<int> q;
	for(int i=0;i<10;i++)
		q.add(10-i);
	cout << "begin:" << endl;
	for(int i=0;i<q.size();i++)
		cout << i << ' ' << q.get(i) << endl;
	cout << "over" << endl;
	q.remove(0);
	q.remove(2);
	
	cout << "begin:" << endl;
	for(int i=0;i<q.size();i++)
		cout << i << ' ' << q.get(i) << endl;
	cout << "over" << endl;
	return 0;
	
}*/