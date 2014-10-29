#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string pattern;

bool check(const string& a){
	if(((a[0] <'0' or a[0] > '9') and a[0] != '-' and a[0] != '@'))
		return false;
	for(int i=1;i<a.length();i++)
		if(((a[i] <'0' or a[i] > '9')))
			return false;
	return true;
}

int find_next(const string& a,int begin){
	int count;
	count = 1;
	for(++begin;count !=0 and begin<a.length();begin++)
		if(a[begin]=='(')
			++count;
		else if(a[begin]==')')
			--count;
	return begin;	
}


int find_left_digit(const string& a,int i){
	while(a[i] >= '0' and a[i] <= '9' and i>0)
		--i;
	if(i == 0)
	return 0;
	else if(a[i]=='@')
		return i;
	return i+1;
}
int find_right_digit(const string& a,int i){
	if(a[i]=='@')
		++i;
	while(a[i] >= '0' and a[i] <= '9' and i<a.length())
		++i;
	if(i == a.length())
	return i;
	else
	return i-1;
}
int to_digit(const string& a,int i){
	int tmp;bool ne;
	if(a[i]=='@'){
		ne = true;
		i++;
	}
	else 
		ne =false;
	tmp = 0;
	for(;a[i] >= '0' and a[i] <= '9' and i<a.length();i++)
		tmp=tmp*10+a[i]-'0';
	if(ne)
		tmp = -tmp;
	return  tmp;
}
string to_string(int ans){
	string tmp;
	bool ne;
	if(ans == 0)
		return "0";
	if(ans < 0){
		ne = true;
		ans = -ans;
	}else 
		ne = false;
	for(;ans>0;ans /=10)
		tmp=(char)(ans%10+'0')+tmp;
	if(ne)
		tmp = '@' + tmp;
	return tmp;
}



void reverse(string& a){
	int i,l;
	char tmp;
	l = a.length();
	i = l>>1;
	for(int j=0;j<=i;j++){
		tmp = a[j];
		a[j] = a[l-j-1];
		a[l-j-1] = tmp;
	}
		
}
string power(const string& a,const string& b){
	string tmp;
	int q,w,ans;
	q = to_digit(a,0);
	w = to_digit(b,0);
	ans = 1;
	for(int i=0;i<w;i++)
		ans*=q;
	return to_string(ans);
}
string multiply(const string& a,const string& b){
	string tmp;
	int ans;
	tmp = "";
	ans = to_digit(a,0)*to_digit(b,0);
	return to_string(ans);

}
string divid(const string& a,const string& b){
	string tmp;
	int ans;
	tmp = "";
	ans = to_digit(a,0)/to_digit(b,0);
	return to_string(ans);
}
string solve(string a){
	int i,l,r,ans;
	bool ne;
	string tmp;
	for(i=a.length()-1;i>0;i--)
		if(a[i] == '^'){
			l = find_left_digit(a,i-1);
			r = find_right_digit(a,i+1);
			a.replace(l,r-l+1,power(a.substr(l,i-l),a.substr(i+1,r-i)));
			i = l;
		}else if(i == a.length())
			break;
	for(i=0;i<a.length();i++)
		if(a[i] == '*' or a[i] =='/'){
			l = find_left_digit(a,i-1);
			r = find_right_digit(a,i+1);
			if(a[i] == '*'){
				
				a.replace(l,r-l+1,multiply(a.substr(l,i-l),a.substr(i+1,r-i)));}
			else if(a[i] == '/'){
				a.replace(l,r-l+1,divid(a.substr(l,i-l),a.substr(i+1,r-i)));	}		
			i = l;
		}else if(i == a.length())
			break;	
	ans = to_digit(a,0);
	for(i=find_right_digit(a,0)+1;i<a.length();i++){
		if(a[i]=='+'){
			ans+=to_digit(a,i+1);
			i = find_right_digit(a,i+1);
		}else if(a[i]=='-' or a[i]=='@'){
			ans-=to_digit(a,i+1);
			i = find_right_digit(a,i+1);
		}
	}
	return to_string(ans);
}

string make(string a){
	int tmp;
	for(int i=0;i<a.length();i++){
		if(a[i]=='('){
			tmp = find_next(a,i);
			a.replace(i,tmp-i,make(a.substr(i+1,tmp-i-2)));
		}
		if(i==a.length())
			break;
	}
	return solve(a);
}
void rep(string& a){
	for(int i=0;i<a.length();i++)
		if(a[i] == '@')
			a[i] = '-';
}
int main(){
	while(cin >> pattern){
		while(!check(pattern))
			pattern=make(pattern);
		rep(pattern);
		cout << pattern << endl;
	}
return 0;
}