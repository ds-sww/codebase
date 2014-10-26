/*
	 author: Han Peiru
	 date: 2014.10.21
	 This version can get the right answer
	 but will exceed the time limit
*/

#include<iostream>
#include<cstdio>

using namespace std;

inline long long GetInt()
{
  long long ret = 0;
  int neg = 0;
  char c;
  while (isspace(c = getchar()));
  if (c == '-')
  {
	  neg = 1;
	  c = getchar();
  }
  while (isdigit(c))
  {
	  ret = ret * 10 + (c - '0');
    c = getchar();
  }
  if (neg == 1) return -ret;
  else          return ret;
}

long long h[1000050]; 
int l[1000050]; // l is the left link
int r[1000050]; // r is the right link
int n;



long long FindMaxSize()
{
  long long maxSize = 0;
  long long tempSize;
  int tempWidth;

	for (int i=1; i<=n; i++)
	{ l[i] = i;
		r[i] = i;
	}

	for (int i=2; i<=n; i++)
	{ while (h[l[i] - 1] >= h[i])
		  l[i] = l[l[i] - 1];
  }

	for (int i=n-1; i>=1; i--)
	{ while (h[r[i] + 1] >= h[i])
			r[i] = r[r[i] + 1];
	}

	for (int i=1; i<=n; i++)
	{ tempWidth = r[i] - l[i] + 1;
		tempSize = tempWidth * h[i];
    if (maxSize < tempSize) maxSize = tempSize;
	}
  return maxSize;
}

int main()
{
  while (1)
	{
	  scanf("%d", &n);
		if (n == 0) break;

		for (int i = 1; i <= n; i++)
			h[i] = GetInt();

		printf("%lld\n", FindMaxSize());
	}
	
	return 0;
}
