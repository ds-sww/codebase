# include <cstdio>
# include <cstring>
using namespace std;

int main(){
	int n,i,j,top,flag;
	int a[1001],stack[1001];
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		scanf("%d",&a[1]);
		while(a[1]!=0){
			for(i=2;i<=n;++i)	scanf("%d",&a[i]);
			top=0;j=i=1;stack[0]=-1;flag=1;
			while(flag&&i<=n){
				if(a[i]==j){
					i++;j++;continue;
				}
				if(a[i]==stack[top]){
					i++;top--;continue;
				}
				if(j<=n){
					top++;stack[top]=j;j++;
				}else if (stack[top]!=a[i])	flag=0;
				
			}
			printf("%s\n",(flag?"Yes":"No"));
			scanf("%d",&a[1]);
		}
		putchar('\n');
	}
	return 0;
}
