#include<iostream>
#include<vector>
#include<algorithm>
#define MAXX 9999999
#define min(x,y) (x)>(y)?(y):(x)
using namespace std;
vector<int>cow;
int N,S,i,j,g,h,ans;
int main(){
	cin >> N >> S;
	cow.resize(N+1);
	for(i=0;i<N;i++)
		cin >> cow[i];	
	cow[N] = MAXX;
	sort(cow.begin(),cow.end());
	ans = 0;
	for(i=N-1,j=0;i>=0;i--){
		for(;j<N && cow[j]+cow[i]<=S;j++);
		ans += min(j,i);
	}
	cout << ans << endl;
}