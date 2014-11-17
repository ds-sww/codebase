#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s1[27],s2[27];
int m,len;
long long result;
int comb(int r){
	int re=1;
	for(int i=0;i<r;i++)
		re=re*(m-i)/(i+1);
	return re;
}
void cal(int l1,int r1,int l2,int r2){
	int k,num=0,i=l1+1,j=l2;
	while(i<=r1){
		for(k=j;s2[k]!=s1[i];k++);
		num++;
		cal(i,i+k-j,j,k);
		i=i+k-j+1;
		j=k+1;
	}
	result*=comb(num);
}
int main(void){
	while(1){
		cin>>m;
		if(m==0)break;
		scanf(" %s %s",&s1,&s2);
		len=strlen(s1);
		result=1;
		cal(0,len-1,0,len-1);
		cout<<result<<endl;
	}
	return 0;
}
