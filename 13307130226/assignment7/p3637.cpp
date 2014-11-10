#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t,n;
int i,j,g,h;
vector<int> thing;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		thing.resize(n);
		for(i=0;i<n;i++)
			cin >> thing[i];
		sort(thing.begin(),thing.end(),cmp);
		for(g=0,i=2;i<n;i+=3)
			g+=thing[i];
		cout << g << endl;
	}
	return 0;
}