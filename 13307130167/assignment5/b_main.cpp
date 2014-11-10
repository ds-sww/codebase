#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>
#define MAXN 100
using namespace std;

int isnumber(char c){
	if (c>='0'&&c<='9') return 1;
	else return 0;
}

class Expression {
private:
	char  pos_e[MAXN];

public:
	Expression()	{
		for (int i=0; i<MAXN ;i++)
			pos_e[i]='\0';
	}
	Expression(char p[]){
		for (int i=0; i<MAXN; i++)
			pos_e[i]=p[i];
	}
	int evaluate()
	{
		int i, k, x, y, z,r;
		stack <int> s;
		char c;
		i=0;
		c=pos_e[0];

		while(c!='\0')
		{
			if (isnumber(c)){
				int temp=0;
				while (isnumber(c)){
					temp=temp*10+c-'0';
					c=pos_e[++i];
				}
				s.push(temp);
			}
			else switch(c)
			{
			case '%':
				c=pos_e[++i];
			case '+':
				x=s.top();
				s.pop();
				y=s.top();
				s.pop();
				s.push(x+y);
				break;
			case '-' :
				x=s.top();
				s.pop();
				y=s.top();
				s.pop();
				s.push(y-x);
				break;
			case '*' :
				x=s.top();
				s.pop();
				y=s.top();
				s.pop();
				s.push(x*y);
				break;
			case '/' :
				x=s.top();
				s.pop();
				y=s.top();
				s.pop();
				s.push(y/x);
				break;
			case '^' :
				x=s.top();
				s.pop();
				y=s.top();
				s.pop();
				if (y==0) return 1;
				if(x==0)  s.push(1);
				else
				{
					for (z=1,k=1;k<=x; k++)  z*=y;
					s.push(z);
				}
					break;
			default: return 1;
			}
		c=pos_e[++i];
	}
		r=s.top();
	s.pop();
	if (s.empty()){
		cout<< r<<endl;
		return 0;
	}
	else return 1;
	}
};

class Mid2Pos {
public:
	int icp(char c)
	{
		switch(c)
		{
			case '^' : return 4;
			case '*' :
			case '/' : return 2;
			case '+' :
			case  '-' : return 1;
			default : return 0;
		}
	}

	int isp(char c)
	{
		switch(c)
		{
			case '^' : return 3;
			case '*' :
			case '/' : return 2;
			case '+' :
			case '-' : return 1;
			case '(' : return 0;
			case '$' : return -1;
			default: return 0;
		}
	}


	int mid_to_pos(char mid_e[], char pos_e[])
	{
		stack <char> s;
		s.push('$');
		char c;
		int i, j;
		j=0;
		i=0;
		c=mid_e[0];
		while(c!='\0')
		{
			if (isnumber(c)){
				while (isnumber(c)){
					pos_e[j++]=c;
					c=mid_e[++i];
				}
				pos_e[j++]='%' ;	//%为一个多位数的读入结束标志
				continue;
			}
			else switch (c)
			{
				case '+' :
				case '-' :
				case '*' :
				case '/' :
				case '^' :
					while (icp(c)<=isp(s.top()))	{
						pos_e[j++]=s.top();
						s.pop();
					}
					s.push(c);
					break;
				case '(' :
					s.push(c);
					break;
				case ')' :
					while (s.top() != '(' ){
						pos_e[j++]=s.top();
						s.pop();
					}
					s.pop();
					break;
				default :
					return 1;
			}
			c=mid_e[++i];
		}
		while (s.top()!='$'){
			pos_e[j++]=s.top();
			s.pop();
		}
		pos_e[j]='\0';
		return 0;
	}
};

int main(){
		string mid_exp_s;
		char mid_exp_c[MAXN], pos_exp_c[MAXN];	
		Mid2Pos operExp;
		while (cin >> mid_exp_s){
			for (int i=0; i<MAXN; i++){
			mid_exp_c[i]=pos_exp_c[i]='\0';		
			}
			for (unsigned int i=0; i<mid_exp_s.size() ; i++)
				mid_exp_c[i]=mid_exp_s[i];

			int mark1=0;
			mark1=operExp.mid_to_pos(mid_exp_c, pos_exp_c);
//			cout<<pos_exp_c<<"\t=";
			if (mark1==1) return 1;
			else if (mark1==0){
				Expression exp(pos_exp_c);
				int mark2=0;
				mark2=exp.evaluate();
				if (mark2==1) cout<<"no result!"<<endl;
			}
		}
		return 0;
}