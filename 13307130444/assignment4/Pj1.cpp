#include<iostream>
#include<stack>
#define MAX 1000
#using namespace std;

int isPossible(int num){// for one block
	int n=mun,i;
	queue temp;
	stack ra,rb,dend;
	//restore later
	while(1){
		while(n--){
		cin>>i;
		if(i==0)return 0;
		cin>i;
		temp.enqueue(i);
	}
		while(!(ra.empty()&&dend.empty())){
			if(!ra.empty()&&temp.front()>=ra.front()){
			while(temp.front()>=ra.front())
			{
				dend.push(ra.front());
				ra.pop();
			}
			rb.push(dend.front());
			dend.pop();
			temp.dequeue();
			continue;
			}
			 if(!dend.empty()&&temp.front()==dend.front())
			{
				rb.push(dend.front());
				dend.pop();
				temp.dequeue();
				continue;
			}
			if(ra.empty()&&dend.empty())cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
			temp.clear();
			break;
			}
		if(ra.empty()&&dend.empty())cout<<"Yes"<<endl;
		n=num;
	}
cout<<endl;return 0;
}

int main(){
	int i;
	while(cin>>i)
	{
		if (i==0)break;
		isPossible(i);
		cin>>i;
		}
	return 0;
}





