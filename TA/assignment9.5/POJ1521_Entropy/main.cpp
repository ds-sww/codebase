/**
 * @author whimsycwd
 * @date   2014.11.22
 * !?  what is difference between %lf & %f
 * http://stackoverflow.com/questions/210590/why-does-scanf-need-lf-for-doubles-when-printf-is-okay-with-just-f
 * print("%lf")  是无效的. 依赖编译器的解释.
 * 所以可能和标准行为不同.导致答案不正确
 */

#include<iostream>
#include<cstdio>
#include<queue>
#include<functional>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int char_count[256];

void work(string &text) {
    memset(char_count, 0, sizeof(int) * 256);

    for (int i = 0; i < text.length(); ++i) {
       ++char_count[text[i]]; 
    }

    
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < 256; ++i) {
        if (char_count[i]) {
            pq.push(char_count[i]);
        }
    }
    int ans = 0;
    if (pq.size() == 1) {
        ans = pq.top();
    } else {
        while (pq.size() > 1) {
            int v1 = pq.top();
            pq.pop();
            int v2 = pq.top();
            pq.pop();
            ans += v1 + v2;
            pq.push(v1 + v2);
       }
    }

    printf("%d %d %.1f\n", (int) text.length() * 8, ans, (double) text.length() * 8 / ans); 
}

int main() {
    string text;
    while (getline(cin , text)) {
        if (text == "END") break;
        work(text);
    }
    return 0;
}
