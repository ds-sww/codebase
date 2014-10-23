#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int isPossible(int num){// for one block
	int n=num,i;
	queue<int> temp;
	stack<int> ra,dend;
	n=num;
	while(1){
		while(n--)ra.push(n+1);n=num;
		while(n--){
		cin>>i;
		if(i==0)return 0;
		temp.push(i);//cout<<"bj0"<<endl;
		}
		while( !(ra.empty()&&dend.empty())){
			if(!ra.empty()&&(temp.front()>=ra.top())){
			while(!ra.empty()&&temp.front()>=ra.top())
			{//cout<<"bj1"<<endl;
				dend.push(ra.top());
				ra.pop();
			}
			dend.pop();
			temp.pop();
			}
			else if(!dend.empty()&&temp.front()==dend.top())
			{//cout<<"bj2"<<endl;
				dend.pop();
				temp.pop();
			 }
			else {cout<<"No"<<endl;break;}
		
			if(ra.empty()&&dend.empty()){
				cout<<"Yes"<<endl;
				while(!temp.empty()){temp.pop();}
			}
		}
		n=num;
	}
return 0;
}

int main(){
	int i;
	while(cin>>i)
	{   
		if (i==0)break;
		isPossible(i);cout<<endl;
		}
	cout<<endl;
	return 0;
	cin>>i;
	cin>>i;
}
