/*修改利用了了一下书上的栈定义以及中缀转后缀函数和后缀计算，
将表达式转成后缀之后进行计算，但是过不了OJ，用一些正确的测试数据实验后也是正确的，
不知道是哪里除了问题，希望助教予以改正，谢谢～*/

#include<iostream>
#include<string>
using namespace std;
template<class Type>class Stack
{
private:
	Type *stk;
	int top;
	int MAXN;
public:
	Stack(int size)
	{
		MAXN=size;
		stk=new Type[MAXN];
		top=-1;
	}
	Stack()
	{
		stk=new Type[100];
		top=-1;
		MAXN=100;
	}

	~Stack(){delete []stk;}
	int push(Type x)
	{
		if(top>=MAXN-1)
			return 1;
		stk[++top]=x;
		return 0;
	}
	Type pop()
	{
		Type px;
		if(top==-1)
			return 0;
		px=stk[top--];
		return px;

	}
	Type getTop()
	{
		if(top==-1)
			return NULL;
		return stk[top];
	}
	int isEmpty()const{return top==-1;}
	int isFull()const{return top==MAXN-1;}
};
int evaluate(int p_y, char * pos_e)
{
	int i,j,k,z,x,y,l=0;
	Stack<int> s;
	char c;
	i=0;
	c=pos_e[0];
	while(c!='\0')
	{
		if(c>='0'&&c<='9')
		{
			while(c>='0'&&c<='9')
			{
				l=10*l+(c-'0');
				c=pos_e[++i];
			}
			s.push(l);
			l=0;
			i--;
		}
		else
		{
			switch(c)
			{
			case 'p':break;
			case '+':
				x=s.pop();
				y=s.pop();
				s.push((x)+(y));
				break;
			case '-':
				x=s.pop();
				y=s.pop();
				s.push((y)-(x));
				break;
			case '*':
				x=s.pop();
				y=s.pop();
				s.push((x)*(y));
				break;
			case '/':
				x=s.pop();
				y=s.pop();
				s.push((y)/(x));
				break;
			case '^':
				x=s.pop();
				y=s.pop();
				if(y==0)
					s.push(0);
				else
				{
					if(x==0)
						s.push(1);
					else
					{
						if(x>0)
							j=x;
						else
							j=-(x);
						for(z=1,k=1;k<=j;k++)
							z*=(y);
						if(x<0)
							z=1/z;
						s.push(z);
					}
					break;
				}
			}
		}
		c=pos_e[++i];
	}
	p_y=s.pop();
	if(s.isEmpty())
		return p_y;
}
int icp(char c)
{
	switch(c)
	{
	case '^':return 4;
	case '*':
	case '/':return 2;
	case '+':
	case '-':return 1;
	}
}
int isp(char c)
{
	switch(c)
	{
	case '^':return 3;
	case '*':
	case '/':return 2;
	case '+':
	case '-':return 1;
	case '(':return 0;
	case '$':return -1;
	}
}
int mid_to_pos(char mid_e[],char pos_e[])
{

	Stack<char>s;
	char c;
	int i,j;
	j=0;i=0;
	c=mid_e[0];
	while(c!='\0')
	{
		if(isdigit(c))
		{
			pos_e[j++]=c;
		}
		else 
		{
			pos_e[j++]='p';  //用p来分割不同的数字
			switch(c)
			{
			case'+':
			case'-':
			case'*':
			case'/':
			case'^':
				while(icp(c)<=isp(s.getTop()))
				{
					pos_e[j++]=s.pop();
				}
				s.push(c);
				break;
			case'(':
				s.push(c);
				break;
			case')':
				while((s.getTop())!='(')
				{
					pos_e[j++]=s.pop();
				}
				break;
			default:return 1;
			}
		}
		c=mid_e[++i];
	}
	while(s.isEmpty()!=1)
	{
		pos_e[j++]=s.pop();
	}
	pos_e[j]='\0';
	return 0;
}
int main()
{
	string q[100];
	char mid_e[100];
	char *pos_e=new char[100];
	int v;
	int number =0;
	v=0;
	while(cin>>q[v])

		v++;
	for(int i=0;i<v;i++)
	{
		strcpy(mid_e, q[i].c_str());
		mid_to_pos(mid_e,pos_e);
		number=evaluate(number,pos_e);
		cout<<number<<endl;
	}
	return 0;
}






