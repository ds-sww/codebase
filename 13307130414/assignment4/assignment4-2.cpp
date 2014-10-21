#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    vector <int> rec;
    int Rec;
    int n;
    int i,j,k;
    int num;
    long long  Size;
    long long Max;

    while (1) {
        cin >> n;
        if (n == 0) break;
        for(i = 0; i < n; i++) {
            scanf("%d", &Rec);
            rec.push_back(Rec);
        }
        Max = 0;
        for (i = 0; i < n; i++) {
            for (j = i; rec[j] >= rec[i] && j < n; j++) ;
            for (k = i; rec[k] >= rec[i] && k >= 0; k--) ;
            num = j-k-1;
            Size = num * rec[i];
            if (Size > Max)
                Max = Size;
        }
        while (!rec.empty())
            rec.pop_back();
        cout << Max << endl;
    }

    return 0;
}
