//
//  BruteForce.cpp
//  
//
//  Created by taineleau on 13/10/14.
//
//

#include <stdio.h>
#include <iostream>
using namespace std;


void find(string text, string pattern, int &expect) {
    expect = -1;
    for (int i = 0; i <= text.length() - pattern.length(); i++) {
        int boo = 1;
        for (int j = 0; j < pattern.length(); j++) {
            boo = boo && (text[i + j] == pattern[j]);
            cout << pattern[j] << " " << text[i + j] <<  boo << endl;
        }
        if (boo) {
            expect = i;
            break;
        }
    }
}


int main()
{
    string p, t;
    cin >> p;
    cin >> t;
    int exp;
    find(t, p, exp);
    if (exp == -1) {
        cout << "Cannot find!" << endl;
        
    } else {
        cout << "Find on the position " << exp + 1 << endl;
    }
}