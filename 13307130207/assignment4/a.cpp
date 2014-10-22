#include <cstdio>
#include <iostream>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int n,top,p,flag,a[10000],q[10000];
int main(){
	while (1){
		scanf("%d",&n);
		if (!n) break;
		while (1){
			scanf("%d",&a[1]);
			if (!a[1]) break;
			rep(i,2,n) scanf("%d",&a[i]);
			top=0; p=0; flag=1;
			rep(i,1,n){
				while (p<n && q[top]!=a[i]) q[++top]=++p;
				if (q[top]==a[i]) {top--; continue;}
				flag=0;
			}
			if (flag) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
}