/**
 * @author whimsycwd
 * @date   2014.10.4
 *
 * Node
 */

#include<memory>

using namespace std;

class Node {
    public :
        int key;        // node key        
        Node * lc;      // left child
        Node *  rc;      // right child
        Node * p;       // parent
        int size;          // size of subtree

       
        // this constuctor used by Nil
        Node(int _key) : key(_key), lc(0), rc(0), p(0), size(0) {
        }
       
};

