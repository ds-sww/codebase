#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(NULL));

    freopen("gen.txt", "w", stdout);
    int n = 10;
    cout << n << " ";
    for (int i = 0; i < n; ++i) {
        cout << rand() % 10 << " ";
    }
    cout << endl;
    cout << 0 << endl;
    return 0;
}
