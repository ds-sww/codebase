#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int H = 100007;
int hashtable[H];

struct Node {
    char before[25];
    char after[25];
    int next;
    Node() : next(-1) {}
} node[25];

int ELFhash(char* key) {
    unsigned long g,h=0;
    while(*key)
    {
        h=(h<<4)+*key++;
        g=h & 0xf0000000L;
        if(g) h^=g>>24;
        h&=~g;
    }
    return h%H;
}

void inserthash(char *s, int i) {
    int h = ELFhash(s);
    node[i].next = hashtable[h];
    hashtable[h] = i;
}

int searchhash(char *s) {
    int h = ELFhash(s);
    int next = hashtable[h];
    while (next != -1) {
        if (!strcmp(node[next].before, s)) return next;
        next = node[next].next;
    }
    return -1;
}

int main() {
    //freopen("3366.txt", "r", stdin);
    int l,n;
    cin >> l >> n;
    memset(hashtable, -1, sizeof(hashtable));
    for (int i = 0; i < l; i++) {
        cin >> node[i].before >> node[i].after;
        inserthash(node[i].before, i);
    }
    for (int i = 0; i < n; i++) {
        char str[25];
        cin >> str;
        if (searchhash(str) != -1) {
            cout << node[searchhash(str)].after << endl;
        }
        else if (str[strlen(str) - 1] == 'y') {
            if (strlen(str) > 1 && str[strlen(str) -2] == 'a' || str[strlen(str) -2] == 'e' ||
                str[strlen(str) -2] == 'i' || str[strlen(str) -2] == 'u' || str[strlen(str) -2] == 'o')
                cout << str << 's' << endl;
            else {
                str[strlen(str) - 1] = '\0';
                cout << str << "ies" << endl;
            }
        }
        else if (str[strlen(str)-1] == 'o' || str[strlen(str)-1] == 's' || str[strlen(str)-1] == 'x'
                 || (str[strlen(str)-1] == 'h' && (str[strlen(str)-2] == 'c' || str[strlen(str)-2] == 's'))) {
            cout << str << "es" << endl;
        }
        else
            cout << str << "s" << endl;
    }
    return 0;
}
