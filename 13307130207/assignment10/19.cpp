#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define For(i,a) for(int i=0;i<a;++i)
using namespace std;

int cnt,len,pa,pb,na,nb,b[200000],cao[200000];
string s,a[200000];

inline int cg(char c){
    if ('A'<=c && c<='Z') return c-'A';
    return c-'a';
}

inline bool cmp(string a,string b){
    int len=min(a.length(),b.length());
    For(i,len) if (cg(a[i])<cg(b[i])) return 1;
    else if (cg(a[i])>cg(b[i])) return 0;
}

int main(){
//freopen("a.in","r",stdin);
    while (1){
        cnt=na=nb=0;
        while(++cnt){
            cin>>s;
            len=s.length();
            if (isdigit(s[0])||s[0]=='-'){
                b[++nb]=0;
                cao[cnt]=0;
                if (s[0]=='-') rep(i,1,len-2) b[nb]=b[nb]*10-s[i]+'0';
                else For(i,len-1) b[nb]=b[nb]*10+s[i]-'0';
            }else{
                a[++na]=s.substr(0,len-1);
                cao[cnt]=1;
            }
            if (s[len-1]=='.') break;
        }
        if (na==1 && a[1].length()==0) break;

        sort(b+1,b+nb+1);
        sort(a+1,a+na+1,cmp);
        pa=pb=0;
        //rep(i,1,cnt) cout<<cao[i]; cout<<endl;
        rep(i,1,cnt){
            if (i!=1) cout<<' ';

            if (cao[i])cout<<a[++pa];
            else cout<<b[++pb];

            if (i==cnt) cout<<'.';
            else cout<<',';
        }
        cout<<endl;
    }
}