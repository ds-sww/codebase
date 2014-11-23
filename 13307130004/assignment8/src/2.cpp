#include <iostream>
#include <cstdio>
#define N 28
using namespace std;
char preorder[N],inorder[N];
int length;
struct tree
{
	char data;
	tree *left,*right;
};
void build(tree *head,int pl,int pr,int il,int ir){
	int temp;
	for(temp=il;temp<=ir;temp++)
		if(inorder[temp]==preorder[pl])
			break;
	if(temp!=il){
		tree *left=new tree;
		left->data=preorder[pl+1];
		head->left=left;
		build(left,pl+1,pl+temp-il,il,temp-1);
	}
	else
		head->left=NULL;
	if(temp!=ir){
		tree *right=new tree;
		right->data=preorder[pl+temp-il+1];
		head->right=right;
		build(right,pl+temp-il+1,pr,temp+1,ir);
	}
	else
		head->right=NULL;
}
void pos(tree *t){
	if(t!=NULL){
		pos(t->left);
		pos(t->right);
		cout<<t->data;
	}
}
void out(){
	tree tr;
	tr.data=preorder[0];
	build(&tr,0,length-1,0,length-1);
	pos(&tr);
	cout<<endl;
}
int main(){
	while(cin >> preorder)
	{
		cin >> inorder;
		length = 0;
		while(1)
		{
			if(preorder[length] == '\0')
				break;
			length++;
		}
		out();
	}
}
