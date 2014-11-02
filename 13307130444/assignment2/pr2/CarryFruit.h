#include<iostream>
#include<vector>
using namespace std;
class CarryFruit{
	vector<int> fruit;
	int num;
	public:
	CarryFruit();
	int countLabor();
	~CarryFruit(){};
}
CarryFruit::CarryFruit(){
	int i;
	cin>>num;
	while(cin>>i){
		fruit.push_back(i);
	}
}
int CarryFruit::countLabor(){
	int labor=0;
	vector<int>::iterator it1=fruit.begin();
	vector<int>::iterator it2=fruit.end();
	vector<int>::iterator it3;
	sort(it1,i2);
	vector<int>  fruitheap;
	it2=it1+1;
	for(;it1&&it2;)
	{
		if(!it3){
			fruitpile.push_back((*it1++)+(*it2++));
			it3=fruitpile.begin();
		}
		else
			if (*it2<*it3){
			fruitpile.push_back(*it1+*it2);
			it1+=2;it2+=2;
			}
			else{
			fruitpile.push_back(*it1+it3);
			it1++;it2++;it3++;
			}
	}
	if(it1)
		labor=*it3+*it1;
	else{
		it2=it3-1;
		labor=*it2+*it3;
	}
	return labor;
}

