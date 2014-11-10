#include<iostream>

using namespace std;

class stack{
	int ele;
	stack* next;
public:
	stack(){next=NULL;};
	stack(int x){ele=x;next=NULL;}
	~stack(){}
	bool isempty(){
		if(next==NULL)return 1;
		else return 0;
	}
	void pop(){
		stack *p;
		p=next;
		next=next->next;
		delete p;
	}
	void push(int x){
		stack *p;
		p=new stack(x);
		p->next=next;
		next=p;
	}
	int tell(){
		return next->ele;
	}
};

int main(){
	while(1){
		int N;
		cin>>N;
		if(N==0)break;
		int i,j,*coach;
		stack head;
		coach=new int [N];
		for(i=0;i<N;i++){
			coach[i]=i+1;
		}
		int t,*ask;
		ask =new int [N];
		cin>>t;
		while(t!=0){
			ask[0]=t;
			for(i=1;i<N;i++)
				cin>>ask[i];
			for(j=i=0;i<N;i++){
				head.push(coach[i]);
				while(1){
					if(head.isempty())break;
					else{
						if(ask[j]==head.tell()){
							head.pop();
							j++;
						}
						else break;
					}
				}
			}
			if(j==N)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
			cin>>t;
		}
		cout<<endl;
	}

	return 0;
}
