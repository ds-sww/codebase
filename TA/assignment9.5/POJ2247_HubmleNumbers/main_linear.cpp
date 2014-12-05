/**
 * @author whimsycwd
 * @date   2014.11.28
 */


#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

const long long INF = 3000000000; 
vector<int> hNumbers;

int base[] = {2,3,5,7};
int tp[4];

int work(int n) {


    while (n >= hNumbers.size()) {
        long long value = INF;
        for (int i = 0; i < 4; ++i) {
            value = min(value, (long long) hNumbers[tp[i]] * base[i]);
        }
        
        for (int i = 0; i < 4; ++i) {
            if (value == (long long) hNumbers[tp[i]] * base[i]) ++tp[i];        
        } 

        hNumbers.push_back(value);
    }
    return hNumbers[n]; 

}

int main() {
    hNumbers.push_back(1);
    tp[0] = tp[1] = tp[2] = tp[3] = 0;

    int testCase = 0;
    int n;
    while (cin >> n && n > 0) {
        string suffix = "th";
        if (n % 100 != 11 && n % 10 == 1) suffix = "st";
        if (n % 100 != 12 && n % 10 == 2) suffix = "nd";
        if (n % 100 != 13 && n % 10 == 3) suffix = "rd";
        
        printf("The %d%s humble number is %d.\n", n, suffix.c_str(), work(n - 1));
    }
    return 0;
}
