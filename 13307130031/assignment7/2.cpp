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

string s[20000],a[4][20000];
int f[300];
int n,m,i,j,k,x,d[4],sum[20000];

void process(){
	for(i=0;i<n;i++) cin>>s[i];
	for(i=0;i<m;i++){
		for(j=0;j<4;j++) d[j]=0;
		for(j=0;j<n;j++){
			x=f[s[j][i]];
			a[x][d[x]++]=s[j];
		}
		x=0;
	for(j=0;j<4;j++)
		for(k=0;k<d[j];k++)
			s[x++]=a[j][k];
	}
	for(i=0;i<n;i++) sum[i]=0;
	i=0;
	while(i<n){
		j=i;k=0;
		while((j<n)&&(s[i]==s[j])){
			j++;k++;
		}
		sum[k-1]++;
		i=j;
	}
	for(i=0;i<n;i++)	cout<<sum[i]<<endl;
}

int main(){
	memset(f,-1,sizeof(f));f['A']=0;f['C']=1;f['G']=2;f['T']=3;
	while((~scanf("%d %d",&n,&m))&&(n||m)){
		process();
	}
	return 0;
}

