#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class point{
public:
	int x,y;
	point(){
		;
	}
	point(const int a,const int b){
		x=a;y=b;
	}
	void set_point(const int a,const int b){
		x=a;y=b;
	}
	bool operator<(const point& a)const{
		if(x<a.x)return true;
		else if(x>a.x)return false;
		else if(y<=a.y)return true;
		else return false;
	}
	bool operator==(const point& a)const{
		if(a.x == x && a.y == y)return true;
		return false;
	}
	bool operator>(const point& a)const{
		if(x>a.x)return true;
		else if(x<a.x)return false;
		else if(y>=a.y)return true;
		else return false;
	}	
	void const disp(){
		cout << "point: x " << x << " y " << y << endl;
	}
	void read_p(){  //越写越奇怪的读入优化...
		//以后再也不写读入优化了TT
		scanf("%d%d",&x,&y);
		return;
		char a;bool ne;
		x = y = 0;
		//disp();
		a = 'x';
		while(a != '-' && a<'0'|| a>'9')
			 a=getchar();
		ne = false;
		do{
			if(a == ' ')break;
			if(a == '-'){ne=true;continue;}
			x = x*10 + a - '0';
		}while(a=getchar());
		if(ne)x=-x;ne=false;
		while(a=getchar()){
			if(a!= '-' && a < '0' or a > '9')break;
			if(a == '-'){ne=true;continue;}
			y = y*10 + a - '0';
		}
		if(ne)y=-y;
		//disp();
		//cin >> x >> y;
	}
};
typedef vector<point> stars;

void gen(stars& q,point a,point b){
	int dx,dy;
	dx = b.x - a.x;
	dy = b.y - a.y;
	q.clear();
	q[0].set_point(a.x+dy,a.y-dx);
	q[1].set_point(q[0].x+dx,q[0].y+dy);
	q[2].set_point(a.x-dy,a.y+dx);
	q[3].set_point(q[2].x+dx,q[2].y+dy);
}

stars st,tmp;
int n,ans;
/*
bool get_p(point a){
	for(int i=0;i<n;++i){
		if(st[i].x == a.x && st[i].y == a.y)
			return true;
	}
	return false;
}*/
bool get_p(point a){
	int l,r,midn;
	point mid;
	l = 0;
	r = n;
	while(l<r){
		midn = (l+r)>>1;
		mid = st[midn];
		if(mid == a)return true;
		else if(mid < a)l=midn+1;
		else r = midn;
	}
	//a.disp();
	return false;
}

int main(){
tmp.resize(4);
while(1){
	scanf("%d",&n);
	//cin >> n;
	if(n == 0)break;
	st.resize(n);
	for(int i=0;i<n;i++)
		st[i].read_p();
	sort(st.begin(),st.end());
	ans = 0;
	for(int i=0;i<n-1;++i)
		for(int j=i+1;j<n;++j){
			gen(tmp,st[i],st[j]);
			if(get_p(tmp[0])&&get_p(tmp[1]))++ans;
			if(get_p(tmp[2])&&get_p(tmp[3]))++ans;
		}
	//printf("%d\r\n",ans>>2); //TT竟然没有下面那个快简直...
	cout << (ans>>2) << endl;
}
return 0;
}