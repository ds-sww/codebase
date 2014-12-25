#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int N,s,p;
int pointsX[600],pointsY[600];
int sets[600];
int nset;
double ans;
class way{
public:
	double lo;
	int a,b;
	way(){
		lo=0.0;
		a=b=0;
	}
	bool operator<(const way& a)const{
		return a.lo<lo;
	}
};
int getset(int a){
	return sets[a]==a?a:sets[a]=getset(sets[a]);
}

priority_queue<way>ways;
way tmp;
int main(){
cin >> N;
while(N--){
	cin >> s >> p;
	for(int i=0;i<p;++i){
		cin >> pointsX[i] >> pointsY[i];
		sets[i]=i;
	}
	while(!ways.empty())ways.pop();
	for(int i=0;i<p;++i)
		for(int j=i+1;j<p;++j){
			tmp.lo = (pointsX[i]-pointsX[j])*(pointsX[i]-pointsX[j])+(pointsY[i]-pointsY[j])*(pointsY[i]-pointsY[j]);
			tmp.a = i;
			tmp.b = j;
			ways.push(tmp);
		}
	nset=p;
	ans = 0;
	while(!ways.empty()){
		tmp = ways.top();
		//cout << "tmp " << tmp.a << ' ' << tmp.b << ' ' <<tmp.lo <<endl;
		ways.pop();
		if(getset(tmp.a)==getset(tmp.b))continue;
		--nset;
		ans=ans>tmp.lo?ans:tmp.lo;
		sets[sets[tmp.a]]=sets[tmp.b];
		if(nset==s)break;	
	}
	printf("%0.2f",sqrt(ans));
	cout << endl;
}
return 0;
}