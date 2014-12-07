#include<iostream>
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
	void read_p(){
		cin >> x >> y;
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
	cin >> n;
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
	cout << (ans>>2) << endl;
}
return 0;
}