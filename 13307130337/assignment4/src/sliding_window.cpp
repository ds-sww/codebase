/*
   author: Han Peiru
	 date: 2014.10.23
*/

#include <iostream>
#include <cstdio>
using namespace std;

inline int GetInt()
{  int ret = 0;
	 int neg = 0;
	 char c;
   while (isspace(c = getchar()));
   if(c == '-')
	 { neg = 1;
	   c = getchar();
   }
	 while (isdigit(c))
	 { ret = ret * 10 + (c - '0');
	   c = getchar();
	 }
   if (neg == 1) return -ret;
   else          return ret;
}

struct MonQueue
{ int dt;    //dt is the data stored in a;
	int id;    //id is the index of the data stored in a;
} q[1000050];

int a[1000050];
int maxNum[1000050];
int minNum[1000050];
int n;
int k;

void InIt()
{	cin >> n >> k;
	if (k > n)
	  k = n;

	for (int i=1; i<=n; i++)
	  a[i]=GetInt();

	return;
}

void FindMin()
// by using a montonically increasing queue
{ int head = 1;
	int tail = 1;

	for (int i=1; i<=n; i++)
	{ q[i].dt = 0x7fffffff;
		q[i].id = 0;
  }

	q[1].dt = a[1];
	q[1].id = 1;
	
	for (int i=2; i<=k-1; i++)
	{ while (head <= tail && q[tail].dt >= a[i])
			tail--;

		tail++;
		q[tail].dt = a[i];
		q[tail].id = i;
	}
	
	for(int i=k; i<=n; i++)
	{ while (head <= tail && q[tail].dt >= a[i])
			tail--;
			
		tail++;
		q[tail].dt = a[i];
		q[tail].id = i;
		
		while (head < tail && q[head].id < i-k+1)
			head++;

		minNum[i-k+1] = q[head].dt;
	}
	
	return;
}

void FindMax()
// by using a montonically decreasing queue
{ int head = 1;
	int tail = 1;
	
	for (int i=1; i<=n; i++)
	{ q[i].dt = -0x7fffffff;
		q[i].id = 0;
	}
	
	q[1].dt = a[1];
	q[1].id = 1;

	for (int i=2; i<=k-1; i++)
	{ while (head <= tail && q[tail].dt <= a[i])
			tail--;

		tail++;
		q[tail].dt = a[i];
		q[tail].id = i;
	}

	for(int i=k; i<=n; i++)
	{ while (head <= tail && q[tail].dt <= a[i])
			tail--;

		tail++;
		q[tail].dt = a[i];
		q[tail].id = i;

		while (head < tail && q[head].id < i-k+1)
			head++;

		maxNum[i-k+1] = q[head].dt;
	}
	
	return;
}

void OutIt()
{ for (int i=1; i<=n-k+1; i++)
		printf("%d ", minNum[i]);
	cout<<endl;
	for (int i=1; i<=n-k+1; i++)
		printf("%d ", maxNum[i]);
	return;
}

int main()
{ InIt();
	FindMin();
	FindMax();
	OutIt();
	return 0;
}
