/**
 * @author whimsycwd
 * @date   2014.11.21
 * 仔细想想, 有线性的做法
 */


#include<iostream>
#include<cstdio>
#include<set>
#include<vector>

using namespace std;

vector<int> hNumbers;
set<long long> candidate;

int work(int n) {

    while (n >= hNumbers.size()) {
        long long topValue = *candidate.begin();
        hNumbers.push_back(topValue);
        candidate.erase(candidate.begin());
        
        candidate.insert(topValue * 2);
        candidate.insert(topValue * 3);
        candidate.insert(topValue * 5);
        candidate.insert(topValue * 7);
    }
    return hNumbers[n]; 

}

int main() {
    candidate.insert(1);

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
