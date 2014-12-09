#include <iostream>
using namespace std;
class Node{
public:
	char color;
	int data,size;
	Node* lc;
	Node* rc;
	Node* pa;

	Node(int key,char ch)
	{
		data = key;
		color = ch;
		size = 0;
		lc = NULL;
		rc = NULL;
		pa = NULL;
	}
};
static Node *Nil = new Node(-1,'B'); // nil black

class RBT{
private:
	Node* root;

	Node* makenode(int key)
	{
		Node* x = new Node(key,'R'); // initial Red
		x->lc = x->rc = x->pa = Nil;
		return x;
	}
	
	void fixsize(Node* x)   //维护size
	{
		while (x != Nil)
		{
			x->size = x->lc->size + x->rc->size + 1;
			x = x->pa;
		}
	}
	void upsize(Node* x)
	{
		x->size = x->lc->size + x->rc->size + 1;
	}

	void leftrotate(Node* x)
	{
		Node* y = x->rc;
		x->rc = y->lc;
		if (y->lc != Nil)
			y->lc->pa = x;
		y->pa = x->pa; // new subtree connect to root

		if (x->pa == Nil)
			root = y;
		else
		{
			if (x == x->pa->lc)
				x->pa->lc = y;
			else
				x->pa->rc = y;
		}
		y->lc = x;
		x->pa = y;
		
		upsize(x);
		upsize(y);
	}
	void rightrotate(Node* x)
	{
		Node* y = x->lc;
		x->lc = y->rc;
		if (y->rc != Nil)
			y->rc->pa = x;
		y->pa = x->pa; // new subtree connect to root

		if (x->pa == Nil)
			root = y;
		else
		{
			if (x == x->pa->lc)
				x->pa->lc = y;
			else
				x->pa->rc = y;
		}
		y->rc = x;
		x->pa = y;

		upsize(x);
		upsize(y);
	}
	void RBinsertfixup(Node* z)
	{
		while (z->pa->color == 'R')  //R-R need to fix up
		{
			if (z->pa == z->pa->pa->lc) // left three situations
			{
				Node* tmp = z->pa->pa->rc; // tmp is uncle node
				if (tmp->color == 'R') //situation 1 颜色翻一下
				{
					z->pa->pa->color = 'R';
					z->pa->color = 'B';
					tmp->color = 'B';
					z = z->pa->pa; // subtree is ok
				}
				else  // situation 2&3
				{
					if (z == z->pa->rc)
					{
						z = z->pa;
						leftrotate(z); // rotate situtation 2 to 3
					}
					z->pa->color = 'B';
					z->pa->pa->color = 'R';
					rightrotate(z->pa->pa);   //做完这次rotate之后就满足RBT的定义，不用再做了，所以RBT最多旋转两次= =
				}
			}
			else                              //right three situation
			{
				Node* tmp = z->pa->pa->lc; // tmp is uncle node
				if (tmp->color == 'R') //situation 1 颜色翻一下
				{
					z->pa->pa->color = 'R';
					z->pa->color = 'B';
					tmp->color = 'B';
					z = z->pa->pa; // subtree is ok
				}
				else  // situation 2&3
				{
					if (z == z->pa->lc)
					{
						z = z->pa;
						rightrotate(z); // rotate situtation 2 to 3
					}
					z->pa->color = 'B';
					z->pa->pa->color = 'R';
					leftrotate(z->pa->pa);
				}
			}
		}
		root->color = 'B'; // if tree is empty
	}
	void RBinsert(Node* z)
	{
		Node* x = root, *y = Nil;
		while (x != Nil)
		{
			y = x;
			if (z->data < x->data) x = x->lc;
			else
				if (z->data > x->data) x = x->rc;
				else return; //exist 
		}
		z->pa = y;
		if (y == Nil) root = z; // tree is empty
		else
		{
			if (z->data < y->data) y->lc = z;
			else y->rc = z;
		}

		fixsize(z);
		RBinsertfixup(z);
	}

