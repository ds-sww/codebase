#include <iostream>
#define M 1001000
#define L 3
using namespace std;

class Queue{
private:
	int *q,*index;
	int front,rear,size,counter,decounter;
	int max[M];
public:
	Queue(int maxsize){
		size=maxsize+L;
		q=new int[size];
		index=new int[size];
		front=rear=counter=decounter=0;
	};
	void enqueue(int i){
		int temp;
		rear=(rear+1)%size;
		index[rear]=counter;
		q[rear]=i;
		if(counter!=0){
			temp=rear;
			for(int j=((rear+size-front)%size-1);j>0;j--){
				if(q[(front+j)%size]>i)
					break;
				else
				{
					q[(front+j)%size]=i;
					index[(front+j)%size]=counter;
					temp=(front+j)%size;
				}
			}
			rear=temp;
		}
		counter++;
	};
	void dequeue(){
		if(index[(front+1)%size]==decounter)
			front=(front+1)%size;
		decounter++;
	};
	void add(int i){
		enqueue(i);
		if(counter>size-L)
			dequeue();
		max[counter]=q[(front+1)%size];
	};
	void print1(){
		for(int i=size-L;i<=counter;i++)
			cout<<max[i]<<" ";
		cout<<endl;
	};
	void print2(){
		for(int i=size-L;i<=counter;i++)
			cout<<(-max[i])<<" ";
		cout<<endl;
	};
	void clear(){
		delete []q;
		delete []index;
		q=new int[size];
		index=new int[size];
		front=rear=counter=decounter=0;
	};
};
int main(){
	int arraysize,slidesize,temp;
	int a[M];
	cin>>arraysize>>slidesize;
	Queue que(slidesize);
	for(int i=0;i<arraysize;i++)
	{
		cin>>a[i];
		que.add(-a[i]);
	}
	que.print2();
	que.clear();
	for(int i=0;i<arraysize;i++)
	{
		que.add(a[i]);
	}
	que.print1();
	return 0;
};