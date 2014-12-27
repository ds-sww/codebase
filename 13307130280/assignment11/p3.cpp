#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

char s[2100];
int son[510][510];
int snum[510];
int a[1100];
int v[1100];
int heap[1100];
int size;

void down(int x)
{
	int i = x;
	int j = (x << 1) + 1;
	while (j < size)
	{
		if (heap[j] > heap[j + 1] &&  j + 1 < size) j++;
		
		if (heap[i] > heap[j])
		{
			int tmp = heap[i];
			heap[i] = heap[j];
			heap[j] = tmp;
			i = j;
			j = (i << 1) + 1;
		}
		else break;
	}
}
void dfs(int x)
{
	printf("(%d",x);
	for (int i = 0; i < snum[x]; i++)
	{
		printf(" ");
		dfs(son[x][i]);
	}
	printf(")");
}
int main()
{
	while (gets(s))
	{
		memset(v,0,sizeof(v));
		memset(son,0,sizeof(son));
		memset(snum,0,sizeof(snum));
		memset(heap,0,sizeof(heap));
		int num = 0;
		
		//number input
		int l = strlen(s);
		if (l == 0)
		{
			printf("(1)\n");
			continue;
		}
		int tmpt = 0;
        for (int i = 0; i <= l; i++)
        {
            if (i == l || s[i] == ' ')
            {
                
                a[num] = tmpt;
                v[a[num]]++;
                num++;
                tmpt = 0;
            }
            else
            {
                tmpt = tmpt * 10 + s[i] - '0';
            }
        }
		
		size = 0;
		for (int i = 1; i <= num + 1; i++)
			if (!v[i])
			{
				heap[size] = i;
				size++;
			}

		for (int i = 0; i < num; i++)
		{
			son[a[i]][snum[a[i]]] = heap[0];
			snum[a[i]]++;
			
			
			v[a[i]]--;
			if (!v[a[i]])
			{
				heap[0] = a[i];
				down(0);
			}
			else
			{
				heap[0] = heap[size - 1];
				size--;
				down(0);
			}
		}
		
		//output
		dfs(a[num - 1]);
		printf("\n");

	}
	return 0;
}
