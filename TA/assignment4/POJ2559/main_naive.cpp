/**
 * @author whimsycwd
 * @date 2014.10.13
 */


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;


struct Node {
    int idx;
    int height;
    Node(const int &_idx, const int &_height) : idx(_idx), height(_height) {
    }
};


vector<Node> stack;

void work(int n) {
    int height;
    int ans = 0;
    stack.clear();

      

    for (int i = 0; i< n; ++i) {
        scanf("%d", &height);
        int lastIdx = i;
        while (!stack.empty() && stack.back().height >= height) {
            lastIdx = stack.back().idx;
            stack.pop_back();
        }
        if (stack.empty() || stack.back().height != height) { 
            stack.push_back(Node(lastIdx, height));
        }
/*
        for (int i = 0; i < stack.size(); ++i) {
            cout << stack[i].idx << " " << stack[i].height << " |  ";
        }
        cout << endl;
*/
        ans = max(ans, (i + 1) * stack[0].height);
        for (int j = 0; j < stack.size(); ++j) {
            // printf("stack(%d) %d %d\n",j, stack[j].idx, stack[j].height);  
              ans = max(ans, (i - stack[j].idx + 1) * stack[j].height);
        }
    }

    cout << ans << endl;
    
}

int main() {

    int n;
    while (cin >> n && n != 0) {
        work(n);
    }
    return 0;
}

