/*
 * @author whimsycwd
 * @date   2014.11.21
 *
 */

#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int childNum;

string pre;
string post;

int C(int n, int m) {
    long long retValue = 1;
    for (int i = 0; i < m; ++i) {
        retValue *= n - i;
    } 
    for (int i = 0; i < m; ++i) {
        retValue /= (i+1);
    }
    return retValue;
}

int walk_tree(int preIdx, int& postIdx) {
    int cnt = 0;
    int count = 1;
    int lastPostIdx = postIdx;
    while (postIdx < post.size() && post[postIdx] != pre[preIdx]) {
        count *= walk_tree(preIdx + 1 + postIdx - lastPostIdx, postIdx);
        ++cnt;
    }
    ++postIdx;
    count *= C(childNum, cnt);
    return count; 
} 

void work() {
    cin >> pre >> post;
    int preIdx = 0;
    int postIdx = 0;
    cout << walk_tree(preIdx, postIdx) << endl;  
}

int main() {

    while (cin >> childNum && childNum > 0) {
        work(); 
    }
    return 0; 
}
