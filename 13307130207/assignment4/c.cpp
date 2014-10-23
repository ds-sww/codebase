#include <cstdio>
#include <iostream>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define maxN 1000010
using namespace std;
typedef long long ll;

int n,k,l,r,a[maxN],q[maxN];
int main(){
	cin>>n>>k;
	rep(i,1,n) scanf("%d",&a[i]);
	l=1; r=0;
	rep(i,1,k-1){
		while (r>=l && a[q[r]]>=a[i]) r--;
		q[++r]=i;
	}
	rep(i,k,n){
		if (q[l]<=i-k) l++;
		while (r>=l && a[q[r]]>=a[i]) r--;
		q[++r]=i;
		printf("%d",a[q[l]]);
		if (i==n) printf("\n"); else printf(" ");
	}

	l=1; r=0;
	rep(i,1,k-1){
		while (r>=l && a[q[r]]<=a[i]) r--;
		q[++r]=i;
	}
	rep(i,k,n){
		if (q[l]<=i-k) l++;
		while (r>=l && a[q[r]]<=a[i]) r--;
		q[++r]=i;
		printf("%d",a[q[l]]);
		if (i==n) printf("\n"); else printf(" ");
	}
}