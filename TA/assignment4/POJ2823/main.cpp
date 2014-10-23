/**
 * @author whimsycwd
 * @date   2014.10.14
 * 常数卡得有点厉害。
 * Accepted 8472K   5516MS  C++ 1825B   2014-10-14 22:28:28
 */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

struct Node {
    int idx;
    int value;
};

const int N = 1000005;

Node min_que[N];
int headMin = 0;
int tailMin = 0;

Node max_que[N];
int headMax = 0;
int tailMax = 0;

int min_res[N];
int max_res[N];

int n, width;

void push(const int &i, const int &x) {
    while (headMin != tailMin && min_que[tailMin-1].value >= x) 
        --tailMin;
    min_que[tailMin].idx = i;
    min_que[tailMin].value = x;
    ++tailMin;
    

    while (headMax != tailMax && max_que[tailMax-1].value <= x) 
        --tailMax;
    max_que[tailMax].idx = i;
    max_que[tailMax].value = x;
    ++tailMax;
   
}

void work(int n, int width) {
    
    int x;
    for (int i = 0; i < width; ++i) {
        scanf("%d", &x);
        push(i, x);
    }

    int cntMin = 0;
    int cntMax = 0;

    for (int i = width; i < n; ++i) {
        min_res[cntMin++] = min_que[headMin].value;
        max_res[cntMax++] = max_que[headMax].value;

        // clear expired value
        if (headMin != tailMin && min_que[headMin].idx <= i - width) 
            ++headMin;
        if (headMax != tailMax && max_que[headMax].idx <= i - width) 
            ++headMax;

        scanf("%d", &x);
        push(i, x);
    }
    min_res[cntMin++]= min_que[headMin].value;
    max_res[cntMax++] = max_que[headMax].value;


    for (int i = 0; i < cntMin; ++i) 
        printf("%d ", min_res[i]);
    printf("\n");
    for (int i = 0; i < cntMax; ++i) 
        printf("%d ", max_res[i]);
    printf("\n");

}

int main() {
    while (cin >> n >> width) {
        work(n, width);
    }
    return 0;
}
