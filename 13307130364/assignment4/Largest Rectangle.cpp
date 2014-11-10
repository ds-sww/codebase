#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int func(const int* a,const int count){
	stack<int> r;
	int temp;
	int minium=0;
	int s=0;
	int w = 0;
	for (int i=0; i < count;i++){
		if (r.size()==0||a[i] >= a[r.top()]){
			r.push(i);
		}
		else{
			while (!r.empty() && a[r.top()] > a[i]){
				temp = r.top(); 
				r.pop();
				w = r.empty() ? i : (i - r.top()-1);
				s = max(s, a[temp] * w);
			}
			r.push(i);
		}
	}
	return s;
}
int main(){
	int count;
	int flag = 0;
	cin >> count;
	while (count){
		int *a = new int[count+1];
		for (int i = 0; i < count; i++)
			cin >> a[i];
		a[count] = 0;
		if (flag)
			cout << endl;
		cout << func(a,count+1);
		flag = 1;
		cin >> count;
	}
	return 0;
}