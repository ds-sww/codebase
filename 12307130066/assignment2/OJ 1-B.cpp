#include <iostream>
#include <vector>

using namespace std;

int main() {
	int s, tmp, sum = 0;
	cin >> s;
	vector<int> clusters;
	for(int i = 0; i < s; i++) {
		cin >> tmp;
		int j;
		for(j = 0; j < i; j++) {
			if(tmp < clusters[j])
				break;
		}
		if(j == i)
			clusters.push_back(tmp);
		else
			clusters.insert(clusters.begin()+j, tmp);
	}
	for(int i = 0; i < s-1; i++) {
		tmp = clusters[0] + clusters[1];
		sum = sum + tmp;
		clusters.erase(clusters.begin());
		clusters.erase(clusters.begin());
		int j;
		for(j = 0; j < clusters.size(); j++) {
			if(tmp < clusters[j])
				break;
		}
		if(j == clusters.size())
			clusters.push_back(tmp);
		else
			clusters.insert(clusters.begin()+j, tmp);
	}
	cout << sum << endl;
	return 0;
}