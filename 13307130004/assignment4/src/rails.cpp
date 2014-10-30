#include <iostream>
#define N 1010
using namespace std;

class rail{
private:
	int *a;
	int top,maxtop;
public:
	rail(const int max){
		maxtop=max;
		a=new int[maxtop];
		top=-1;
	};
	void push(const int i){
		if(top<maxtop){
			top++;
			a[top]=i;
		}
	};
	void pop(){
		if(top!=-1){
			top--;
		}
	};
	int gettop(){
		if(top!=-1)
			return a[top];
		else return 0;
	};
	void isempty(){
		if(top==-1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		delete []a;
		top=-1;
	};
};
int main(){
	int i,j,n,b[N];
	cin>>n;
	while(n){
		while(1){
			cin>>b[0];
			if(!b[0])
				break;
			rail ra(n);
			for(i=1;i<n;i++)
				cin>>b[i];
			for(i=1,j=0;i<=n;i++){
				ra.push(i);
				while(ra.gettop()==b[j]){
					ra.pop();
					j++;
				}
			}
			ra.isempty();
		}
		cout<<endl;
		cin>>n;
	}
	return 0;
}