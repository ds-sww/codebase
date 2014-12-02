#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int j,x,n,m,t,a[200000],b[200000];
long long ans;

void qsort(int l,int r){
    int m=(l+r)/2;
    int xx=a[m];
    int i=l,j=r;
    while (i<j){
        while (a[i]<xx) i++;
        while (a[j]>xx) j--;
        if (i<=j){
            swap(a[i],a[j]);
            i++; j--;
        }
    }
    if (l<j) qsort(l,j);
    if (i<r) qsort(i,r);
}

int main(){
while (cin>>n>>m,n&&m){
    rep(i,1,n) scanf("%d",&a[i]);
    qsort(1,n);
    rep(i,1,n) b[i]=a[i];
    rep(i,1,m) scanf("%d",&a[i]);
    qsort(1,m);
    j=1; int flag=1;
    ans=0;
    rep(i,1,n){
        while (j<m && a[j]<b[i]) j++;
        if (a[j]<b[i]) flag=0;
        ans=ans+a[j++];
    }
    if (!flag) printf("Loowater is doomed!\n");
    else cout<<ans<<endl;
}
}