#include <iostream>
#include <cstdio>
#define N 1001000
using namespace std;

class stack{
private:
	int*h;
	int *n;
	int size;
	int top;
public:
	stack(){
		size=1;
		h=new int;
		n=new int;
		top=-1;
	};
	void changesize(int si){
		delete []h;
		delete []n;
		size=si;
		h=new int[size];
		n=new int[size];
		top=-1;
	};
	void zero(){
		top=-1;
	};
	int push(int i){
		int temp=1;
		if (top==-1){
			top++;
			h[top]=i;
			n[top]=1;
		}
		else if(top<size){
			for(int j=top;j>=0;j--)
			{
				if(h[j]>=i){
					temp+=n[top];
					top--;
				}
				else
					break;
			}
			top++;
			h[top]=i;
			n[top]=temp;
		}
		return n[top];
	};
};
int main(){
	int n;
	long long max;
	int a[N];
	int b[N];
	stack st;
	while(1){
		scanf("%d",&n);
		if(!n) break;
		max=-1;
		st.changesize(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[i]=st.push(a[i]);
		}
		st.zero();
		for(int i=n-1;i>=0;i--){
			b[i]+=st.push(a[i])-1;
			if((long long)b[i]*(long long)a[i]>max)
				max=(long long)(b[i])*(long long)(a[i]);
		}
		cout<<max<<endl;
	}
	return 0;
}
