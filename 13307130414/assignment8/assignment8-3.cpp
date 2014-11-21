#include <iostream>
using namespace std;

int n;

void maketree(int i) {
    if (i > n) return;
    if (i == 1)
        cout << i;
    else
        cout << ' ' << i;
    maketree(2*i);
    maketree(2*i+1);
}

int main() {
    while (cin >> n) {
        if (n == 0) return 0;
        maketree(1);
        cout << endl;
    }
}
