
/**
 * @author aixile 
 * @date   2014.9.26
 * ArrayList
 */
#include <iostream>
#include <cassert>
#include "List.h"
# include <cstdio>

using namespace std;

template <typename T>
class ArrayList : public List<T> {
	int cnt,arrcnt;
	T* arr[32];

	int getBinLength(int index) const{
		int len=0;
		for(;index;index>>=1,len++);
		return len;
	}

	void add(const T& element,int& arrcnt,int& cnt,T* arr[],bool newspace){
		cnt++;
		if(cnt==(1<<arrcnt)){
			if(newspace)	arr[arrcnt]=new T[1<<arrcnt];
			arr[arrcnt++][0]=element;
		}else{
			arr[arrcnt-1][cnt-(1<<(arrcnt-1))]=element;
		}
	}

	public:
	ArrayList(){
		cnt=arrcnt=0;
	}

	int size() const{
		return cnt;
	}
	
	bool isEmpty() const{
		return cnt==0;
	}

	void add(const T& element){
		add(element,arrcnt,cnt,arr,true);
	}

	T get(int index) const{
		int len=getBinLength(index+1)-1;
		return arr[len][index-(1<<len)+1];
	}

	T remove(int index){
		T* newarr[32];
		int len=getBinLength(index+1)-1;
		for(int i=len;i<arrcnt;i++){
			newarr[i]=new T[1<<i]; 
		}
		int newcnt=(1<<len)-1,newarrcnt=len;
		for(int i=newcnt+1;i<=cnt;i++)	if(index+1!=i){
			add(get(i-1),newarrcnt,newcnt,newarr,false);
		}
		for(int i=len;i<arrcnt;i++){
			delete arr[i];
			arr[i]=newarr[i];
		}
		cnt=newcnt;
		arrcnt=newarrcnt;
		if(((cnt+1)&cnt)==0)	delete arr[arrcnt]; 
	}
};


