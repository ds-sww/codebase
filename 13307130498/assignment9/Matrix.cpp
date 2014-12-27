#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long i,j,l,r,mid,re,n,t,cnt,jr,m;
bool judge(){
	for(j=1,jr=0;j<=n;j++){
		i=(int)((sqrt(-3*j*j+600000*j+10000000000+4*mid)-j-100000)/2);
		if(i<0)continue;
		if(i>n)i=n;
		jr+=i;
	}
	return jr>=m;
}
int main(void){
	scanf("%lld",&t);
	for(cnt=0;cnt<t;cnt++){
		scanf("%d %lld",&n,&m);
		re=0;
		l=-10000000000;
		r=10000000000;
		while(l<=r){
			mid=(l+r)/2;
			if(judge()==1){
				re=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		printf("%lld\n",re);
	}
	return 0;
}

