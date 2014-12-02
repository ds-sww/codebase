#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int j,x,n,t,a[200000];

void qsort(int l,int r){
    int m=(l+r)/2;
    int xx=a[m];
    int i=l,j=r;
    while (i<j){
        while (abs(a[i])<abs(xx)) i++;
        while (abs(a[j])>abs(xx)) j--;
        if (i<=j){
            swap(a[i],a[j]);
            i++; j--;
        }
    }
    if (l<j) qsort(l,j);
    if (i<r) qsort(i,r);
}

int main(){
    cin>>t>>n;
    rep(i,1,n) scanf("%d",&a[i]);
    qsort(1,n);
    rep(i,1,n){
        t-=abs(a[i]-a[i-1]);
        if (t<0){
            cout<<i-1<<endl;
            break;
        }
    }
}