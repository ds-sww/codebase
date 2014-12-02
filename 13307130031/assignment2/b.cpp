# include <cstdio>
# include <queue>
# include <vector>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;

int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;scanf("%d",&a);
		q.push(a);
	}
	while(q.size()!=1){
		int a=q.top();q.pop();
		int b=q.top();q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	printf("%d\n",ans);
	return 0;
}