	Node* successor(Node* z)
	{
		Node* x = z->rc;
		while (x->lc != Nil)
			x = x->lc;
		return x;
	}
	void RBdelfix(Node* x)
	{
		while (x != root && x->color == 'B')
		{
			if (x == x->pa->lc)
			{
				Node* tmp = x->pa->rc; // tmp is the brother of x
				if (tmp->color == 'R') // case 1
				{
					tmp->color = 'B';
					x->pa->color = 'R';
					leftrotate(x->pa);
					tmp = x->pa->rc;
				}
				if (tmp->lc->color == 'B' && tmp->rc->color == 'B') // case 2
				{
					tmp->color = 'R';
					x = x->pa; // 相当于把tmp的黑色和x的二重黑色抹去，然后移到了x的pa上
				}
				else
				{
					if (tmp->rc->color == 'B') // case 3
					{
						tmp->lc->color = 'B';
						tmp->color = 'R';
						rightrotate(tmp);
						tmp = x->pa->rc;
					}
					// case 4
					tmp->color = x->pa->color;
					tmp->rc->color = 'B';
					x->pa->color = 'B';
					leftrotate(x->pa);
					x = root; //结束循环，这里x的双重黑色已被他的父亲吸收掉了，也是至多旋转3次的高效原因
				}
			}
			else
			{
				Node* tmp = x->pa->lc; // tmp is the brother of x
				if (tmp->color == 'R') // case 1
				{
					tmp->color = 'B';
					x->pa->color = 'R';
					rightrotate(x->pa);
					tmp = x->pa->lc;
				}
				if (tmp->lc->color == 'B' && tmp->rc->color == 'B') // case 2
				{
					tmp->color = 'R';
					x = x->pa; // 相当于把tmp的黑色和x的二重黑色抹去，然后移到了x的pa上
				}
				else
				{
					if (tmp->lc->color == 'B') // case 3
					{
						tmp->rc->color = 'B';
						tmp->color = 'R';
						leftrotate(tmp);
						tmp = x->pa->lc;
					}
					// case 4
					tmp->color = x->pa->color;
					tmp->lc->color = 'B';
					x->pa->color = 'B';
					rightrotate(x->pa);
					x = root; //结束循环，这里x的双重黑色已被他的父亲吸收掉了，也是至多旋转3次的高效原因
				}
			}
		}
		x->color = 'B'; // 找到红节点吸收x的双重黑色
	}

	void RBdelete(Node* z)
	{
		Node *y, *x;
		if (z->lc == Nil || z->rc == Nil)
			y = z;
		else y = successor(z); // 把z的后继删掉，然后z的值替换为z的后继
		if (y->lc != Nil)
			x = y->lc;
		else  x = y->rc;
		//if (x != Nil)  这里看算导 一开始没懂。。为啥要无条件赋值，因为fixup的时候是把x传进去的
		//单纯的删除会改变黑高度，而把y的黑色加到x上，然后不断调整，直到红色的x，把它染黑
		x->pa = y->pa;
		if (y->pa == Nil)
			root = x;
		else
		{
			if (y == y->pa->lc)
				y->pa->lc = x;
			else y->pa->rc = x; // delete y
		}
		if (y != z)
			z->data = y->data; // 替换为后继的值

		fixsize(y->pa);

		if (y->color == 'B')
			RBdelfix(x);  
	}

	Node* TreeMin(Node* x)
	{
		while (x->lc != Nil)
			x = x->lc;
		return x;
	}
	Node* TreeMax(Node* x)
	{
		while (x->rc != Nil)
			x = x->rc;
		return x;
	}
	void prev(Node* x)
	{
		if (x == Nil) return;
		cout << x->data << x->color << ' ';
		prev(x->lc);
		prev(x->rc);
	}

	void infix(Node* x)
	{
		if (x == Nil) return;
		infix(x->lc);
		cout << x->data << x->color << ' ';
		infix(x->rc);
	}

	void post(Node* x)
	{
		if (x == Nil) return;
		post(x->lc);
		post(x->rc);
		cout << x->data << x->color << ' ';
	}

	Node* search(int key)
	{
		Node* x = root;
		while (x != Nil)
		{
			if (key < x->data) x = x->lc;
			else
				if (key > x->data) x = x->rc;
				else return x;
		}
		return Nil;
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
	RBT(){
		root = Nil;
	}
	void RBadd(int key)
	{
		Node* z = makenode(key);
		RBinsert(z);
	}

	void RBdel(int key)
	{
		Node* z = search(key);
		RBdelete(z);
	}

	int getmin()   
	{
		return TreeMin(root)->data;
	}
	int getmax()
	{
		return TreeMax(root)->data;
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
	int size()
	{
		return root->size;
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
	RBT test;
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		test.RBadd(x);
	}
	cout << test.size() << endl;
	int x;
	cin >> x;
	test.RBdel(x);
	cout << test.size() << endl;
	cout << test.getmax() << endl;
	cout << test.getmin() << endl;
	test.inorder();
	test.prevorder();
	cin >> x;
	cout << test.select(x) << endl;
	cin >> x;
	cout << test.rank(x) << endl;
}