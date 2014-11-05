# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
# define INF 0x7FFFFFFF
# define REP(i,n) for(int i=0;i<n;i++)
# define REP1(i,n) for(int i=1;i<=n;i++)
# define CLR(a,b) memset(a,b,sizeof(a))

//纯粹的递归做法
char s[1010];
int len;

int checknum(int l,int r){
	for(int i=l;i<=r;i++)	if(!(s[i]>='0'&&s[i]<='9'))	return INF;
	int ans=s[l]-'0';
	for(int i=l+1;i<=r;i++)	ans*=10,ans+=s[i]-'0';
	return ans;
}

int eval(int l,int r){	
	if(l>r)	return 0;
	int val=checknum(l,r);
	if(val!=INF)		return val;
	if(s[l]=='('&&s[r]==')')	return eval(l+1,r-1);
	int cnt=0,i,flag=0;
	int pos[100];char op[100];

//对于+ -，需要将统一层的元素先都全算出来
	for(i=l;i<=r;i++){
		if(s[i]=='(')	cnt++;
		else	if(s[i]==')')	cnt--;
		if((s[i]=='+'||s[i]=='-')&&cnt==0){
			op[flag]=s[i],pos[flag++]=i;
		}
	}
	if(flag){
		pos[flag]=r+1;
		int ans=eval(l,pos[0]-1);
		for(int i=0;i<flag;i++){
			int tmp=eval(pos[i]+1,pos[i+1]-1);
			if(op[i]=='+')	ans+=tmp;
			else 	ans-=tmp;
		}
		return ans;
	}

//对于* /，也是一样
	for(i=l;i<=r;i++){
		if(s[i]=='(')	cnt++;
		else	if(s[i]==')')	cnt--;
		if((s[i]=='*'||s[i]=='/')&&cnt==0){
			op[flag]=s[i],pos[flag++]=i;
		}
	}

	if(flag){
		pos[flag]=r+1;
		int ans=eval(l,pos[0]-1);
		for(int i=0;i<flag;i++){
			int tmp=eval(pos[i]+1,pos[i+1]-1);
			if(op[i]=='*')	ans*=tmp;
			else 	ans/=tmp;
		}
		return ans;
	}

//对于^，因为是右结合的，所以直接递归就行了
	for(i=l;i<=r;i++){
		if(s[i]=='(')	cnt++;
		else	if(s[i]==')')	cnt--;
		if(s[i]=='^'&&cnt==0)	return pow(eval(l,i-1),eval(i+1,r));
	}
}

void process(){
	int len=strlen(s); 	
	printf("%d\n",eval(0,len-1));
}

int main(){
	while(~scanf("%s",s)){
		process();
	}
	return 0;
}
