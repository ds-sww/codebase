/*
 * @author whimsycwd
 * @date   2014.10.4
 * 
 * Red Black Tree.   
 * CLRS Chapter 13 Red-Black Trees's implementation
 *
 * key is a integer
 *
*/

#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>


using namespace std;

const static int NIL_CONST = -1;
#define RED 0
#define BLACK 1

class Node {
    public :
        int key;            // node key        
        Node * lc;          // left child
        Node *  rc;         // right child
        Node * p;           // parent
        int color; 
        // this constuctor used by Nil
        Node(int _key) : key(_key), lc(0), rc(0), p(0),color(BLACK)  {
        }
       
};


// Nil.parent we can't set it arbitrarily.. It's used by deletion. 
// for example 
// if we set Nil.parent to other value during `delete_fix` 
// it disable the travase up
static Node * Nil = new Node(NIL_CONST);   // sentinel

struct RBTreeIterator;

class RBTree {
    
    public :
        typedef RBTreeIterator         iterator;
    private :
        Node * root;
    


        Node * makeNode(int key) {
            Node * retValue = new Node(key);
            retValue->lc = Nil;
            retValue->rc = Nil;
            retValue->p = Nil;
            retValue->color = RED;
            return retValue;
        }

        // CLRS P.316
        void insert_fixup(Node *z) {
            while (z->p->color == RED) {
                if (z->p == z->p->p->lc) {
                    auto y = z->p->p->rc;
                    if (y->color == RED) {
                        z->p->color = BLACK;
                        y->color = BLACK;
                        z->p->p->color = RED;
                        z = z->p->p;
                    }  else { 
                        if (z == z->p->rc) {
                            z = z->p;
                            left_rotate(z);
                        } 
                        z->p->color = BLACK;
                        z->p->p->color = RED;
                        right_rotate(z->p->p);
                    }
                } else {
                    auto y = z->p->p->lc;
                    if (y->color == RED) {
                        z->p->color = BLACK;
                        y->color = BLACK;
                        z->p->p->color = RED;
                        z = z->p->p;
                    } else {
                        if (z == z->p->lc) {
                            z = z->p;
                            right_rotate(z);
                        }
                        z->p->color = BLACK;
                        z->p->p->color = RED;
                        left_rotate(z->p->p);
                    }
                }
            }
            root->color = BLACK;
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
            
            // color has been set in `makeNode`, it's red. 
            insert_fixup(z); 
        }

        //  Note that TRANSPLANT does not attemp to update v.left 
        //  and v.right; doing so, or not doing so, is the responsibility
        //  of TRANSPLANT's caller
        void transplant(Node * u, Node * v) {
            if      (u->p == Nil)       root = v; 
            else if (u == u->p->lc)     u->p->lc = v;
            else                        u->p->rc = v;

            v->p = u->p;
        }

        void delete_fixup(Node * x) {
            while (x != root && x->color == BLACK) {
                if (x == x->p->lc) {
                    auto w = x->p->rc;
                    // printf("b w: %d\n", w->key); 
                    //  Case 1: x’s sibling w is red
                    if (w->color == RED) {
                        w->color = BLACK;
                        x->p->color = RED;
                        left_rotate(x->p);
                        w = x->p->rc;
                    }
                    
                    //  Case 2: x’s sibling w is black, 
                    //  and both of w’s children are black
                    if (w->lc->color == BLACK && w->rc->color == BLACK) {
                        w->color = RED;
                        x = x->p;
                    } 
                    else {
                        // Case 3: x’s sibling w is black, w’s left child is red, 
                        // and w’s right child is black
                        if (w->rc->color == BLACK) {
                            w->lc->color = BLACK;
                            w->color = RED;
                            // printf("before ratate %d  w->key %d, w->lc->key %d, x->p->key %d  w->p->key %d\n",
                            //        x->p->rc->key, w->key, w->lc->key, x->p->key, w->p->key);

                            right_rotate(w);
                            // printf("after rotate %d\n", x->p->rc->key);
                            w = x->p->rc;
                        } 
                        // Case 4: x’s sibling w is black, 
                        // and w’s right child is red
                        
                        // printf("x : %d, w : %d\n", x->key, w->key);
                        w->color = x->p->color;
                        x->p->color = BLACK;
                        w->rc->color = BLACK;
                        left_rotate(x->p);
                        x = root;
                    }

                } else {

                    // it's symmetrical, use child[0] for lc, child[1] for rc. we can unify this procedure to reduce code.
                    // but it will make code unreadiable.
                    auto w = x->p->lc;
                    // printf("w->key %d, x->p->key %d\n", w->key, x->p->key);
                    if (w->color == RED) {
                        w->color = BLACK;
                        x->p->color = RED;
                        right_rotate(x->p);
                        w = x->p->lc;
                    }
                    if (w->lc->color == BLACK && w->rc->color == BLACK) {
                        w->color = RED;
                        x = x->p;
                    } else {
                        if (w->lc->color ==  BLACK) {
                            w->rc->color = BLACK;
                            w->color = RED;
                            left_rotate(w);
                            w = x->p->lc;    
                        }
                    
                        w->color = x->p->color;
                        x->p->color = BLACK;
                        w->lc->color = BLACK;
                        right_rotate(x->p);
                        x = root;
                    }
                }
            }
            x->color = BLACK; 
        }

