#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int n;
    cin >> n;
    int List[5][n];
    int i, j;
    for (i = 0; i < n; i++){
        List[0][i] = i + 1;
        cin >> List[1][i] >> List[2][i] >> List[3][i];
        List[4][i] = List[1][i] + List[2][i] + List[3][i];
    }
    for (i = 0; i < n; i++)
        for (j = n-1; j > i; j--){
            if ((List[4][j] > List[4][j-1])
                || (List[4][j] == List[4][j-1] && List[1][j] > List[1][j-1])
                || (List[4][j] == List[4][j-1] && List[1][j] == List[1][j-1] && List[0][j] < List[0][j-1]))
            {
                int k;
                for(k = 0; k < 5; k++)
                    swap(List[k][j], List[k][j-1]);
            }
        }
    for (i = 0; i < 5; i++)
        cout << List[0][i] << "\t" << List[4][i] << endl;
    return 0;
}
