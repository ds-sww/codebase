#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int fruit[n];
	int i, j, temp, left, steps = 0;
	for (i = 0; i < n; i++)
		cin >> fruit[i];
	for (i = 0; i < n; i++)
		for (j = n - 1; j > i; j--){
		if (fruit[j] < fruit[j - 1]){
			temp = fruit[j - 1];
			fruit[j - 1] = fruit[j];
			fruit[j] = temp;
		}
		}
	left = n;
	while (left != 1){
		temp = fruit[0] + fruit[1];
		steps += temp;
		for (i = 2, j = 2; i < left; i++){
			if (fruit[i] > temp)
				if (j == 2){
				j = 1;
				fruit[i - 2] = temp;
				}
			fruit[i - j] = fruit[i];
		}
		if (i == left&&j == 2)fruit[i - 2] = temp;
		left--;
	}
	cout << steps << endl;
	return 0;
}

