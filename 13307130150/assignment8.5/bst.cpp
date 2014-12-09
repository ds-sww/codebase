//用class写感觉各种bug，后来看了TA代码觉得自己很多地方姿势不太好，不过不想整了，RedBlacktree注意了很多
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class Node{
public:
	int data,size;
	Node *rc;
	Node *lc;
	Node *pa;

	Node(int key) {
		data = key;
		size = 0;
		lc = NULL;
		rc = NULL;
		pa = NULL;
	}
};
static Node *Nil = new Node(-1);  //设置一个虚拟的结束哨兵
class BST{
private:
	Node *root;

	void fixsize(Node* x)   //维护一个size在select和rank中都很有帮助
	{
		while (x != Nil)
		{
			x->size = x->lc->size + x->rc->size + 1;
			x = x->pa;
		}
	}
	int high(Node* x)
	{
		if (x == Nil)
			return 0;
		else
			return max(high(x->lc),high(x->rc))+1;  
	}

	void prev(Node* x)
	{
		if (x == Nil) return;
		cout << x->data << ' ';
		prev(x->lc);
		prev(x->rc);
	}

	void infix(Node* x)
	{
		if (x == Nil) return;
		infix(x->lc);
		cout << x->data << ' ';
		infix(x->rc);
	}

	void post(Node* x)
	{
		if (x == Nil) return;
		post(x->lc);
		post(x->rc);
		cout << x->data << ' ';
	}

	Node* delnode(Node* x)
	{
		if (x->lc != Nil)
		{
			Node* p = x->lc;
			while (p->rc != Nil)
				p = p->rc;
			if (p->pa == x)
			{
				p->rc = x->rc;
				x->rc->pa = p;
			}
			else
			{
				Node* y = p->pa;
				p->pa->rc = p->lc;
				x->lc->pa = x->rc->pa = p;
				p->lc = x->lc;
				p->rc = x->rc;

				p->pa = Nil;
				fixsize(y);
			}
			return p;
		}
		else
		{
			Node* p = x->rc;
			return p;
		}
	}

	Node* selectnode(Node* x,int k)
	{
		int t = x->lc->size+1;
		if (k < t) return selectnode(x->lc,k);
		else
			if (k > t) return selectnode(x->rc,k-t);
			else return x;
	}

	int ranknode(Node* x,int key)
	{
		if (x == Nil) return 0;
		if (x->data > key) return ranknode(x->lc,key);
		else
			if (x->data < key) return 1+x->lc->size+ranknode(x->rc,key);
			else return x->lc->size+1;
	}
public:
	BST()
	{
		Nil->lc = Nil->rc = Nil->pa = Nil;  //Nil 的所有值都指回自身
		root = Nil;
	}
	void add(int key)
	{
		Node *x = root,*y = Nil;
		Node *z = new Node(key);
		z->lc = z->rc = Nil;
		while (x != Nil)
		{
			y = x;  //record parent
			if (key > x->data) x = x->rc;
			else 
				if (key < x->data) x = x->lc;
				else return; // exist in the tree
		}
		z->pa = y;

		if (y == Nil) root = z;
		else
		{
			if (key < y->data) y->lc = z;
			else y->rc = z;
		}
		fixsize(z);
	}
	int getmin()    //用min，max不太好吧，还要考虑作用域
	{
		Node *x = root;
		while (x->lc != Nil) 
			x = x->lc;
		if (x != Nil)
			return x->data;
		else
			return -1;
	}
	int getmax()
	{
		Node *x = root;
		while (x->rc != Nil) 
			x = x->rc;
		if (x != Nil)
			return x->data;
		else 
			return -1;
	}
	//助教代码上面三个写进private，感觉比较好，不过就这题来讲好像无所谓吧

	int size()
	{
		return root->size;
	}

	int height()
	{
		return high(root);
	}

	//遍历
	void prevorder()
	{
		prev(root);
		cout << endl;
	}

	void inorder()
	{
		infix(root);
		cout << endl;
	}

	void postorder()
	{
		post(root);
		cout << endl;
	}

	void del(int key)
	{
		Node* x = root;
		while (x != Nil)
			if (key < x->data) x = x->lc;
			else 
				if (key > x->data) x = x->rc;
				else break;
		if (x != Nil)
		{
			Node* sub = delnode(x);
			sub->pa = x->pa;
			if (x->pa->lc == x) x->pa->lc = sub;
			else x->pa->rc = sub;
			free(x);
			fixsize(sub);
		}
	}

	int select(int k)
	{
		if (k <= 0 || k > size()) return -1;
		Node* x = selectnode(root,k);
		return x->data;
	}

	int rank(int key)
	{
		return ranknode(root,key);
	}
};
int main()
{
	BST test;
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		test.add(x);
	}

	cout << test.getmin();
	cout << test.getmax();
	cout << test.height();
	test.prevorder();
	test.inorder();
	test.postorder();
	int x;
	cin >> x;
	test.del(x);
	//test.inorder();
	cout << test.size() << endl;
	for (int i=0; i<3; i++)
	{
		cin >> x;
		cout << test.rank(x) << endl;
	}
}