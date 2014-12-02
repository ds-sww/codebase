/*
   author: Han Peiru
	 date: 2014.10.24
	 This version seems to be right
	 But it gets Wrong Answer of 2 data points on the OJ
	 and the other 12 data points are all Accepted
*/

#include <iostream>
#include <cstdio>
using namespace std;

inline long long GetInt()
{
  long long ret = 0;
  int neg = 0;
  int c;
	while (isspace(c = getchar()));
  if(c == '-')
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

struct RectangleStack
{
  long long height;
  int leftWidth;
	int rightWidth;
} s[1000050];
int top;

long long h[1000050];
int n;

long long FindMaxSize()
{
  long long maxSize = 0;
  long long tempSize;
  int tempWidth;
  int nowLeftWidth;
	 
  top = 1;
  s[top].height = h[1];
  s[top].leftWidth = 0;
  s[top].rightWidth = 0;

  n++;
  h[n] = -0x7fffffff;
  /* this ensures that all elements in the stack
     can be popped out */
	    
  for (int i=2; i<=n; i++)
  {
	  nowLeftWidth = 0;
	 
    while (s[top].height > h[i] && top >= 1)
    {
		  tempWidth = s[top].leftWidth + s[top].rightWidth + 1;
      tempSize = s[top].height * tempWidth;
	    if(tempSize > maxSize) maxSize = tempSize;

      nowLeftWidth += s[top].leftWidth + 1;
      s[top-1].rightWidth += s[top].rightWidth + 1;
      top--;
    }
      
    if (s[top].height == h[i] && top >= 1)
    {
      s[top].rightWidth++;
    }
    
    else if (s[top].height < h[i] || top == 0)
    {
		  top++;
      s[top].height = h[i];
      s[top].leftWidth = nowLeftWidth;
      s[top].rightWidth = 0;
    }
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

    printf("%lld\n", FindMaxSize());
  }

	return 0;
}

