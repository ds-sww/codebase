#include <cstdio>
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int evaluate(int a,int b,char c)
{
	switch (c)
	{
		case'+': return (a+b);
		case'-':  return (a-b);
		case'*': return (a*b);
		case'/': return (a/b);
		case'^': return (pow(a,b));
	}
	return 0;
}
int icp(char c)
 {
		 switch(c)
		 {
			  case'^':return 4;
			  case'*':
			  case'/':return 2;
			  case'+':
			  case'-':return 1; 
	     }
	     return 0;
}
int isp(char c)
{
		switch(c)
	  {
			case'^':return 3;
			case'*':
		    case'/':return 2;
			case'+':
			case'-':return 1;
			case'(':return 0;
			case'$':return -1;
	  }
	    return 0;
}
int mid_to_pos(char mid_e[])
{
	    int x;
	    stack  <char> s;
	    stack <int> ss;
	    s.push('$');
	    char c;
		int i=0;
		c=mid_e[0];
		while(c!='\0')
		{
			if(c<='9'&&c>='0')
			{
			        if((i==0)||(mid_e[i-1]>'9'||mid_e[i-1]<'0')) 
				             ss.push(c-'0');
			          else  ss.top()=ss.top()*10+(c-'0');
			}
			 else switch(c)
			 {
				 case'+':
				 case'-':
				 case'*':
				 case'/':
				 case'^':
					      while(icp(c)<=isp(s.top()))
					      {
							  x=ss.top();
							  ss.pop();
							  ss.top()=evaluate(ss.top(),x,s.top());
					      s.pop();}
					      s.push(c);
					      break;
				 case'(':
					      s.push(c);
					      break;
			   	 case')':
				     	  while((s.top()!='('))
				     	  { x=ss.top();
							  ss.pop();
							  ss.top()=evaluate(ss.top(),x,s.top());
				     	  s.pop();}
				     	  s.pop();
			              break;
			     default:
			              return -1;
			 }
			 c=mid_e[++i];
		 }
		 while(s.top()!='$')
		 { x=ss.top();
							  ss.pop();
							  ss.top()=evaluate(ss.top(),x,s.top());
		 s.pop();}
		 s.pop();
		 cout<<ss.top();
		 return 0;
	
}


int main()
{
	stack <char> a;
	char b[100];
	while(cin >> b)
	{
          mid_to_pos(b);
          cout<<endl;
             
          
     }	 
	
}
