#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int N,K;
int set[55000];
int rank[55000];
int ans;
void getset(int a){
	
	//cout << "b " << a << ' ' << set[a] << ' ' <<rank[a] << endl;
	if(set[a]==a)return;
	getset(set[a]);
	rank[a]=(rank[a]+rank[set[a]])%3;
	set[a]=set[set[a]];
	//cout << "r " << a << ' ' << set[a] << ' ' <<rank[a] << endl;
}
int main(){
	cin >> N >> K;
	ans = 0;
	for(int i=0;i<=N;++i){
		set[i]=i;
		rank[i]=0;
	}
	for(int i=0;i<K;++i){
		int d,x,y;
		cin >> d >> x >> y;
		if(x>N||y>N){
		++ans;
		//cout << "lie" << endl;
		continue;}
		getset(x);getset(y);
		if(d==1){
			if(set[x]==set[y]&&(-rank[x]+rank[y]+3)%3!=0)
				{++ans;
				//cout << "lie" << endl;
				}
			if(set[x]!=set[y]){
				rank[set[y]]=3+rank[x]-rank[y];
				set[set[y]]=set[x];
			}
		}else if(d==2){
			if(set[x]==set[y]&&(rank[x]-rank[y]+3)%3!=1)
				{++ans;
				//cout << "lie" << endl;
				}
			if(set[x]!=set[y]){
				rank[set[x]]=3-rank[x]+rank[y]+1;
				set[set[x]]=set[y];
			}
		}/*
		for(int i=0;i<9;++i){
			cout << 'r' << i << set[i] << rank[i]%3 << endl;
		}	*/
	}
	
	cout << ans << endl;
}