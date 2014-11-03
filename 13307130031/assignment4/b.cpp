# include <cstdio>
# include <iostream>
using namespace std;

# define N 100010
long long h[N],l[N],r[N];
int n;

int main(){
	while(scanf("%d",&n)!=-1){
		if(n==0)	break;
		for(int i=1;i<=n;i++){
			scanf("%ld",h+i);
		}
		for(int i=1;i<=n;i++){
			l[i]=i;
			while(l[i]>1&&h[l[i]-1]>=h[i])	l[i]=l[l[i]-1];
		}
		for(int i=n;i>=1;i--){
			r[i]=i;
			while(r[i]<n&&h[r[i]+1]>=h[i])	r[i]=r[r[i]+1];
		}
		long long m=0;
		for(int i=1;i<=n;i++){
			long long x;
			if((x=((long long)h[i]*(r[i]-l[i]+1)))>=m)	m=x;
		}
		cout<<m<<endl;
	}
	return 0;
}
