#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;

class node{
public:
	int occur;
	vector<char> cont;
	node(){
		cont.clear();occur=0;
	}
	node(char a){
		cont.resize(1);occur=0;
		cont[0]=a;
	}
	~node(){
		cont.clear();
	}
	void merge(const node& a){
		occur+=a.occur;
		cont.insert(cont.end(),a.cont.begin(),a.cont.end());
	}
}tmp,tmpp;
class cmp{
public:
	bool operator() (const node& a,const node& b){
		if(a.occur<b.occur)return false;
		else return true;
	}
};


string text;
int map[300];
int countt[300];
int length;
priority_queue<node,vector<node>,cmp>pri;
int main(){
while(cin >> text){
	if(text == "END")
		return 0;
	memset(countt,0,sizeof(int)<<8);
	memset(map,0,sizeof(int)<<8);
	while(!pri.empty())pri.pop();
	for(int i=0;i<text.size();i++)
		map[text[i]]++;
	
	tmp.cont.resize(1);
	for(int i=0;i<260;i++)
		if(map[i]!=0){
			tmp.occur=map[i];
			tmp.cont[0]=i;
			pri.push(tmp);
		}
	while(pri.size()>1){
		tmp=pri.top();
		pri.pop();
		tmpp=pri.top();
		pri.pop();
		tmp.merge(tmpp);
		for(int i=0;i<tmp.cont.size();i++){
			countt[tmp.cont[i]]++;
		}
		pri.push(tmp);		
	}
	length=0;
	for(int i=0;i<260;i++)
			length += map[i]*(countt[i]>1?countt[i]:1);
	printf("%d %d %.1f",text.size()<<3,length,((double)(text.size()<<3))/length);
	cout << endl;
}
}