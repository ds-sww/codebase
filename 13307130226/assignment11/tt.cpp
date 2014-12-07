#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
set<string>a;

int main(){
	a.clear();
	for(set<string>::iterator q=a.begin();q!=a.end();q++)
		cout << *q << ' ';
	cout << "end "<<endl;
	a.insert("bb");
	a.insert("aa");
	a.insert("cc");
	a.insert("aa");
	a.erase("aa");
	for(set<string>::iterator q=a.begin();q!=a.end();q++)
		cout << *q << ' ';
	//cout << *a.find("bb");
	//cout << a.count("bb");
	//cout << *a.find("k");
	cout << endl << endl;
	cout << "sr" << endl;
	cout << string("asdffdsa").find("s",2);
	
}