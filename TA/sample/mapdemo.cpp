/**
 * @author whimsycwd
 * @date   2014.12.19
 *
 */


#include<iostream>
#include<map>

using namespace std;

struct node {
    int x;
    int y;
    node(int _x, int _y) : x(_x), y(_y) { }
};

struct nodeComp{
    bool operator() (const node& lhs, const node& rhs) const {
        if (lhs.x < rhs.x) return true;
        if (lhs.x > rhs.x) return false;
        return lhs.y < rhs.y;
    }
};

int main() {
    map<node, int, nodeComp> mp;

    mp.insert(make_pair(node(1,2), 1));
    mp.insert(make_pair(node(1,3), 2));
    mp.insert(make_pair(node(2,1), 3));
    mp.insert(make_pair(node(2,0), 4));

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first.x << " " << it->first.y  << ": " << it->second << endl;
    }


    return 0; 
}
