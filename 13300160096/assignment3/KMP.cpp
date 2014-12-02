//
//  KMP.cpp
//  
//
//  Created by taineleau on 13/10/14.
//
//

const int maxN = 10010;

#include <stdio.h>
#include <iostream>
using namespace std;

void ini(string s, int m, int next[]) {
    next[0] = -1;
    int j = -1;
    for (int i = 1; i < m; i++) {
        while ((j > -1) && (s[j + 1] != s[i]))
            j = next[j];
        if (s[j + 1] == s[i])
            j++;
        next[i] = j;
    }
    
    /*
    
    for (int i = 0; i < m; i ++) {
        cout << next[i] << " ";
    }
    cout << endl;
     
     */
}

void find(string x, string y,int &expect) {
    int i, j, next[maxN];
    int m = x.length();
    int n = y.length();
    ini(x, m, next);
    for (j = -1, i = 0; i < n; i++) {
 //       cout << "R " << i << " " << j << endl;
        while ((j > -1) && (x[j + 1] != y[i]))
            j = next[j];
        if (x[j + 1] == y[i])
            j++;
        if (j == m - 1) {
            cout << "Find on the position " << i - m + 1 << endl;
            expect = i - m + 1;
            j = next[j];
        }
    }
}

int main() {
    string p, t;
    cin >> p;
    cin >> t;
    int exp;
    find(p, t, exp);
    return 0;
}
