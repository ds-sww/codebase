#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 1111111
#define RED 0
#define BLACK 1
#define nil 0
using namespace std;
int n, m,id,value, root, tot, lefts[maxn], rights[maxn], fa[maxn], key[maxn], color[maxn], bh[maxn],size[maxn];
void init()
{
	root = 0;
	lefts[nil] = rights[nil] = nil;
	fa[nil] = nil; //father of the node
	color[nil] = BLACK;
	size[nil] = 0;
	bh[nil] = 1;
}
void update(int x)
{
	if (x == nil) return;
	size[x] = size[lefts[x]] + size[rights[x]] + 1;
}
void LR(int x)
{
	int y = rights[x];
	rights[x] = lefts[y];
	if (lefts[y] != nil) fa[lefts[y]] = x;
	fa[y] = fa[x];
	if (fa[x] == nil) root = y; //no one node points to y
	else if (x == lefts[fa[x]]) lefts[fa[x]] = y;
	else rights[fa[x]] = y;
	fa[x] = y;
	lefts[y] = x;
	update(x);
	update(y);
}
void RR(int x)
{
	int y = lefts[x];
	lefts[x] = rights[y];
	if (rights[y] != nil) fa[rights[y]] = x;
	fa[y] = fa[x];
	if (fa[x] == nil) root = y; //no one node points to y
	else if (x == lefts[fa[x]]) lefts[fa[x]] = y;
	else rights[fa[x]] = y;
	fa[x] = y;
	rights[y] = x;
	update(x);
	update(y);
}
void insertfixup(int z)
{
	while (color[fa[z]] == RED) // fa[z] cannot be the root since color[root]=BLACK always;
	{
		if (fa[z] == lefts[fa[fa[z]]])
		{
			int w = rights[fa[fa[z]]];
			if (color[w] == RED)
			{
				color[fa[z]] = color[w] = BLACK;
				color[fa[fa[z]]] = RED;
				z = fa[fa[z]]; //color[z]=RED; only this case changes the value of z
			}
			else //color[w]==BLACK;
			{
				if (z == rights[fa[z]]) { z = fa[z]; LR(z); } //leftsrotate(z)   so that z==lefts[fa[z]] 
				color[fa[z]] = BLACK;
				color[fa[fa[z]]] = RED;
				RR(fa[fa[z]]);    //once it is implementated it will break out of the while loop 
				//so there are at most two rotatation LR & RR	
			}
		}
		else //fa[z]==rights[fa[fa[z]]]
		{
			int w = lefts[fa[fa[z]]];
			if (color[w] == RED)
			{
				color[fa[z]] = color[w] = BLACK;
				color[fa[fa[z]]] = RED;
				z = fa[fa[z]]; //color[z]=RED;
			}
			else //color[w]==BLACK
			{
				if (z == lefts[fa[z]]) { z = fa[z]; RR(z); }
				color[fa[z]] = BLACK;
				color[fa[fa[z]]] = RED;
				LR(fa[fa[z]]);
			}
		}
	}
	color[root] = BLACK; //maintain ROOT BLACK
}
void insert(int v)
{
	int y = nil;
	int x = root;
	while (x != nil)
	{
		size[x]++;
		y = x;
		if (v < key[x]) x = lefts[x]; else x = rights[x];
	}
	fa[++tot] = y; lefts[tot] = rights[tot] = nil;;
	key[tot] = v; size[tot] = 1;
	if (y == nil) root = tot;
	else if (v < key[y]) lefts[y] = tot; else rights[y] = tot;
	color[tot] = RED; //red 
	insertfixup(tot);
}
int findmin(int x)
{
	while (lefts[x] != nil) x = lefts[x];
	return x;
}
int succ(int x)
{
	if (rights[x] != nil) return findmin(rights[x]);
	int y = fa[x];
	while (y != nil && x == rights[y])
	{
		x = y;
		y = fa[y];
	}
	return y;
}
void deletesfixup(int z)
{
	while (z != root && color[z] == BLACK) //REDBLACK || BLACKBLACK EXIT
	{
		if (z == lefts[fa[z]])
		{
			int w = rights[fa[z]];
			if (color[w] == RED)
			{
				color[fa[z]] = RED;
				color[w] = BLACK;
				LR(fa[z]); //turns into case 2
				w = rights[fa[z]];
			}			
			if (color[lefts[w]] == BLACK && color[rights[w]] == BLACK)
			{				
				color[w] = RED;
				z = fa[z];
			}
			else
			{
				if (color[rights[w]] == BLACK) //RED BLACK  
				{
					color[lefts[w]] = BLACK;
					color[w] = RED; 
					RR(w); //turns into case 4
					w = rights[fa[z]]; 
				}
				//RIGHT RED
				color[w] = color[fa[z]];
				color[fa[z]] = BLACK;
				color[rights[w]] = BLACK;
				LR(fa[z]);
				z = root;
			}
		}
		else //z==rights[fa[z]]
		{
			int w = lefts[fa[z]];
			if (color[w] == RED)
			{
				color[fa[z]] = RED;
				color[w] = BLACK;
				RR(fa[z]); //turns into case 2
				w = lefts[fa[z]];
			}
			if (color[lefts[w]] == BLACK && color[rights[w]] == BLACK)
			{
				color[z] = BLACK;
				color[w] = RED;
				z = fa[z];
			}
			else
			{
				if (color[lefts[w]] == BLACK) //RED BLACK  
				{
					color[rights[w]] = BLACK;
     				color[w] = RED;
					LR(w); //turns into case 4
					w = lefts[fa[z]];
				}
				//LEFT RED
				color[w] = color[fa[z]];
				color[fa[z]] = BLACK;
				color[lefts[w]] = BLACK;
				RR(fa[z]);
				z = root;
			}
		}
	}
	color[z] = BLACK;
}
void deletes(int z)
{
	int y;
	if (lefts[z] == nil || rights[z] == nil) y = z;
	else y = succ(z);
	int x;
	if (lefts[y] != nil) x = lefts[y]; else x = rights[y];
	fa[x] = fa[y];
	if (fa[y] == nil) root = x;
		else if (y == lefts[fa[y]]) lefts[fa[y]] = x; 
				else rights[fa[y]] = x;
	if (y != z) key[z] = key[y];
	int p = fa[x];
	while (p != nil) { size[p]--; p = fa[p]; }
	if (color[y] == BLACK) deletesfixup(x);
}
int getKth(int x, int now)
{
	if (size[lefts[x]] >= now) return getKth(lefts[x], now);
	if (size[lefts[x]] + 1 == now) return x;
	return getKth(rights[x], now - size[lefts[x]] - 1);
}
int main()
{
//	freopen("RBT.in", "r", stdin);
//        freopen("RBT.out", "w", stdout);
	init();
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value);
		insert(value);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &id);
		deletes(getKth(root,id));
	}
	return 0;
}
