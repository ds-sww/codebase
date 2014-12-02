#include <iostream>

using namespace std;

int space_cnt;
int n;

class Node{
public:
    Node()  {   lchild=NULL; data=0; rchild=NULL; }
    Node *lchild;
    int data;
    Node *rchild;
};

void preord_traversal(Node *t){
    if(t!=NULL){
        cout<<t->data;
        if(space_cnt!=n-1){
         cout<<" ";
         space_cnt++;
        }
        preord_traversal(t->lchild);
        preord_traversal(t->rchild);
    }
}

int main()
{
    while(cin>>n&&n!=0){
      Node *tree=new Node[n+1];
      for (int i=1; i<n+1;++i){
            tree[i].data=i;
            if(i*2<=n){
                tree[i].lchild=&tree[i*2];
                if(i*2+1<=n)
                    tree[i].rchild=&tree[i*2+1];
            }
        }
        space_cnt=0;
    preord_traversal(&tree[1]);
    cout<<endl;
    }
    return 0;
}
