//2503
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
#define MAXN 100100 

map<string,string>ma;
string q,w,e;
int pos;
int main(){
	ma.clear();
	while(getline(cin,e)){
		if(e=="")break;
		pos = e.find(' ');
		q=e.substr(0,pos);
		w=e.substr(pos+1,e.size()-pos-1);
		ma[w]=q;
		//cout << "x"<<q <<"x"<<w<<endl;
	}
	while(getline(cin,q)){
		if(q=="")break;
		if(ma.count(q)==0)
			cout << "eh" << endl;
		else
			cout << ma[q] << endl;
	}
	return 0;
}