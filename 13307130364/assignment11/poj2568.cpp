#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;
vector<int> data[55];
int maxn;
void printin(int n){
	if (n != maxn)
		cout << " ";
	cout << "("<<n;
	//sort(data[n].begin(), data[n].end());
	for (vector<int>::iterator it = data[n].begin(); it != data[n].end(); it++){
		printin(*it);
	}
	cout << ")";
}
int main(){
	string a;
	while (getline(cin, a)){
		stringstream s;
		s << a;
		int x;
		map<int, int> ma;//度数
		vector<int> vec;//输入
		set<int> se;//可插入节点
		for (int i = 0; i < 60; i++){
			data[i].clear();
			ma[i] = 0;
		}
		vec.clear();
		se.clear();
		while (s >> x){
			vec.push_back(x);
			ma[x]++;
		}
		for (int i = 1; i <= vec.size()+1; i++){
			if (ma[i] == 0)
				se.insert(i);
		}
		for (vector<int>::iterator vit = vec.begin(); vit!=vec.end(); vit++){
			data[*vit].push_back(*se.begin());
			se.erase(se.begin());
			if (--ma[*vit] == 0)
				se.insert(*vit);
		}
		maxn = *se.begin();
		printin(maxn);
		cout << endl;
	}

	return 0;
}