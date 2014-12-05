#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char pr[27],in[27];
int len;
void cal(int l1,int r1,int l2,int r2){
	if(l1>r1)return;
	char root=pr[l1];
	int i;
	for(i=l2;in[i]!=root;i++);
	cal(l1+1,l1+i-l2,l2,i-1);
	cal(l1+i-l2+1,r1,i+1,r2);
	cout<<root;
}

int main(void){
	while(scanf("%s %s",&pr,&in)!=EOF){
		len=strlen(pr);
		cal(0,len-1,0,len-1);
		cout<<endl;
	}
	return 0;
}
