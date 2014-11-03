# include <cstdio>
using namespace std;

#define N 1000100
int a[N],que1[N],que2[N],ans1[N],ans2[N];

int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=-1){
		for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
		int h1=0,t1=-1;
		int h2=0,t2=-1,cnt=0;
		for(int i=1;i<=n;i++){
			while(h1<=t1&&a[i]<=a[que1[t1]])	t1--;
			que1[++t1]=i;
			while(que1[h1]<i-k+1)	h1++;
			while(h2<=t2&&a[i]>=a[que2[t2]])	t2--;
			que2[++t2]=i;
			while(que2[h2]<i-k+1)	h2++;
			if(i>=k){
				ans1[++cnt]=a[que1[h1]];
				ans2[cnt]=a[que2[h2]];
			}
		}
		printf("%d",ans1[1]);
		for(int i=2;i<=cnt;i++)	printf(" %d",ans1[i]);
		printf("\n%d",ans2[1]);
		for(int i=2;i<=cnt;i++)
			printf(" %d",ans2[i]);
		printf("\n");
	}
	return 0;
}

