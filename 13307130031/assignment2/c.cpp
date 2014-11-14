# include <cstdio>
# include <algorithm>
using namespace std;

struct Node{
	int a,b,c,d,t;
	void scan(int x){
		scanf("%d %d %d",&a,&b,&c);
		d=x;
		t=a+b+c;
	}
	void print(){
		printf("%d %d\n",d,t);
	}
} x[500];

bool operator<(const Node& a,const Node& b){
	if(a.t!=b.t)	return a.t<b.t;
	if(a.a!=b.a)	return a.a<b.a;
	return a.d>b.d;
}

int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		x[i].scan(i+1);
	}
	sort(x,x+n);
	for(int i=n-1;i>=n-5;i--){
		x[i].print();
	}
	return 0;
}
