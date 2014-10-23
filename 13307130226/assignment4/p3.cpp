#include<cstdio>
#include<iostream>
using namespace std;

class stack{
int value[1000100];
int maxx[1000100];
int minn[1000100];
public:
	int size;
	stack(){
		size=0;
	}
	void push(int v){
		value[size]=v;
		if(size>0&&maxx[size-1]>v)
			maxx[size]=maxx[size-1];
		else
			maxx[size]=v;
		if(size>0&&minn[size-1]<v)
			minn[size]=minn[size-1];
		else
			minn[size]=v;
		size++;
	}
	int pop(){
		return value[--size];
	}
	int max(){
		return maxx[size-1];
	}
	int min(){
		return minn[size-1];
	}
};
class queue{
stack st_a,st_b;
public:
	int size;
	queue(){
		size=0;
	}
	void push(int v){
		st_a.push(v);
		size++;
	}
	int pop(){
		size--;
		if(st_b.size>0)
			return st_b.pop();
		while(st_a.size>0)
			st_b.push(st_a.pop());
		return st_b.pop();
	}
	int max(){
		int a,b;
		a = st_a.max();
		b = st_b.max();
		return a>b?a:b;
	}
	int min(){
		int a,b;
		a = st_a.min();
		b = st_b.min();
		return a<b?a:b;
	}


}window;


int value[1000100];
int maxx[1000100];
int main(){
	int n,k,i,j;
	cin >> n;
	cin >> k;
	for(i=0;i<n;i++)
		scanf("%d",&value[i]);
	for(i=0;i<k-1;i++)
		window.push(value[i]);
	for(;i<n;i++){
		window.push(value[i]);
		if(i!=n-1)
		printf("%d ",window.min());
		else
		printf("%d",window.min());
		
		maxx[i-k+1] = window.max();
		window.pop();
	}
	cout << endl;
	for(i=0;i<n-k+1;i++)
		if(i!=n-k)
		printf("%d ",maxx[i]);
		else
		printf("%d",maxx[i]);
	cout << endl;
	
	
}