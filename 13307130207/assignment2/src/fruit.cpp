#include <iostream>
#include <queue>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int x,n,ans,tmp;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	cin>>n;
	rep(i,1,n){
		cin>>x;
		q.push(x);
	}
	rep(i,1,n-1){
		tmp=q.top(); q.pop();
		tmp+=q.top(); q.pop();
		q.push(tmp);
		ans+=tmp;
	}
	cout<<ans<<endl;
}