        void del(Node * z) {
            auto y = z;
            int y_original_color = y->color;
            Node * x;
            if (z->lc == Nil) {
                x = z->rc;
                transplant(z, z->rc);
            }
            else if (z->rc == Nil) {
                x = z->lc;
                transplant(z, z->lc);
            }
            else {
                auto y = min(z->rc);
                y_original_color = y->color;
                x = y->rc;

                if (y->p != z) {
                    transplant(y, y->rc);
                    y->rc = z->rc;
                    y->rc->p = y;

                } else  {
                    // confused? CLRS v3 P.325
                    // Since node x moves into node y’s original position, 
                    // the attribute x:p is always set to point to the original position in the tree of y’s parent,
                    // ** even if x is, in fact, the sentinel T:nil**.
                    // @comment this line aim to temporily make Nil.p point to right parent when we call `delete_fixup`
                    x->p = y;              
                }
                transplant(z, y);
                y->lc = z->lc;
                y->lc->p = y;
                y->color = z->color;

            }
            // printf("x->p %d\n", x->p->key); 
            // we need to make sure x->p is set properly.
            if (y_original_color == BLACK) 
                delete_fixup(x);

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
        

        int height(Node * x) {
            if (x == Nil) return 0;
            return std::max(height(x->lc), height(x->rc)) + 1;
        }

        void left_rotate(Node * x) {
            auto y = x->rc;                             // set y
            x->rc = y->lc;                              // turn y's left substree into x's right subtree
            
            if (y->lc != Nil) 
                y->lc->p = x;           // important! trap >_<, we can't set Nil.parent.. It's used by deletion to travse up
            y->p = x->p;                                // link x's parent to y
            if      (x->p == Nil)       root = y;
            else if (x == x->p->lc)     x->p->lc = y;
            else                        x->p->rc = y;
        
            y->lc = x;                                  // put x on y's left
            x->p = y;
        }
        void right_rotate(Node * x) {
            auto y = x->lc;
            x->lc = y->rc;
            
            if (y->rc != Nil) 
                y->rc->p = x;           // important! trap >_<, we can't set Nil.parent.. It's used by deletion to travse up
            y->p = x->p;
            if      (x->p == Nil)       root = y;
            else if (x == x->p->lc)     x->p->lc = y;
            else                        x->p->rc = y;
        
            y->rc = x;
            x->p = y;
        }

    public : 
        RBTree() {
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
        
        int height() {
            return height(root);
        }


        /*****************************
         * iterator
         * **************************/
        struct RBTreeIterator {
            Node * ptr;
            RBTree * tree;

            RBTreeIterator(Node * _ptr = 0, RBTree * _tree = 0) : ptr(_ptr), tree(_tree) { }
            
           // don't need to implement copy constuctor and assignemnt operator
           // the defualt behavior suffice. 

            int operator*() const {
                return ptr->key;
            }
            int* operator->() const {
                return &ptr->key;
            }
            
            // pre-incrment operator
            RBTreeIterator& operator++() {
                ptr = tree->succ(ptr); 
                return *this;
            }
            // post-increment operator
            
            RBTreeIterator operator++(int) {
                RBTreeIterator tmp = *this;
                ++*this;
                return tmp;
            }
            bool operator==(const RBTreeIterator& iter) const {
                return ptr == iter.ptr;
            }
            bool operator!=(const RBTreeIterator& iter) const {
                return ptr != iter.ptr;
            }
            
        };

        RBTreeIterator begin() {
            return RBTreeIterator(min(root));
        } 

        RBTreeIterator end() {
            return RBTreeIterator(Nil);
        }


        /*************************
         * for debug
         * **********************/
    private :
        void inorder(Node * x) {
            if (x == Nil) return;
            inorder(x->lc);
            cout << x->key<<","<<x->color << " ";
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

        friend ostream & operator<<(ostream &os, const RBTree &tree);
};

ostream  &operator<<(ostream& os, const RBTree& tree) {
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

