#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int rect[100100];//,ln[100100],rn[100100];
vector<int> high;
bool comp(int a,int b){
	if(rect[a] >= rect[b])
		return true;
	else
		return false;
}
int n,maxx,minn,i,j,g,h;
int main(){
	while(1){
	cin >> n;
	if(n == 0)
		return 0;
	high.clear();
	for(i=0;i<n;i++){
		scanf("%d",&rect[i]);
		high.push_back(i);
	}
	sort(high.begin(),high.end(),comp);
	//for(i=0;i<n;i++)cout << rect[high[i]] << ' ';
	maxx = 0;
	minn = n-1;
	do{
		
	}
	
	
	}
}