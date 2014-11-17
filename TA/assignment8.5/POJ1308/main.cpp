/**
 * @author whimsycwd
 * @date   2014.11.17
 *
 */

#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

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



int main() {
    int a, b;
    int testCase = 0;
    bool isTreeFlag = true;
    int edgeNumber = 0;
   
    while (cin >> a >> b && a != -1 && b!=-1) {
        if (a == 0 && b == 0) {
            if (edgeNumber == 0 ||  
                    (fa.size() == edgeNumber + 1 && isConnected())) {
                printf("Case %d is a tree.\n", ++testCase);
            } else {
                printf("Case %d is not a tree.\n", ++testCase);
            }
            fa.clear();
            edgeNumber = 0;
            continue;
        }
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
