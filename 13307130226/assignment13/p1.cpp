#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

int P,T;
class way{
public:
	int a,w;
	bool operator<(const way& a)const{
		return a.w>w;
	}
}tmp;
vector<vector<way> >ways;

vector<int>dis;
vector<set<int> >from;
class comp{
public:
	bool operator()(int a,int b){
		return dis[a]>dis[b];
	}
};
priority_queue<int,vector<int>,comp>points;
const int shif = 14;
const int mask = 0x3fff;
set<int>occo;
const int MAXD = 80000000;
void dfs(int now){
	//cout << "dfs " << now <<' '<<from[now].size()<< endl; 
	
	for(set<int>::iterator i=from[now].begin();i!=from[now].end();++i){
		//cout << ((*i)&mask) << endl;
		occo.insert(*i);
		if(((*i)&mask)!=0)
			dfs((*i)&mask);
	}
}
int main(){
	cin >> P >> T;
	ways.resize(P);
	dis.resize(P);
	from.resize(P);
	for(int i=0;i<P;++i){
		ways[i].clear();
		dis[i]=MAXD;
		//from[i].clear();
	}
	for(int i=0;i<T;++i){
		int a,b,w;
		cin >> a >> b >> w;
		tmp.a=b;tmp.w=w;
		ways[a].push_back(tmp);
		tmp.a=a;
		ways[b].push_back(tmp);		
	}
	while(!points.empty())points.pop();
	dis[0]=0;
	points.push(0);
	while(!points.empty()){
		int now;
		now = points.top();
		points.pop();
		//cout << now << endl;
		if(dis[now]>dis[P-1])break;
		for(int i=0;i<ways[now].size();++i){
			int b,w;
			b = ways[now][i].a;
			w = ways[now][i].w;
			if(dis[b]==dis[now]+w){
				from[b].insert((i<<shif)+now);
			}else if(dis[b]>dis[now]+w){
				dis[b]=dis[now]+w;
				from[b].clear();
				from[b].insert((i<<shif)+now);
				points.push(b);
			}
		}	
	}
	occo.clear();
	dfs(P-1);
	int ans;
	ans = 0;
	for(set<int>::iterator i=occo.begin();i!=occo.end();++i)
		ans += ways[(*i)&mask][(*i)>>shif].w;
	cout << (ans<<1) << endl;
return 0;
}