/*
	 author: Han Peiru
	 date: 2014.10.21
*/

#include<iostream>
using namespace std;

int n;
int order[1050];
int hash[1050]; 
int acheive[1050];
int stack[1050]; 
// use stack[0] as head

int TestOrder()
{ for (int i=1; i<=n; i++)
	{
		acheive[order[i]] = 1;
		
	  if (hash[order[i]] == 0)
		{
		  for (int j=1; j<order[i]; j++)
			{
			  if (hash[j]==0 && acheive[j]==0)
		    {
				  hash[j] = 1;
	        stack[0]++;
				  stack[stack[0]] = j;
		    }
      }
		}
		
		else
		{
      if(stack[stack[0]] != order[i]) return -1;
      //can't be reorganised in the giving order

			stack[stack[0]] = 0;
			stack[0]--;
    }
	}
	
	return 0;
	//can be reorganised in the giving order
}

int main()
{ 
	while (1)
	{
	  cin >> n;
		if (n==0) break;
		
		while (1)
		{
		  cin >> order[1];
			if (order[1] == 0)
	    { cout << endl;
			  break;
			}

			stack[0] = 0;
			hash[1] = 0;
			stack[1] = 0;
			acheive[1] = 0;
			for (int i=2; i<=n; i++)
			{ cin >> order[i];
				hash[i] = 0;
				stack[i] = 0;
				acheive[i] = 0;
		  }
		
	  	if (TestOrder() == 0) cout << "Yes" << endl;
			else                  cout << "No" << endl;
    }
    
  }
	return 0;
}
