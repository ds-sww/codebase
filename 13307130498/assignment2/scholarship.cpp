#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int std[n][5];
	int i, j, p, q;
	for (i = 0; i < n; i++){
		for (j = 0; j < 3; j++)
			cin >> std[i][j];
		std[i][3] = std[i][0] + std[i][1] + std[i][2];
		std[i][4] = i + 1;
	}
	int order[n][5];
	for (j = 0; j < 5; j++)
		order[0][j] = std[0][j];

	for (i = 1; i < n; i++){
		for (p = 0; p < i; p++){
			if (std[i][3] > order[p][3]){
				for (j = i; j > p; j--)
					for (q = 0; q < 5; q++)
						order[j][q] = order[j - 1][q];
				for (q = 0; q < 5; q++)
					order[j][q] = std[i][q]; break;
			}
			if (std[i][3] == order[p][3]){
				if (std[i][0] > order[p][0]){
					for (j = i; j > p; j--)
						for (q = 0; q < 5; q++)
							order[j][q] = order[j - 1][q];
					for (q = 0; q < 5; q++)
						order[j][q] = std[i][q]; break;
				}
				if (std[i][0]<order[p][0])
					for (j = i; j>p + 1; j--){
					for (q = 0; q < 5; q++)
						order[j][q] = order[j - 1][q];
					for (q = 0; q < 5; q++)
						order[j][q] = std[i][q]; break;
					}
				if (std[i][0] == order[p][0]){
					if (std[i][4] < order[p][4]){
						for (j = i; j > p; j--)
							for (q = 0; q < 5; q++)
								order[j][q] = order[j - 1][q];
						for (q = 0; q < 5; q++)
							order[j][q] = std[i][q]; break;
					}
					if (std[i][4] > order[p][4])
						for (j = i; j > p + 1; j--){
						for (q = 0; q < 5; q++)
							order[j][q] = order[j - 1][q];
						for (q = 0; q < 5; q++)
							order[j][q] = std[i][q]; break;
						}
				}
			}
		}
		if (p == i)
			for (q = 0; q < 5; q++)
				order[i][q] = std[i][q];
	}
	for (i = 0; i < 5; i++)
		cout << order[i][4] << "  " << order[i][3] << endl;

	return 0;
}
