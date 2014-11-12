#include<iostream>

using namespace std;

void sort(int* array, int* array2, int first, int last) {
	if(first >= last)
		return;
	int i = first, j = last;
	int ctrl = array[first], ctrl2 = array2[first];
	while(i < j) {
		while(array[j] >= ctrl && i != j)
			j--;
		array[i] = array[j];
		array2[i]=array2[j];

		while(array[i] < ctrl && i != j)
			i++;
		array[j] = array[i];
		array2[j]=array2[i];
	}
	array[i] = ctrl;
	array2[i]= ctrl2;
	sort(array, array2, first, i-1);
	sort(array, array2, i+1, last);
}

int main() {
	int T, N;
	cin >> T >> N;
	int array[N], array2[N];
	for(int i = 0; i < N; i++) {
		cin >> array2[i];
		array[i] = array2[i];
		if(array[i] < 0)
			array[i] = -1 * array[i];
	}
	sort(array, array2, 0, N-1);
	int dist, curr = 0, sum = 0;
	for(int i = 0; i < N; i++) {
		dist = array2[i] - curr;
		if(dist < 0)
			dist = dist * -1;
		sum = sum + dist;
		curr = array2[i];
		if(sum > T) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}