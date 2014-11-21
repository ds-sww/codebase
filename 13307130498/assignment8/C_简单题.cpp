#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N;

void ct(int n,int m){
	if(m>N)return;
	else{
		cout<<m<<" ";
		ct(n*2,2*m);
		ct(n*2,2*m+1);
	}
}
	
int main(void){
	while(1){
		cin>>N;
		if(N==0)break;
		ct(1,1);
		cout<<endl;
	}
	return 0;
}
