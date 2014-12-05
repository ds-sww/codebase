# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <iostream>
# include <vector>
# include <deque>
using namespace std;
# define INF 0x7FFFFFFF
# define REP(i,n) for(int i=0;i<n;i++)
# define REP1(i,n) for(int i=1;i<=n;i++)
# define CLR(a,b) memset(a,b,sizeof(a))

int n;
int a[100000];
deque<int> q;
void process(){
	scanf("%d",&n);
	REP1(i,n)	scanf("%d",a+i);
	long long ans=0;
	for(int i=1;i<=n;i++){
		while(!q.empty()&&q.front()<=a[i]){
				q.pop_front();
		}
		ans+=q.size();
		q.push_front(a[i]);
	}
	cout<<ans<<endl;
}
int main(){
	process();
	return 0;
}
