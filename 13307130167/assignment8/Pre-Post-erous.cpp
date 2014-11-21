#include <iostream>
#include <cstring>

using namespace std;

long long ans;
int m;

int combination(int m, int n){
    if(n==0 ||n==m)     return 1;
    else return combination(m-1,n)+combination(m-1,n-1);
}

void child_com(char *a, char *b, int len){
    if(len<=0)  return;
    int i=0, pos=0;
    char ch=a[0];
    int cnt=0;
    while(i<=len){
    if(b[i]==ch){
        child_com(&a[pos+1],&b[pos],i-pos);
        pos=i+1;
        cnt++;
        if(i<len)   ch=a[pos];
    }
        i++;
    }
    ans*=combination(m,cnt);
    return;
}

int main()
{
    char a[30] ,b[30];
    int length;
    cin>>m;
    while(m!=0){
        cin>>a>>b;
        length=strlen(a)-1;
        ans=1;
        child_com(a,b,length);
        cout<<ans/m<<endl;
        cin>>m;
    }
    return 0;b
}
