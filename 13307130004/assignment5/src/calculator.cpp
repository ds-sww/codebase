#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Calculator{
private:
	string st;
	int cur;
	int length;

	int exponent(int base,int exp){
		int temp=base;
		for(int i=1;i<exp;i++)
			temp*=base;
		return temp;
	}
	int priority(char sym){
		switch (sym){
			case '+' : return 0;
			case '-' : return 0;
			case '*' : return 1;
			case '/' : return 1;
			case '^' : return 2;
			default: return -1;
		}
	}
	int calculate(int a,int b,char c){
		switch (c){
			case '+' : return (a+b);
			case '-' : return (a-b);
			case '*' : return (a*b);
			case '/' : return (a/b);
			case '^' : return exponent(a,b);
		}
	}
	int getresult(){
		int topn=0,tops=0;
		int *n=new int[length];
		char *s=new char[length];
		while(cur<length){
			if(st[cur]>='0'&&st[cur]<='9'){
				int temp=0;
				while(st[cur]>='0'&&st[cur]<='9')
					temp=temp*10+st[cur++]-'0';
				n[topn++]=temp;
			}
			if(cur<length&&(st[cur]=='+'||st[cur]=='-'||st[cur]=='*'||st[cur]=='/'||st[cur]=='^')){
				while(tops&&(priority(s[tops-1])>=priority(st[cur]))){
					if(priority(st[cur])==2) break;
					n[topn-2]=calculate(n[topn-2],n[topn-1],s[tops-1]);
					tops--;topn--;
				}
				s[tops++]=st[cur++];
			}
			if(cur<length&&(st[cur]=='(')){
				cur++;
				n[topn++]=getresult();
			}
			if(cur<length&&(st[cur]==')')){
				cur++;
				break;
			}
		}
		while(tops){
			n[topn-2]=calculate(n[topn-2],n[topn-1],s[tops-1]);
			tops--;topn--;
		}
		return n[0];
	}	
public:
	Calculator (const string &str){
		st=str;
		cur=0;
		length=st.size();
	}
	void result(){
		cout<<getresult()<<endl;
	}
};
int main(){
    string Str;
    while(cin >> Str){
        Calculator s(Str);
        s.result();
    }
    return 0;
}