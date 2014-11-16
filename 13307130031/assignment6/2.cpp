# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
# define INF 0x7FFFFFFF
# define REP(i,n) for(int i=0;i<n;i++)
# define REP1(i,n) for(int i=1;i<=n;i++)
# define CLR(a,b) memset(a,b,sizeof(a))
struct px{
	int v,p;
	void scan(){
		scanf("%d",&v);
		if(v<0)	p=-v;
		else	p=v;
	}

} a[100010];int n;

void Qsort(int l,int r){
	int t=a[(l+r)>>1].p,i=l,j=r;
	while(i<j){
		while(a[i].p<t)	i++;
		while(t<a[j].p)	j--;
		if(i<=j){
			swap(a[i].v,a[j].v);
			swap(a[i].p,a[j].p);
			i++,j--;
		}
	}
	if(i<r)	Qsort(i,r);
	if(j>l)	Qsort(l,j);
}

int t;
void process(){
	scanf("%d %d",&t,&n);
	for(int i=1;i<=n;i++){
		a[i].scan();
	}
	Qsort(1,n);
	int cnt=0,tot=0;
	for(int i=1;i<=n;i++){
		//printf("%d %d\n",a[i].v,a[i].p);
		int val;
		if((long long)a[i].v*a[i-1].v<0){
			val=a[i].p+a[i-1].p;
		}else{
			val=a[i].p-a[i-1].p;
		}
		if(val+tot>t)	break;
		tot+=val;
		cnt++;
	}
	printf("%d\n",cnt);
}

int main(){
	process();
	return 0;
}
