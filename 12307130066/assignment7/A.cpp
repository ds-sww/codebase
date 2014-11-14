#include<iostream>
using namespace std;

void sort(int* array, int first, int last) {
	if(first >= last)
		return;
	int ctrl = array[first];
	int i = first, j = last;
	while(i < j) {
		while(array[j] >= ctrl && i != j)
			j--;
		array[i] = array[j];
		while(array[i] < ctrl && i != j)
			i++;
		array[j] = array[i];
	}
	array[i] = ctrl;
	sort(array, first, i-1);
	sort(array, i+1, last);
}

int main() {
	int cases;
	cin >> cases;
	for(int c = 0; c < cases; c++) {
		int needed, friends;
		cin >> needed >> friends;
		int array[friends];
		for(int i = 0; i < friends; i++)
			cin >> array[i];
		//cout << "Oops!" << endl;
		sort(array, 0, friends-1);
		//cout << "Oops!" << endl;
		int i, sum = 0;
		for(i = 0; i < friends; i++) {
			sum = sum + array[friends - 1 - i];
			if(sum >= needed)
				break;
		}
		if(i == friends)
			cout << "Scenario #" << c+1 << ":\n" << "impossible\n" << endl;
		else {
			cout << "Scenario #" << c+1 << ":\n";
			cout << i+1 << endl << endl;
		}
	}
	return 0;
}
