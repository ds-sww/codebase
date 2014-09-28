
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
		return list[index];
	}
	void add(const T& element){
		if(total_size > self_size){
			list[self_size] = element;
			++self_size;
		}else{
			total_size <<= 1;
			T *tmp = new T[total_size];
			for(int i=0;i<self_size;i++)
				tmp[i] = list[i];
			delete list;
			list = tmp;
			list[self_size] = element;
			++self_size;
		}	
	}
	T remove(int index){
		int re = get(index);
		for(int i=index+1;i<self_size;i++)
			list[i-1] = list[i];
		--self_size;
		if(5*self_size < total_size){
			total_size >>= 1;
			if(total_size == 0)
				total_size = 1;
			T *tmp = new T[total_size];
			for(int i=0;i<self_size;i++)
				tmp[i] = list[i];
			delete list;
			list = tmp;
		}
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