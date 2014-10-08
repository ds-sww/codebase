#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class CarryFruit{
	vector<int>fruit;
	int num,cnt;
	public:
	CarryFruit(int num);
	int count();
	~CarryFruit(){};
};
CarryFruit::CarryFruit(int num){
	int i,j;
	for(i=0;i<num;i++){
		cin>>j;
		fruit.push_back(j);
	}
	cnt=0;
	sort(fruit.begin(),fruit.end());
}

int CarryFruit::count(){
	int j;
	for(;fruit.size()>1;){
		j=*(fruit.begin())+*(fruit.begin()+1);
		cnt+=j;
		fruit.push_back(j);
		if(fruit.size()>=3)
			fruit.erase(fruit.begin(),fruit.begin()+2);
			sort(fruit.begin(),fruit.end());
		num--;
	}
	return cnt;
}
int main()
{
	int in;
	cin>>in;
	CarryFruit duoduo(in);
	cout<<duoduo.count();
	return 0;
}

