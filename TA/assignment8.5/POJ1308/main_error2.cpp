/**
 * @author whimsycwd
 * @date   2014.11.18
 * 有向图是树 充要条件 所有点除了根入度为0 其他均为1
 * 
 * @chiyahoho
 * 一棵树+一个环会错哦……
 *  1 2 3 4 4 3 这样 
 */

#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

map<int, int> inDegree;

bool isTree() {
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
            if (edgeNumber == 0 || isTree()) { 
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
            
        ++edgeNumber;
    }
    
}
