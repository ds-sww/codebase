#include <iostream>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

struct man{
	int a,b,c;
}stu[500];
int n,a,b,c;

bool cmp(man u,man v){
	return u.a>v.a || (u.a==v.a && u.b>v.b) || (u.a==v.a && u.b==v.b && u.c<v.c);
}
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>a>>b>>c;
		stu[i].a=a+b+c;
		stu[i].b=a;
		stu[i].c=i;
	}
	sort(stu+1,stu+n+1,cmp);
	rep(i,1,5) cout<<stu[i].c<<' '<<stu[i].a<<endl;
}