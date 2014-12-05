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

int a[100010],b[100010];
int n,m;

void Qsort(int *a,int l,int r){
	int t=a[(l+r)>>1],i=l,j=r;
	while(i<j){
		while(a[i]<t)	i++;
		while(t<a[j])	j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++,j--;
		}
	}
	if(i<r)	Qsort(a,i,r);
	if(j>l)	Qsort(a,l,j);
}

int t;
void process(){
	for(int i=1;i<=n;i++)	scanf("%d",a+i);
	for(int i=1;i<=m;i++)	scanf("%d",b+i);
	if(n>m){
		printf("Loowater is doomed!\n");
	}else{
		Qsort(a,1,n);
		Qsort(b,1,m);
		int p=1,tot=0;
		for(int i=1;i<=n;i++){
			while(p<=m&&b[p]<a[i])	p++;
			if(p>m){
				printf("Loowater is doomed!\n");
				return;
			}
			tot+=b[p++];
		}
		printf("%d\n",tot);
	}
}

int main(){
	while(scanf("%d %d",&n,&m)&&(n||m)){
		process();
	}
	return 0;
}
