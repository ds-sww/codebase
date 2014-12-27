#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string>input;
int ans,n;
long long chars[300],map[300];
long long occo[11];
int charn;
string tmp;


void check(){
	int sum=0;
	int tmp=0;
	for(int i=0;i<n;++i){
		if(map[input[i][0]]==0&&input[i].size()!=1)
			return;
		tmp = 0;
		for(int j=0;j<input[i].size();++j){
			tmp = tmp*10 + map[input[i][j]];
		}
		if(i==n-1)
			sum-=tmp;
		else
			sum+=tmp;
	}
	if(sum==0)++ans;
}

void dfs(int n=0){
	if(n==charn)
		check();
	else{
		for(int i=0;i<10;++i)
			if(occo[i]==-1){
				occo[i]=n;
				map[chars[n]]=i;
				dfs(n+1);
				occo[i]=-1;
			}
	}
}
int main(){
	cin >> n;
	input.clear();
	for(int i=0;i<n;++i){
		cin >> tmp;
		input.push_back(tmp);
	}
	ans = 0;
	for(int i=0;i<300;++i)
		map[i]=-1;
	charn = 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<input[i].size();++j)
			if(map[input[i][j]]==-1){
				chars[charn++]=input[i][j];
				map[input[i][j]]=1;
			}
	/*
	for(int i=0;i<charn;++i)
		cout << chars[i] << ' ';
	cout << endl << charn << endl ;
	*/
	for(int i=0;i<11;++i)
		occo[i]=-1;
	dfs(0);
	cout << ans << endl;
	


return 0;
}
