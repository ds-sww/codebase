#include <iostream>
using namespace std;

struct node {
    int parent;
    bool flag;
    node() : parent(0), flag(false) {};
} Node[200];

void clearset() {
    for (int i = 0; i < 200; i++) {
        Node[i].parent = 0;
        Node[i].flag = false;
    }
    return;
}

void add(int x, int y) {
    Node[y].parent = x;
    Node[x].flag = Node[y].flag = true;
}

int findroot(int x) {
        if (Node[x].parent)
            x = findroot(Node[x].parent);
        return x;
}

bool singleroot(int n) {
    int i = 1;
    while (!Node[i].flag && i <= n)
        i++;
    int root = findroot(i);
    for (i = 0; i <= n; i++) {
        if (Node[i].flag && findroot(i) != root)
            return false;
    }
    return true;
}

int main() {
    int count = 1;
    while (1) {
        int a,b;
        int range = 0;
        bool isatree = true;
        while (cin >> a >> b) {
            if (a < 0 || b < 0) return 0;
            if (a == 0 && b == 0) {
                if (isatree == true && singleroot(range))
                    cout << "Case " << count++ << " is a tree." << endl;
                else
                    cout << "Case " << count++ << " is not a tree." << endl;
                isatree = true;
                clearset();
                range = 0;
                continue;
            }
            if (isatree == false)
                continue;
            range = a > range ? a : range;
            range = b > range ? b : range;
            if (Node[b].parent) {
                isatree = false;
                continue;
            }
            if (findroot(a) == findroot(b)) {
                isatree = false;
                continue;
            }
            add(a,b);
        }
    }
}
