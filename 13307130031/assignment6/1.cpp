# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <iostream>
# include <vector>
using namespace std;
# define INF 0x7FFFFFFF
# define REP(i,n) for(int i=0;i<n;i++)
# define REP1(i,n) for(int i=1;i<=n;i++)
# define CLR(a,b) memset(a,b,sizeof(a))

void qsort(int *a,int l,int r){
	int t=a[(l+r)>>1],i=l,j=r;
	while(i<j){
		while(a[i]<t)	i++;
		while(t<a[j])	j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++,j--;
		}
	}
	if(i<r)	qsort(a,i,r);
	if(j>l)	qsort(a,l,j);
}

int a[100010],n,m;
void process(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d\n",a+i);
	qsort(a,1,n);
	while(getchar()!='\n');
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int x;scanf("%d",&x);
		printf("%d\n",a[x]);
	}
}

int main(){
	process();
	return 0;
}
