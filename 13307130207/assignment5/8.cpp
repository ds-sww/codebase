#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define For(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int pri[300],tn,to,stkn[10000],stko[10000];
string s;

int calc(int a,int b,int _){
	if (_=='+') return a+b;
	if (_=='-') return a-b;
	if (_=='*') return a*b;
	if (_=='/') return a/b;
	int tmp=1;
	rep(i,1,b) tmp*=a;
	return tmp;
}

int main(){
	pri['(']=0;
	pri[')']=1;
	pri['+']=pri['-']=2;
	pri['*']=pri['/']=3;
	pri['^']=4;
	while (cin>>s){
		s='('+s+')';
		tn=to=0;
		For(i,0,s.length()) {
			if (isdigit(s[i])) {
				if (!isdigit(s[i-1])) stkn[++tn]=0;
				stkn[tn]=stkn[tn]*10+s[i]-'0';
			} else {
				while (s[i]!='(' && pri[stko[to]]>=pri[s[i]] && !(s[i]=='^' && stko[to]=='^')) {
					stkn[tn-1]=calc(stkn[tn-1],stkn[tn],stko[to]);
					tn--; to--;
				}
				if (s[i]==')') to--;
				else stko[++to]=s[i];
			}
		}
		cout<<stkn[1]<<endl;
	}
}