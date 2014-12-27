#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 100003;
const int H = 100003;

struct Node {
    char english[50];
    char foreign[50];
    int next;
    Node() : next(-1) {}
} node[N];

int hashtable[H];

//int hash(char *s) {
//    unsigned int h;
//   unsigned int seed = 131;
//    for (int i = 0; i < strlen(s); i++)
//        h = h*seed + s[i];
//    return h % H;
//}

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

void insertHash(char *a, char *b, int i) {
    strcpy(node[i].english, a);
    strcpy(node[i].foreign, b);
    int h = ELFhash(b);
    node[i].next = hashtable[h];
    hashtable[h] = i;
}

int searchHash(char *s) {
    int h = ELFhash(s);
    int next = hashtable[h];
    while (next != -1) {
        if (!strcmp(node[next].foreign, s)) return next;
        next = node[next].next;
    }
    return -1;
}

int main() {
    char str[100],a[20],b[20],s[50];
    memset(hashtable, -1, sizeof(hashtable));
    int cnt = 0;
    while (gets(str) && str[0] != '\0') {
        sscanf(str, "%s %s", a, b);
        insertHash(a, b, cnt++);
    }
    while (scanf("%s",s) != EOF) {
        int i = searchHash(s);
        if (i != -1)
            printf("%s\n",node[i].english);
        else
            printf("eh\n");
    }
    return 0;
}
