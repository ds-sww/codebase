#include<iostream>
#include<cstdio>
#include<cstdlib>
struct point
{
    int key,cnt,size,height;
    point *l,*r;
};
typedef point *ppoint;
ppoint null;
inline void update(ppoint &root)
{
    root->size=root->l->size+root->r->size+root->cnt;
    if(root->l->height>root->r->height)
    	root->height=root->l->height+1;
    else
    	root->height=root->r->height+1;
    return;
}
void _add(ppoint &root,int e)
{
    if(root==null)
    {
        root=new point;
        root->key=e;
        root->cnt=root->size=1;
        root->l=root->r=null;
    	update(root);
		return;
    }
    if(e==root->key)
        root->cnt++;
    else
    if(e<root->key)
        _add(root->l,e);
    else
        _add(root->r,e);
    update(root);
    return;
}
int find_k(ppoint &root,int k)
{
	if(root->l->size<k&&k<=root->l->size+root->cnt)
		return root->key;
	if(k<=root->l->size)
		return find_k(root->l,k);
	return find_k(root->r,k-(root->l->size+root->cnt));
}
int find_key(ppoint &root,int e)
{
	if(root==null||root->cnt==0)
		return -1;
	if(e==root->key)
	{
		if(root->l==null)
			return 1; 
		return root->l->size+1;
	}
	if(e<root->key)
		return find_key(root->l,e);
	if(root->key<e)
		return find_key(root->r,e)+root->cnt+root->l->size;
}
void _del(ppoint &root,int e)
{
	if(root==null||root->cnt==0)
		return;
	if(e==root->key)
		root->cnt--;
	if(e<root->key)
		_del(root->l,e);
	if(root->key<e)
		_del(root->r,e);
	update(root);
}
void del_all(ppoint &root)
{
	if(root->l!=null)
		del_all(root->l);
	if(root->l!=null)
		del_all(root->r);
	delete root;
}
class BST
{
	private:
    point *head;
    
    public:
    BST()
    {
    	null=new point;
    	null->l=null->r=null;
    	null->height=0;
    	null->size=0;
        head=null;
    	return;
    }
    ~BST()
    {
	   	del_all(head);
    }
    int size()
    {
        return head->size;
    }
    int min()
    {
    	return find_k(head,1);
	}
	int max()
	{
		return find_k(head,head->size);
	}
    int height()
    {
    	return head->height;
	}
    void add(int e)
    {
   	    _add(head,e);
        return;
    }
    void del(int e)
    {
   	    _del(head,e);
        return;
    }
    int select(int k)
    {
    	return find_k(head,k);
    }
    int rank(int key)
    {
    	return find_key(head,key);
	}
};
int n,a[100001]; 
BST tree;
int main()
{
    int i,j;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(i=n-1;i>=0;i--)
    {
        scanf("%d",&a[i]);
        tree.add(a[i]);
    }
    tree.del(5);
    tree.add(9);
    printf("%d ",tree.height()); 
    for(i=0;i<tree.size();i++)
	printf("%d ",tree.select(i+1)); 
    return 0;
}
