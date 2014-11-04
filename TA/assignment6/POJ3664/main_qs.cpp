/**
 * @author whimsycwd
 * @date   2014.11.2
 * Linear expected complexity.
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>

using namespace std;

int n,k;


struct Node {
    int first;
    int second;
    int idx;
};


void mySort(Node votes[], int l, int r) {
    
    if (l + 1 >= r) 
        return;

    int i = l;
    int j = r;
    int pole = votes[(l + r) / 2].first;

    while (i < j) {
        while (i < r && votes[i].first < pole) ++i;
        while (j > l && votes[j-1].first > pole) --j;

        if (i < j) {
            swap(votes[i], votes[j - 1]);
            ++i;
            --j;
        }
    }
    if (j >= n-k) mySort(votes, l, j);
    else mySort(votes, i, r);
} 

void work() {
    Node * votes = new Node[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &votes[i].first, &votes[i].second);
        votes[i].idx = i;
    }

    mySort(votes, 0, n);
/* 
     for (int i = 0; i < n; ++i) 
        printf("%d %d %d\n", votes[i].idx, votes[i].first, votes[i].second);
*/
    int ansIndex = n - k;
    
    for (int i = n - k + 1; i < n; ++i) {
        if (votes[i].second > votes[ansIndex].second) {
            ansIndex = i;
        }
    }

    cout <<  votes[ansIndex].idx + 1 << endl;
   

    delete [] votes;
}

int main() {
    while (cin >> n >> k) {
        work();
    }
    return 0;
}
