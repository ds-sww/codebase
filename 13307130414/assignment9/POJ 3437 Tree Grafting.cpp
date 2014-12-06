#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[20000];
int dep1, dep2;

struct Node {
    int lchild,rchild,parent,height;
    Node() : lchild(-1), rchild(-1), parent(-1), height(0){}
};

int main() {
    int tree = 0;
    while(1) {
        scanf("%s",s);
        if (s[0] == '#') return 0;
        dep1 = dep2 = 0;
        int temp = 0;
        int p = 0, n = 1;
        Node node[10000];
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == 'd') {
                //dep1:
                temp++;
                if (temp > dep1) dep1 = temp;
                //dep2:
                if (node[p].lchild == -1) {
                    node[p].lchild = n;
                    node[n].parent = p;
                    node[n].height = node[p].height+1;
                    if (node[n].height > dep2) dep2 = node[n].height;
                }
                else {
                    node[n].parent = p;
                    int t = node[p].lchild;
                    while(node[t].rchild != -1)
                        t = node[t].rchild;
                    node[t].rchild = n;
                    node[n].height = node[t].height+1;
                    if (node[n].height > dep2) dep2 = node[n].height;
                }
                p = n;
                n++;
            }
            else {
                temp--;
                p = node[p].parent;
            }
        }
        printf("Tree %d: %d => %d\n",++tree,dep1,dep2);
    }
}
