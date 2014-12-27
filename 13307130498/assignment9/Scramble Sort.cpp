#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
string s,num[1000],str[1000];
int x,y,o[2000];
int i,j,k,m,size;
bool fnum(string a,string b){
	for(x=m=0;m<a.size();m++){
		if(a[m]=='-')continue;
		x=x*10+a[m];
	}
	if(a[0]=='-')x=-x;
	for(y=m=0;m<b.size();m++){
		if(b[m]=='-')continue;
		y=y*10+b[m];
	}
	if(b[0]=='-')y=-y;
	return x<y;
}
bool fstr(string a,string b){
	for(m=0;m<a.size()&&m<b.size();m++){
		if(a[m]>='a'&&a[m]<='z'&&b[m]>='A'&&b[m]<='Z'){
			if(a[m]-'a'+'A'<b[m])return 1;
			if(a[m]-'a'+'A'>b[m])return 0;
		}
		else if(a[m]>='A'&&a[m]<='Z'&&b[m]>='a'&&b[m]<='z'){
			if(a[m]-'A'+'a'<b[m])return 1;
			if(a[m]-'A'+'a'>b[m])return 0;
		}
		else{
			if(a[m]<b[m])return 1;
			if(a[m]>b[m])return 0;
		}
	}
	if(m==a.size())return 1;
	else return 0;
}
int main(void){
	while(1){
		cin>>s;
		if(s==".")break;
		i=j=k=0;
		while(s[s.size()-1]!='.'){
			if(s[0]>='0'&&s[0]<='9'||s[0]=='-'){
				num[i++]=s.substr(0,s.size()-1);
				o[k++]=0;
			}
			else{
				str[j++]=s.substr(0,s.size()-1);
				o[k++]=1;
			}
			cin>>s;
		}
		if(s[0]>='0'&&s[0]<='9'||s[0]=='-'){
			num[i++]=s.substr(0,s.size()-1);
			o[k++]=0;
		}
		else{
			str[j++]=s.substr(0,s.size()-1);
			o[k++]=1;
		}
		size=k;
		sort(num,num+i,fnum);
		sort(str,str+j,fstr);
		for(i=j=k=0;k<size-1;k++){
			if(o[k]==0)cout<<num[i++]<<", ";
			else cout<<str[j++]<<", ";
		}
		if(o[k]==0)cout<<num[i++]<<"."<<endl;
		else cout<<str[j++]<<"."<<endl;
	}
	return 0;
}

