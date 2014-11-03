#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int i;
    int cipher[26],origin[26];
    memset(cipher,0,sizeof(cipher));
    memset(origin,0,sizeof(origin));
    string input1,input2;
    cin >> input1;
    for (i = 0; i < input1.length(); i++) {
        cipher[input1[i] - 'A'] ++;
    }
    cin >> input2;
    for (i = 0; i < input2.length(); i++) {
        origin[input2[i] - 'A'] ++;
    }
    sort(cipher,cipher+26);
    sort(origin,origin+26);
    for (i = 0; i < 26 && cipher[i] == origin[i]; i++);
    if (i == 26)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
