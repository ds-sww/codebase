#include <cstdio>
#include <iostream>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;

int n,top,a[200000],q[200000];
ll ans,an[200000];
int main(){
	while (1){
		scanf("%d",&n);
		if (!n) break;
		rep(i,1,n) scanf("%d",&a[i]);
		top=ans=0;
		rep(i,1,n){
			while (top && a[q[top]]>=a[i]) top--;
			an[i]=(ll)a[i]*(i-q[top]);
			q[++top]=i;
		}
		rep(i,1,n/2) swap(a[i],a[n+1-i]);
		top=0;
		rep(i,1,n){
			while (top && a[q[top]]>=a[i]) top--;
			an[n+1-i]=an[n+1-i]+(ll)a[i]*(i-q[top]-1);
			q[++top]=i;
		}
		ans=an[1];
		rep(i,2,n) if (an[i]>ans) ans=an[i];
		cout<<ans<<endl;
	}
}