#include<string>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
string a;
int maxx,i,j,g,h,te;
vector<int>de;
int main(){
te = 1;
while(1){
	cin >> a;
	if(a == "#"){
		break;
	}
	cout << "Tree " << te++ << ": ";
	maxx  = 0;
	for(i=0,j=0;i<a.size();i++){
		if(a[i]=='d')
			j++;
		else
			j--;
		maxx = maxx > j?maxx:j;
	}	
	cout <<  maxx << " => ";
	maxx = 0;
	de.clear();
	de.push_back(0);
	for(i=j=0;i<a.size();i++){
		if(a[i] == 'd'){
			de.push_back(++j);
			maxx = maxx > j?maxx:j;
		}
		else {
			de.pop_back();
			de[de.size()-1]++;
			j = de.back();	}
	}
	cout << maxx << endl;

}
return 0;
}