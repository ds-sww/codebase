//	n^2的算法。转换成后缀表达式不熟练，上机时间短写不出来。
//	对括号的处理方法与书上不同。因为没用栈，乘方的处理方法也有些不同。
//	
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int MAXN=10001;
//数组比链表出错可能性小
char s[MAXN];
int a[MAXN],p[MAXN];
char b[MAXN];
int l,i,num1,num2,ad,po;
int tmp,maxx;
int main()
{
    while (scanf("%s",s)!=-1)
    {
        for (int i=0;i<MAXN;i++)
        {
            a[i]=0;
            p[i]=0;
        }
        num1=num2=0;
        l=0;
        while (s[l]!='\0') l++;
        i=0;
        ad=0;
        po=0;
        
        //处理表达式
        
        while (i<l)
        {
        	//特殊处理减号：减号有可能表示相减，也有可能表示负数。-k=0-k
            if ( s[i]=='-' )
            	if (i==0 || s[i-1]=='(' ) 
	            {
    	            num1++;
    	            a[num1]=0;
    	            num2++;
    	            b[num2]='-';
    	            p[num2]=99999+ad;	//将-k表示为0-k，这种情况下'-'优先级应为最高
    	        }
    	        else
    	        {
    	       		num2++;
              		b[num2]=s[i];
               		p[num2]=1+ad;
    	        }
    	     
    	    //处理运算符   
    	     
            if (s[i]=='(') ad+=1000;	//增加括号内运算符的优先级
            if (s[i]==')') ad-=1000;
            if (s[i]=='+')
            {
                num2++;
                b[num2]=s[i];
                p[num2]=1+ad;
            }
            if (s[i]=='*' || s[i]=='/')
            {
                num2++;
                b[num2]=s[i];
                p[num2]=2+ad;
            }
            if (s[i]=='^')
            {
                num2++;
                b[num2]=s[i];
                p[num2]=3+ad+po;
                po++;	//乘方是从右向左运算，增加靠右的乘方运算符的优先级。增加的优先级远小于括号增加的优先级。
                		//理论上括号增加的优先级数应至少为乘方运算符的个数。
            }
            
            if (s[i]>='0' && s[i]<= '9')
            {
                num1++;
                a[num1]=s[i]-'0';
                while ( (i<l) && (s[i+1]>='0' && s[i+1]<= '9') )
                {
                    i++;
                    a[num1]=a[num1]*10+s[i]-'0';
                }
            }
            i++;
        }
        
        //转化后的表达式，应该有num1个数字与num1-1个运算符
        //找优先级最高的运算符计算。重复num1-1次。
        //此部分可以用后缀表达式优化
        
        while (num1>1)
        {
            maxx=0;
            for (int i=1;i<num1;i++)
            {
                if (p[i]>maxx)
                {
                    maxx=p[i];
                    tmp=i;
                }
            }
            if (b[tmp]=='+')
            {
                a[tmp]+=a[tmp+1];
            }
            else if (b[tmp]=='-')
            {
                a[tmp]-=a[tmp+1];
            }
            else if (b[tmp]=='*')
            {
                a[tmp]*=a[tmp+1];
            }
            else if (b[tmp]=='/')
            {
                a[tmp]/=a[tmp+1];
            }
            else if (b[tmp]=='^')
            {
                int dd=1;
                for (int j=1;j<=a[tmp+1];j++)
                {
                    dd=dd*a[tmp];
                }
                a[tmp]=dd;
            }
            for (int i=tmp+1;i<num1;i++)
            {
                a[i]=a[i+1];
                b[i-1]=b[i];
                p[i-1]=p[i];
            }
            num1--;
        }
        printf("%d\n",a[1]);
    }
    return 0;
}
