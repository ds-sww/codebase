#include <cstdio>
#include <iostream>

using namespace std;

class Stack
{
	private:
	         struct  Way
	         {
			        int x;	 
				    Way *next;
			 }*top;
	public:
	     Stack() {top=NULL;}
	     void push(int a)  
     	{
	           Way *p=new Way;
	           p->x=a;
	           p->next=top;
	           top=p;	
       }
    	void pop()
	   { 
		       if (top ==NULL) {return;}
		       Way *p=top;
		       top=top->next;
		       delete p;
		}
		int top_x() 
		{
			if(top==NULL) 
			return -1;
			return top->x;
		}
		~Stack() 
		{
			Way *p,*q;
			for(p=top;p!=NULL&&p->next!=NULL;) 
			   {
				   q=p;
				   p=p->next;
				   delete q;
				}
			   top=NULL; 
	     }
};

int main()
{
    	int i;
    	int *a;
    	int m,n,q;
    	bool success_or_not=0;
    	Stack train;
    	while(1)
    	{
			cin >> i;
			if(i==0)  break;
	        while(1)
	       {
			      a=new int[i];
			      cin >> a[0];
			      if(a[0]==0){ delete []a; cout<<endl;break; }
	        	  for(int x=1;x<i;x++)
				  cin >> a[x];
			     for(n=1,m=0,q=0; n<=i&&m<i&&q<i;)
		         {
					 if(n==1)  train.push(1);
					 if(a[m]<train.top_x()||a[m]>i||a[m]<0)  
					 {success_or_not=1;break;}
			  	    if(a[m]==train.top_x())
				    {
						train.pop();
						m++;
						q++;
					}
					else{train.push(n); if(n<i) n++;}
				}  
				if(success_or_not==1)  cout << "No" << endl;
				else cout << "Yes" << endl;
				success_or_not=0;
		        delete []a;
		        train.~Stack();
	     	 }
	    }
        return 0;
}
