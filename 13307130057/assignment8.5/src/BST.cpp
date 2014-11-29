#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
class Node
{
friend class search_tree;
private:
	int data;
	Node *left,*right;
};
class search_tree
{
private:
	Node *root;
	int length;
	void create(int a[],int l,int r,Node *x)
	{
		int i=(l+r)/2;
		x->data=a[i];
		if (l<i) 
		{
			x->left=new Node();
			create(a,l,i-1,x->left);
		}
		else x->left=NULL;
		if (i<r)
		{
			x->right=new Node();
			create(a,i+1,r,x->right);
		}
		else x->right=NULL;
	}
	int Size(Node *x)
	{
		if (x==NULL) return 0;
		return Size(x->left)+Size(x->right)+1;
	}
	void Preorder(Node *x)
	{
		cout<<x->data<<' ';
		if (x->left) Preorder(x->left);
		if (x->right) Preorder(x->right);
	}
	void Inorder(Node *x)
	{
		if (x->left) Inorder(x->left);
		cout<<x->data<<' ';
		if (x->right) Inorder(x->right);
	}
	void Postorder(Node *x)
	{
		if (x->left) Postorder(x->left);
		if (x->right) Postorder(x->right);
		cout<<x->data<<' ';
	}
	void Levorder()
	{
		Node *a[1000];
		int top=1;
		a[0]=root;
		for (int i=0;i<length;i++)
		{
			cout<<a[i]->data<<endl;
			if (a[i]->left) a[top++]=a[i]->left;
			if (a[i]->right) a[top++]=a[i]->right;
		}
		delete []*a;
	}
	void Add(Node *x,int key)
	{
		if (length==0)
		{
			root=new Node();
			root->data=key;
			root->left=NULL;root->right=NULL;
			length=1;
		}
		if (key<=x->data) 
			if (x->left) Add(x->left,key);
			else 
			{
				Node *p=new Node();
				p->data=key;
				p->left=NULL;p->right=NULL;
				x->left=p;
				length++;
			}
		else
			if (x->right) Add(x->right,key);
			else
			{
				Node *p=new Node();
				p->data=key;
				p->left=NULL;p->right=NULL;
				x->right=p;
				length++;
			}
	}
	int Del(Node *x,int key,Node *y,int t)
	{
		if (x->data==key)
		{
			if (length==1)
			{
				delete root;
				return -1;
			}
			if (x->right)
			{
				Node *p=x->right;
				if (p->left) 
				{
					Node *q=p;
					while (p->left) p=p->left;
					while (q->left->left) q=q->left;
					x->data=p->data;
					q->left=p->right;
					delete p;
				}
				else
				{
					x->data=p->data;
					x->right=p->right;
					delete p;
				}
			}
			else
			{
				if (t==1) y->left=x->left;
				else y->right=x->left;
				delete x;
			}
			return Size(y);
		}
		else 
		{
			if ((x->data>key)&&(x->left)) return Del(x->left,key,x,1);
			else if ((x->data<key)&&(x->right)) return Del(x->right,key,x,2);
			else 
			{
				cout<<"Not found!"<<endl;
				return 0;
			}
		}
	}
public:
	search_tree(int size)
	{
		assert(size>=0);
		if (size==0) 
		{
			root=NULL;
			length=0;
		}
		else
		{
			int *a=new int[size];
			for (int i=0;i<size;i++)
				cin>>a[i];
			sort(a,a+size);
			root=new Node();
			create(a,0,size-1,root);
			delete []a;
			length=Size(root);
		}
	}
	bool empty() const
	{
		return length==0;
	}
	int size()
	{
		return length;
	}
	int min()
	{
		Node *p=root;
		while (p->left) p=p->left;
		return p->data;
	}
	int max()
	{
		Node *p=root;
		while (p->right) p=p->right;
		return p->data;
	}
	int height()
	{
		return (int)(log(length)/log(2));
	}
	void preorder()
	{
		Preorder(root);
	}
	void inorder()
	{
		Inorder(root);
	}
	void postorder()
	{
		Postorder(root);
	}
	void levorder()
	{
		Levorder();
	}
	void add(int key)
	{
		Add(root,key);
	}
	void del(int key)
	{
		if (Del(root,key,NULL,0)) length--;
	}
};
int main()
{
	int n;
	cin>>n;
	search_tree tree(n);
	if (!tree.empty()) tree.inorder();
	return 0;
}