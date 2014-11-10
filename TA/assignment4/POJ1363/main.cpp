/**
 * @author whimsycwd
 * @date   2014.10.13
 */

#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;

vector<int> vec;

bool work(int n) {
    vec.clear();
    int x;
    int cur = 0;
    for (int i = 0; i< n; ++i) {
        cin >> x;
        if (x == 0) return false;
           

        while (x > cur & cur < n) {
            vec.push_back(++cur);
        }
/*
        printf("x = %d %d\n", x, cur);
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        cout << endl;
*/
        if (vec.size() == 0 || vec.back() != x) {
            cout << "No" << endl;
            for (int k = i+1; k < n; ++k)  cin >> x;
            return true;
        } else {
            vec.pop_back();
    
        }
    }
    cout << "Yes" << endl;
    return true;
}


int main() {
    int n;
    while (cin >> n && n != 0) {
        while(work(n));
        cout << endl;
    }
    return 0;
}

