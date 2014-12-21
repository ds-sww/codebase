#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int a[30];
//a[letter-'A']=num
string s[15];
//words
int temp;
//first letter appear -'A'
bool use[10];
//true:has used
 //false:not used yet  
int number=0;
long long x[15];
int n;
int uuuu=0;

bool check()
{
	memset(x,0,sizeof(x));
	int sum=0;
	for(int k=0;k<n;k++) 
	   if(a[s[k][0]-'A']==0)
	      return false;
	for(int i=0;i<n-1;i++)
	    sum=(sum+a[s[i][s[i].length()-1]-'A'])%10;
	if(sum!=a[s[n-1][s[n-1].length()-1]-'A'])
	    return false;
	for(int i=0;i<n;i++)
	    for(unsigned int j=0;j<s[i].length();j++)  
	       x[i]=x[i]*10+a[s[i][j]-'A'];
	for(int i=1;i<n-1;i++)
	     x[i]+=x[i-1];
	if(x[n-2]==x[n-1])
	      return true;
	 return false;
}

void set(int p)
{
	if(p==30) 
	{
	 if(check()==true)
	      number++;
      return;
	}
	if(a[p]==-1)
	{
	    set(p+1);
	}
	else 
	{
	    for(int i=0;i<10;i++)
	      if(use[i]==false )
	        {
				use[i]=true;
				a[p]=i;
				set(p+1);	
				use[i]=false;
	         }	
	}
	
			
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	   cin>>s[i];
	for(int i=0;i<30;i++)
	   a[i]=-1;
	 for(int i=0;i<n;i++)
	   for(unsigned int j=0;j<s[i].length();j++)
	     a[s[i][j]-'A']=0;
	  for(int i=0;i<30;i++)
	     if(a[i]!=-1)
	      {
			  temp=i;
			   break;
		  }
	  set(temp);
	  cout << number << endl;
	  return 0;
}
