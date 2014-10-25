#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

struct Node {
    int Height;
    int StartPos;
} node;

int n;
long long Size;
long long Max;
stack <Node> s;

int main() {
    while (scanf("%d",&n) && n) {
        int i,height;
        Max = 0;
        node.Height = 0;
        node.StartPos = 0;
        s.push(node);

        for (i = 1; i <= n; i++) {
            scanf("%d", &height);
            node.Height = height;
            node.StartPos = i;

            while (height < s.top().Height) {
                node.StartPos = s.top().StartPos;
                Size = (i - s.top().StartPos) * s.top().Height;
                if (Size > Max) Max = Size;
                s.pop();
            }
            if (height == s.top().Height)
                node.StartPos = s.top().StartPos;
            s.push(node);
        }

        while (!s.empty()) {
            Size = (i - s.top().StartPos) * s.top().Height;
            if (Size > Max) Max = Size;
            s.pop();
         }

         cout << Max << endl;
    }
    return 0;
}
