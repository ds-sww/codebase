/*
 * @author whimsycwd
 * @date   2014.10.4
 * 
 * Binary Search Trees
 * key is a integer
 *
*/

#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>

#include "Node.h"

using namespace std;

const static int NIL_CONST = -1;
static Node * Nil = new Node(NIL_CONST);   // sentinel

struct BSTIterator;

class BST {
    
    public :
        typedef BSTIterator         iterator;
    private :
        Node * root;
    


        Node * makeNode(int key) {
            Node * retValue = new Node(key);
            retValue->lc = Nil;
            retValue->rc = Nil;
            retValue->p = Nil;
            retValue->size = 1;
            return retValue;
        }

        void fix_size(Node * x) {
        
            // trap~  wehn x == Nil. 
            // transplant v,v.rc when rc == Nil, still need to update parent
            while (x!=Nil) {

                x->size = x->lc->size + x->rc->size + 1;
                // cout << x->key << " " << x->size << endl;
                x = x->p;
            } 
        }

        // because we need to maintain parent pointer, so it's unconvience to write in recursive way.
        void add(Node * z) {
            auto y = Nil;
            auto x = root;
            
            while (x != Nil) {
                y = x;
                if      (z->key < x->key) x = x->lc;
                else if (z->key > x->key) x = x->rc;
                else return;                   // ignore duplicate key
            }

            z->p = y;

            if      (y == Nil)          root = z;
            else if (z->key < y->key)   y->lc = z;
            else                        y->rc = z;


            fix_size(z);
            
        }

        //  Note that TRANSPLANT does not attemp to update v.left 
        //  and v.right; doing so, or not doing so, is the responsibility
        //  of TRANSPLANT's caller
        //  !caution, in order to use fix_size, caller have to make sure lc and rc 
        //  is setted properly.
        void transplant(Node * u, Node * v) {
            if (u->p == Nil) root = v; 
            else if (u == u->p->lc) u->p->lc = v;
            else u->p->rc = v;

            v->p = u->p;
        
            // TODO : necessary?    
            
            // trap~  when v == Nil. 
            // transplant v,v.rc when rc == Nil, still need to update parent
            if (v == Nil)   fix_size(v->p);
            else            fix_size(v);  
        }

        void del(Node * z) {
            if      (z->lc == Nil) transplant(z, z->rc);
            else if (z->rc == Nil) transplant(z, z->lc);
            else {
                auto y = min(z->rc);
                if (y->p != z) {
                    transplant(y, y->rc);
                    y->rc = z->rc;
                    y->rc->p = y;
                }
                y->lc = z->lc;
                y->lc->p = y;
                transplant(z, y);
            }

            delete z;   // destroy

        }

        Node * min(Node * x) {
            if (x == Nil) return Nil;
            while (x->lc != Nil) {
                x = x->lc;
            }
            return x;
        }
        Node * max(Node * x) {
            if (x == Nil) return Nil;
            while (x->rc != Nil) {
                x = x->rc;
            }
            return x;
        }

        Node * prev(Node * x) {
            if (x->lc != Nil) {
                return max(x->lc);
            }
            
            auto y = x->p;
            while (y != Nil && x == y->lc) {
                x = y;
                y = y->p;
            }
            return x;

        }

        Node * succ(Node * x) {
            if (x->rc != Nil) {
                return min(x->rc);
            }
            auto y = x->p;
           // cout << "inside " << x->key << " " << x->p->key << endl;

            while (y != Nil && x == y->rc) {
                x = y;
                y = y->p;
            }
            return y; 
        }

        Node * find(int key) {
            auto x = root;
            while (x != Nil) {
                if      (x->key == key) return x;
                else if (key < x->key)  x = x->lc;
                else                    x = x->rc; 
            }
            return x;
        }
        void walk(vector<int> &vec, Node * root) const{
            if (root == Nil) return;
            
            walk(vec, root->lc);
            vec.push_back(root->key);
            walk(vec, root->rc);
        }
        void walk(vector<int> &vec) const {
            walk(vec, root);
        }
        
        int size(Node * x) {
            return x->size;
        }
        Node * select (Node * x, int k) {
            int t = size(x->lc);
            if      (k < t) return select(x->lc, k);
            else if (k > t) return select(x->rc, k - t - 1);
            else            return x; 

        }

        int rank(Node * x, int key) {
            if (x == Nil) return 0;
            if      (key < x->key)  return rank(x->lc, key);
            else if (key > x->key)  return 1 + size(x->lc) + rank(x->rc, key);
            else                    return size(x->lc);
        }

        int height(Node * x) {
            if (x == Nil) return 0;
            return std::max(height(x->lc), height(x->rc)) + 1;
        }



    public : 
        BST() {
            root = Nil;
        }

        // add new elements
        void add(int key) {
            add(makeNode(key));
        }

        void del(int key) {
            Node * x = find(key);
           // cout << "In del: " << x->key << endl;
            if (x != Nil) del(x);
        }

        int min() {
            return min(root)->key;
        }

        int max() {
            return max(root)->key;
        }
        int size() {
            return size(root);
        }
        
        int height() {
            return height(root);
        }

        /******************************
         *  Rank and selection
         *****************************/

        int select(int k) {
            if (k < 0 || k >= size()) return NIL_CONST;
            Node * x = select(root, k);
            return x->key;
        }

        int rank(int key) {
            return rank(root, key);
        }

        /*****************************
         * iterator
         * **************************/
        struct BSTIterator {
            Node * ptr;
            BST * tree;

            BSTIterator(Node * _ptr = 0, BST * _tree = 0) : ptr(_ptr), tree(_tree) { }
            
           // don't need to implement copy constuctor and assignemnt operator
           // the defualt behavior suffice. 

            int operator*() const {
                return ptr->key;
            }
            int* operator->() const {
                return &ptr->key;
            }
            
            // pre-incrment operator
            BSTIterator& operator++() {
                ptr = tree->succ(ptr); 
                return *this;
            }
            // post-increment operator
            
            BSTIterator operator++(int) {
                BSTIterator tmp = *this;
                ++*this;
                return tmp;
            }
            bool operator==(const BSTIterator& iter) const {
                return ptr == iter.ptr;
            }
            bool operator!=(const BSTIterator& iter) const {
                return ptr != iter.ptr;
            }
            
        };

        BSTIterator begin() {
            return BSTIterator(min(root));
        } 

        BSTIterator end() {
            return BSTIterator(Nil);
        }


        /*************************
         * for debug
         * **********************/
    private :
        void inorder(Node * x) {
            if (x == Nil) return;
            inorder(x->lc);
            cout << x->key << " ";
            inorder(x->rc);
        }

        void preorder(Node * x) {
            if (x == Nil) return;
            cout << x->key << " ";
            preorder(x->lc);
            preorder(x->rc);
        }

    public :
        void inorder() {
            inorder(root);
        }
        void preorder() {
            preorder(root);
        }
        void putResult() {
            cout << "inorder  : ";
            inorder();
            cout << endl;
            cout << "preorder : ";
            preorder();
            cout << endl;
        }

        friend ostream & operator<<(ostream &os, const BST &tree);
};

ostream  &operator<<(ostream& os, const BST& tree) {
    vector<int> vec;    
    tree.walk(vec);    
    
    os << "[";    
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        if (iter == vec.begin()) os << *iter;
        else os << " " << *iter;
    }
    os << "]";
    return os;
}

