#include <iostream>
#include <stdlib.h>
using namespace std;

const int N = 50005;

struct Node {
    int index;
    long long first;
    long long second;
    Node() {index = first = second = 0;}
    Node& operator = (Node& node) {
        index = node.index;
        first = node.first;
        second = node.second;
        return *this;
    }
};

int firstcmp (const void *a,const void *b) {
    return ((*(Node *)a).first < (*(Node *)b).first) ? 1 : -1;
}

int secondcmp (const void *a, const void *b) {
    return ((*(Node *)a).second < (*(Node *)b).second) ? 1 : -1;
}

int main() {
    int n,k;
    Node a[N];
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        a[i].index = i+1;
        cin >> a[i].first >> a[i].second;
    }
    qsort(a,n,sizeof(Node),firstcmp);
    qsort(a,k,sizeof(Node),secondcmp);
    cout << a[0].index << endl;
    return 0;
}
