#include <cstdio>
#include <iostream>

using namespace std;

int a[80000];

int main()
{
      int n;
      int x;
      int top=-1;
      long int sum=0;
      cin >> n;
      for(int i=0;i<n;i++)
      {  
		    scanf("%d",&x);
		    if(top==-1) a[++top]=x;
		    else
		    {
		        while(top>=0&&a[top]<=x)  top--;	
		         top++;
		         a[top]=x;
		         sum+=top;
		  }
	  }	
	  cout << sum << endl;
	  return 0;
}


