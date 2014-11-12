#include <iostream>
#include <algorithm>

using namespace std;

class Cow{
public:
	Cow()	{rouA=0;rouB=0;num=0;}
	int rouA,rouB;
	int num;
};

bool compare1(Cow a,Cow b){
    return a.rouA>b.rouA;
}

bool compare2(Cow a,Cow b){
    return a.rouB>b.rouB;
}

int main(){
	int N=0, K=0;
	cin >> N >> K;
	Cow *cows=new Cow[N];
	for (int i=0; i<N;i++){
		cin >> cows[i].rouA>>cows[i].rouB;
		cows[i].num=i+1;
	}
	sort(cows,cows+N,compare1);
    sort (cows,cows+K,compare2);
	cout << cows[0].num;
	return 0;
}
