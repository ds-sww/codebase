#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

struct node{
	int father,indegree;
	int n;
	int a[400];
}nodes[400];

int maxi,k,a[400];
int order[400],sum;
bool flag[400];
string s,num;

void dfs(int x){
	printf("(%d",x);
	for(int i=0;i<nodes[x].n;i++){
		printf(" ");
		dfs(nodes[x].a[i]);
	}
	printf(")");
}

int main(){
	while(getline(cin,s))
	if(s=="") printf("(1)\n");
	else{
		maxi=sum=0;
		memset(a,0,sizeof(a));
		memset(nodes,0,sizeof(nodes));
		memset(flag,true,sizeof(flag));
		for(int i=0;i<s.length();i++)
		if(s[i]>='0'&&s[i]<='9'&&flag[i]){
		num="";
		int j=i;
		while(s[j]>='0'&&s[j]<='9'){
			flag[j]=false;
			num+=s[j++];
		}
		k=0;
		for(int j=num.length()-1;j>=0;j--){
			k+=(int)pow(10.0,(double)num.length()-1-j)*(num[j]-'0');
		}
		a[k]++;
		order[sum++]=k;
		if(maxi<k) maxi=k;
		}

		memset(flag,true,sizeof(flag));
		for(int i=0;i<sum;i++){
			for(int j=1;j<=maxi;j++)
				if(a[j]==0&&flag[j]){
					k=j;
					flag[j]=false;
					break;
				}
			nodes[k].father=order[i];
            		nodes[k].indegree++;
            		a[order[i]]--;
            		nodes[order[i]].a[nodes[order[i]].n++]=k;
        	}
		for(int i=1;i<=maxi;i++)
			if(nodes[i].indegree==0)
		k=i;
		dfs(k);
		printf("\n");
	}
	return 0;
}
