#include<cstdio>
#include<cstdlib>
#include<cstring>
int n,p,top;
char ch_stack[20000];
int num_stack[20000];
char order[20000];
int priority[256];
int act(int a,int b,char e)
{
    if(e=='+')  return a+b;
    if(e=='-')  return a-b;
    if(e=='*')  return a*b;
    if(e=='/')  return a/b;
    if(e=='^')
    {
        int i,_count=1;
        for(i=0;i<b;i++)
            _count*=a;
        return _count;
    }
}//to do the calculation
int main()
{
    int i,j;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    priority['+']=priority['-']=1;
    priority['*']=priority['/']=2;
    priority['^']=3;
    //for priority
    while(scanf("%s",order)!=-1)
    {
        p=0;top=0;
        n=strlen(order);
        for(i=0;i<n;i++)
        if('0'<=order[i]&&order[i]<='9')
        {
            if(i==0||!('0'<=order[i-1]&&order[i-1]<='9'))
		num_stack[top]=0;
            num_stack[top]=num_stack[top]*10+(order[i]-'0');
            if(i==n-1||!('0'<=order[i+1]&&order[i+1]<='9')) 
            	top++;
	    //turn characters into numbers
        }
        else
        {
            if(order[i]==')')//case for bracelet
            {
                while(p>0&&ch_stack[p-1]!='(')
                {
                    num_stack[top-2]=act(num_stack[top-2],num_stack[top-1],ch_stack[p-1]);
                    top--;
                    p--;
                }
                p--;
            }
            else
            if(priority[order[i]]==3&&order[i]!='(')//case for ^
            {
                while(p>0&&priority[order[i]]<priority[ch_stack[p-1]])
                {
                    num_stack[top-2]=act(num_stack[top-2],num_stack[top-1],ch_stack[p-1]);
                    top--;
                    p--;
                }
                ch_stack[p]=order[i];
                p++;
            }
            else
            if(priority[order[i]]!=3&&order[i]!='(')//case for +-*/
            {
                while(p>0&&priority[order[i]]<=priority[ch_stack[p-1]])
                {
                    num_stack[top-2]=act(num_stack[top-2],num_stack[top-1],ch_stack[p-1]);
                    top--;
                    p--;
                }
                ch_stack[p]=order[i];
                p++;
            }
            else//other cases
            {
                ch_stack[p]=order[i];
                p++;
            }
        }
        while(p>0)//pop in the end
        {
            num_stack[top-2]=act(num_stack[top-2],num_stack[top-1],ch_stack[p-1]);
            top--;
            p--;
        }
        printf("%d\n",num_stack[0]);
    }
    return 0;
}
