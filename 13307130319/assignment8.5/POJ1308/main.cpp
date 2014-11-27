/**
 * @author whimsycwd
 * @date   2014.11.18
 * 有向图是树 充要条件 所有点除了根入度为0 其他均为1 & 图是连通图
 *
 * 
 *
 */

#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

map<int, int> inDegree;

map<int, int> fa;

int getfather(int x) {
    if (fa[x] == x) 
        return x;

    fa[x] = getfather(fa[x]);
    return fa[x];
}
bool isConnected() {
    int blockId = -1;

    for (map<int, int>::iterator it = fa.begin(); it!=fa.end(); it++) {
        getfather(it->first);
        // printf("%d %d |  ", it->first, fa[it->first]); 
        if (blockId == -1) 
            blockId = fa[it->first];
        else {
            if (blockId != fa[it->first]) 
                return false;
        } 
    }
    return true; 
}

bool isDegreeCorrect() {
    int zeroCnt = 0;
    for (map<int, int>::iterator it = inDegree.begin(); it != inDegree.end(); ++it) {
        if (it->second > 1) 
            return false;
        if (it->second == 0) 
            ++zeroCnt;
    }
    return zeroCnt == 1;
}

int main() {
    int a, b;
    int testCase = 0;
    int edgeNumber = 0;
   
    while (cin >> a >> b && a != -1 && b!=-1) {
        if (a == 0 && b == 0) {
            if (edgeNumber == 0 || (isDegreeCorrect() && isConnected())) { 
                printf("Case %d is a tree.\n", ++testCase);
            } else {
                printf("Case %d is not a tree.\n", ++testCase);
            }
            inDegree.clear();
            edgeNumber = 0;
            continue;
        }
        if (inDegree.find(a) == inDegree.end()) 
           inDegree[a] = 0;
        if (inDegree.find(b) == inDegree.end()) 
           inDegree[b] = 0;
       
        ++inDegree[b];
            
        if (fa.find(a) == fa.end()) 
           fa[a] = a;
        if (fa.find(b) == fa.end()) 
           fa[b] = b;

        int fx = getfather(a);
        int fy = getfather(b);
        fa[fy] = fx;
            
        ++edgeNumber;
    }
    
}
