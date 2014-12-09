#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,l[20010],s;
long long re;

int main(void){
	scanf("%d %d",&n,&s);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&l[i]);
	sort(l,l+n);
	int j;
	for(i=re=0,j=n-1;;i++){
		while(l[i]+l[j]>s)j--;
		if(i>=j)break;
		re+=j-i;
	}
	cout<<re<<endl;
	return 0;
}

