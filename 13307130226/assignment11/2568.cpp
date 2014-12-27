//2568
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

vector<string>cont;
vector<int>times;
vector<int>order;
//priority_queue<int,vector<int>,greater<int> >pri;
stringstream SS;
#define MASK 0xfff
#define SHIFT 12

int find_small(int n){
	int i,sm;
	for(i=1;i<=n;i++)
		if(times[i]!=-1)
			break;
	sm = i;
	for(;i<=n;++i)
		if(times[i]!=-1&&times[i]<times[sm])
			sm = i;
	return sm;

}
int main(){
	string a;
	int n;
	int i,j,g,h;
	while(getline(cin,a)){
	if(a==""){
		cout << "(1)" << endl;
		continue;
	}
	n = 0;
	for(int i=0;i<a.size();++i)
		if(a[i]==' ')++n;
	n+=2;
	times.resize(n+1);
	cont.resize(n+1);
	for(int i=0;i<=n;++i){
		string tmp;
		times[i]=1;
		SS.clear();
		SS << i;
		SS >> tmp;
		//cout << "tmp" << tmp;
		cont[i]=tmp;
	}
	SS.clear();
	order.resize(n);
	SS << a;
	for(int i=0;i<n-2;++i){
			int j;
			SS >> j;
			order[i]=j;
			++times[j];		
	}
	SS >> j;
	order[n-2]=j;
	for(int i=0;i<n-1;i++){
		int j;
		j=find_small(n);
		times[j]=-1;
		cont[order[i]]=cont[order[i]]+" ("+cont[j]+")";
		--times[order[i]];
	}
	cout << "("<< cont[order[n-2]] <<")"<< endl;
	}
	return 0;
}