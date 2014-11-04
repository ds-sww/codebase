#include <iostream>
#include <ctype.h>
#include <stack>
#include <cstdio>

using namespace std;
#define MAXN 100
char mid_e[MAXN],pos_e[MAXN];
int evaluate(int *p_y,char pos_e[]){
		int i,j,k,x,y,z;
		stack<int>s;
		char c;
		i=0;
		c=pos_e[0];
		while(c !='\0'){
			int a=0;
			if(isdigit(c)){
				while(isdigit(c)){
				a=a*10+c-'0';
				c=pos_e[++i];
				}
				s.push(a);
			}
			else switch(c){
				case'+':    x=s.top();
                                    s.pop();
                                    y=s.top();
                                    s.pop();
                                    s.push(x+y);
                                    break;
				case'-':    x=s.top();
                                    s.pop();
                                    y=s.top();
                                    s.pop();
                                    s.push(y-x);
                                    break;
				case'*':    x=s.top();
                                    s.pop();
                                    y=s.top();
                                    s.pop();
                                    s.push(x*y);
                                    break;
				case'/':    x=s.top();
                                    s.pop();
                                    y=s.top();
                                    s.pop();
                                    s.push(y/x);
                                    break;
				case'^':    x=s.top();
                                    s.pop();
                                    y=s.top();
                                    s.pop();
                                    if(y==0)return 1;
                                    if(x==0)s.push(1);
                                    else{
                                            if(x>0)j=x;
                                            else j=-x;
                                            for(z=1,k=1;k<=j;k++)z*=y;
                                            if(x<0)z=1/z;
                                            s.push(z);
                                    }
                                    break;
				default:    return 1;
			}
			c=pos_e[++i];
		}
		*p_y=s.top();
		while(!s.empty())s.pop();
		if(s.empty())return 0;
		else return 1;
	}

class mid2pos{
public:
    int icp(char c){
    switch(c){
        case '^':return 4;
        case'*':
		case'/':return 2;
        case'+':
		case'-':return 1;
        }
        return 0;
    }
    int isp(char c){
    switch(c){
        case'^':return 3;
        case'*':
        case'/':return 2;
        case '+':
        case'-':return 1;
        case'(':return 0;
        case '$':return -1;
        }
        return 0;
	}
    int mid_to_pos(char mid_e[],char pos_e[]){
        stack<char>s;
        char c;
        int i,j;
        j=0;
        i=0;
        c=mid_e[0];
        while(c!='\0')
        {
            if(isdigit(c)){
                while(isdigit(c)){
                    pos_e[j++]=c;
                    c=mid_e[++i];
                }
                pos_e[j++]=']';
                continue;
            }
            else switch(c)
            {
                case '+':
                case'-':
                case'*':
                case'/':
                case'^':    while(!s.empty()&&icp(c)<=isp(s.top())){
                                        pos_e[j++]=s.top();
                                        s.pop();
                                    }
                                    s.push(c);
                                    break;
                case'(':    	s.push(c);
                                    break;
                case')':	    while(!s.empty()&&s.top()!='('){
                                        if(s.top()!='(')pos_e[j++]=s.top();
                                        s .pop();
                                        }
                                    s .pop();
                                    break;
                default:
                                    return 1;
            }
            c=mid_e[++i];
        }
        while(!s.empty()){//输出栈里所有元素
            if(s.top()!='(')pos_e[j++]=s.top();
            s.pop();
            }
        pos_e[j]='\0';
        return 0;
        }
};

int main()
{
   char ch;
   int *p_y=new int;
   mid2pos md;
   while(ch=getchar(),ch!='\n'&&ch!=EOF){
	   int i=0;
	   mid_e[i]=ch;
	   while(ch=getchar(),ch!='\n')
			mid_e[++i]=ch;
            mid_e[++i]='\0';
            md.mid_to_pos(mid_e,pos_e);
            evaluate(p_y,pos_e);
            cout<<*p_y<<endl;
   }
   return 0;
}




