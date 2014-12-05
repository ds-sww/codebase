#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 44000
const unsigned int MAXX = 1<<30;
#define swa(x,y) x^=y^=x^=y
class heap{
public:
	unsigned int cont[MAXN];
public:
	unsigned int n;
	void init(){
		n=0;
		memset(cont,-1,sizeof(int)*MAXN);
		cont[0]=0;
	}
	heap(){
		init();
	}
	~heap(){
	}
	void push(int a){
		cont[++n]=a;a=n;
		while(cont[a]<cont[a>>1]){
			swa(cont[a],cont[a>>1]);
			a>>=1;
		}
	}
	unsigned int top(){
		return cont[1];
	}
	void pop(unsigned int a=-1){
		if(a==-1){
		swa(cont[1],cont[n]);
		cont[n--]=-1;}
		else
			cont[1]+=a;
		int now;
		now=1;
		while(cont[now]>cont[now<<1]||cont[now]>cont[(now<<1)+1])
			if(cont[now<<1]<=cont[(now<<1)+1])
				{swa(cont[now],cont[now<<1]);now<<=1;}
			else
				{swa(cont[now],cont[(now<<1)+1]);now=(now<<1)+1;}
	}
	

};

int main(){
	heap tryy;
	unsigned n,ans,tmp;
	cin >> n;
	while(n--){
		cin >> tmp;
		tryy.push(tmp);
	}
	//if(tryy.n==1) ans=tryy.top(); else 
	ans = 0;
	while(tryy.n>1){
		tmp = tryy.top();
		tryy.pop();
		//cout << tmp << ' ' << tryy.top() << endl;
		ans+=tmp+tryy.top();
		tryy.pop(tmp);
	}
	cout << ans << endl;
	return 0;
}
