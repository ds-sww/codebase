/**
 * @author whimsycwd
 * @date   2014.11.14
 *
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>

using namespace std;

int n;
int * height;
int * idx;

bool cmp(int idxA, int idxB) {
    return height[idxA] < height[idxB];
}

struct Node {
    int fa;
    int size;
};

Node * blocks;

int getfather_helper(int index, int update_size) {
    blocks[index].size += update_size;
    if (blocks[index].fa == index) 
        return index;
    blocks[index].fa = getfather_helper(blocks[index].fa, blocks[index].size);
    blocks[index].size = 0;
    return blocks[index].fa;
}

int getfather(int index) {
    return getfather_helper(index, 0);
}

int get_size(int index) {
    if (blocks[index].fa == -1) 
        return 0;
    else 
        return  blocks[getfather(index)].size;
}

void work() {
    height = new int[n];
    idx = new int[n];
    blocks = new Node[n];

    for (int i = 0; i < n; ++i) { 
        scanf("%d", &height[i]);
        idx[i] = i;
        blocks[i].fa = -1;
        blocks[i].size = 0;
    }

    stable_sort(idx, idx + n, cmp);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int index = idx[i];
        if (index + 1 < n) 
            ans += get_size(index + 1);
        /*
        printf("idx = %d, ans = %lld\n",index, ans);
        
        for (int i = 0; i < n; ++i) {
            printf("block = %d, father_block %d, size = %d\n", i, blocks[i].fa, blocks[i].size);
        }
        */
        
        blocks[index].fa = index;
        blocks[index].size = 1;
        if (index > 0 && blocks[index - 1].fa != -1) {
            blocks[index].fa = getfather(index - 1);
            // update size
            getfather(index);
        } 

        if (index + 1 < n && blocks[index + 1].fa != -1) {
            // update size
            blocks[getfather(index + 1)].fa = index;
            getfather(index + 1);
        }
        
        
    } 
    
    cout << ans << endl;

    delete [] height;
    delete [] idx;
    delete [] blocks;
}

int main() {
    while (cin >> n) {
        work();
    }

    return 0;
}
