/*
   author: Han Peiru
	 date: 2014.10.26
	 This version uses the montonic queue and is Accepted on the OJ
*/

#include <iostream>
#include <cstdio>
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
int q[1000050];
// q is a montonic queue which sotres the index of height
int leftWidth[1000050];
int rightWidth[1000050];
int n;

void FindLeft()
{
  int head = 1;
	int tail = 1;
	
	q[0] = 0;
	q[1] = 1;
	leftWidth[1] = 0;
	
	for (int i=2; i<=n; i++)
	{
	   while (head <= tail && h[i] <= h[q[tail]])
	   {
		   tail--;
     }
     
		 leftWidth[i] = i - q[tail] - 1;
		 tail++;
		 q[tail] = i;
  }
}

void FindRight()
{
  int head = 1;
	int tail = 1;
	
	q[0] = n + 1;
	q[1] = n;
	rightWidth[n] = 0;

	for (int i=n-1; i>=1; i--)
	{
	  while (head <= tail && h[i] <= h[q[tail]])
    {
		  tail--;
    }

		rightWidth[i] = q[tail] - i - 1;
	  tail++;
	  q[tail] = i;
  }
}

long long FindMaxSize()
{
  long long maxSize = -1;
	long long tempSize;
	int tempWidth;
	
	for(int i=1; i<=n; i++)
	{
	  tempWidth = leftWidth[i] + rightWidth[i] + 1;
		tempSize = h[i] * tempWidth;
		if (tempSize > maxSize) maxSize = tempSize;
		
		/* test
		   cout << i << " " << leftWidth[i] << " " << rightWidth[i] << endl;
    */
	}
	
	return maxSize;
}

int main()
{
  while (1)
  {
	  scanf("%d", &n);
    if(n == 0) return 0;
	  // end main()

    for(int i = 1; i <= n; i++)
      h[i] = GetInt();
        
    FindLeft();
    FindRight();
    printf("%lld\n", FindMaxSize());
  }

  return 0;
}
