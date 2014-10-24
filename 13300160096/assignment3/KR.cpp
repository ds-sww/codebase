//
//  KR.cpp
//  
//
//  Created by taineleau on 13/10/14.
//
//

#include <stdio.h>
#include <iostream>
using namespace std;

int d = 2 << 4;

#define Rehash(a, b, h) ((((h) - (a) * d) << 1) + (b))


void find(string y, string x, int &expect) {
    expect = -1;
    int hx, hy, i, j, m = x.length(), n = y.length();
    
    for (hy = hx = i = 0; i <m; i++) {
        hx = hx * 2 + x[i];
        hy = hy * 2 + y[i];
    }
    for (int i = 0; i <= n - m + 1; i++) {
        int boo = 0;
        cout << "hash: " << hx << " " << hy << endl;
        if (hx == hy) {
            boo = 1;
            for (int j = 0; j <= m; j++) {
                boo = boo && (y[i + j] == x[j]);
                cout << x[j] << " " << y[i + j] << endl << boo;
            }
        }
        if (boo) {
            expect = i;
            break;
        } else {
            if (n - m > 0)
                hy = Rehash(y[j], y[j + m], hy);
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
    return 0;
}