#include<iostream>
#include<string>

using namespace std;

void sort(int* array, int first, int last) {
	if(first >= last)
		return;
	int i = first, j = last;
	int ctrl = array[first];
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
	int N1, N2;
	cin >> N1;
	int array[N1];
	for(int i = 0; i < N1 ; i++) {
		cin >> array[i];
	}
	sort(array, 0, N1-1);
	string tmp;
	cin >> tmp;
	cin >> N2;
	for(int i = 0; i < N2; i++) {
		int ith;
		cin >> ith;
		cout << array[ith-1] << endl;
	}
	return 0;
}