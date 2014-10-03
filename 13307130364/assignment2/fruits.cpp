#include <iostream>
#include <set>
int main(){
	using namespace std;
	multiset<int> fruits;
	int count,step=0;
	int t,a,b;
	cin >> count;
	for (int i = 0; i < count; i++){
		cin >> t;
		fruits.insert(t);
	}
	multiset<int>::iterator cp;
	for (; fruits.size() != 1;){
		cp = fruits.begin();
		a = *cp;
		fruits.erase(cp);
		cp = fruits.begin();
		b = *cp;
		fruits.erase(cp);
		fruits.insert(a + b);
		step += (a + b);
	}
	cout << step << endl;
}