#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int step;
string preorder,inorder;
struct Tree
{
	char name;
	int lchild,rchild;
}tree[30];
void create(int l,int r,int mark)
{
	int x;
	step++;
	for (int i=l;i<=r;i++)
		if (preorder[step]==inorder[i]) 
		{
			x=i;break;
		}
	tree[x].name=preorder[step];
	if (step)
	{
		if (mark==1) tree[r+1].lchild=x;
		else tree[l-1].rchild=x;
	}
	if (l<x) create(l,x-1,1);
	else tree[x].lchild=-1;
	if (x<r) create(x+1,r,2);
	else tree[x].rchild=-1;
}
void postorder(int x)
{
	if (tree[x].lchild!=-1) postorder(tree[x].lchild);
	if (tree[x].rchild!=-1) postorder(tree[x].rchild);
	cout<<tree[x].name;
}
int main()
{
	while (cin>>preorder>>inorder)
	{
		step=-1;
		create(0,preorder.length()-1,0);
		for (int i=0;i<preorder.length();i++)
			if (preorder[0]==inorder[i])
			{
				postorder(i);
				break;
			}
		cout<<endl;
	}
	return 0;
}