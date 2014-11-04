/**
 * @author whimsycwd
 * @date   2014.11.2
 *
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

bool cmpRoundA(const Node &a, const Node &b) {
    return a.first > b.first;
}

void work() {
    Node * votes = new Node[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &votes[i].first, &votes[i].second);
        votes[i].idx = i;
    }

    sort(votes, votes + n, cmpRoundA);
 /*
     for (int i = 0; i < n; ++i) 
        printf("%d %d %d\n", votes[i].idx, votes[i].first, votes[i].second);
*/
    int ansIndex = 0;
    
    for (int i = 1; i < k; ++i) {
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
