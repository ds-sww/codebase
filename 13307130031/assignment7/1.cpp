# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <iostream>
# include <vector>
using namespace std;
# define INF 0x7FFFFFFF
# define REP(i,n) for(int i=0;i<n;i++)
# define REP1(i,n) for(int i=1;i<=n;i++)
# define CLR(a,b) memset(a,b,sizeof(a))

int a[10000];
void process(){
	int n,m;scanf("%d %d",&m,&n);
	REP(i,n){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		cnt+=a[i];
		if(cnt>=m){
			printf("%d\n",n-i);
			return;
		}
	}
	printf("impossible\n");

}

int main(){
	int c;cin>>c;
	REP1(i,c){
		printf("Scenario #%d:\n",i);
		process();
		printf("\n");
	}
	return 0;
}
