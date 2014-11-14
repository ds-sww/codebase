/**
 * @author whimsycwd
 * @date   2014.11.2
 */

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

string strA;
string strB;

void work() {
    int charCountA[26];
    int charCountB[26];
    
    memset(charCountA, 0, sizeof(charCountA));
    memset(charCountB, 0, sizeof(charCountB));

    for (int i = 0; i < strA.size(); ++i) {
        charCountA[strA[i] - 'A']++;
    }
    for (int i = 0; i < strB.size(); ++i) {
        charCountB[strB[i] - 'A']++;
    }

    sort(charCountA, charCountA + 26);
    sort(charCountB, charCountB + 26);

    for (int i = 0; i < 26; ++i) {
        if (charCountA[i] != charCountB[i]) {
            cout << "NO" << endl; 
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    while (cin >> strA >> strB) {
        work();
    }
}
