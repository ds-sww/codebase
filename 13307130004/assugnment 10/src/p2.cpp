#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 20010
using namespace std;

int main(){
  int a[N];
  int i,n,s,l,r,m,sum=0;
  scanf("%d%d",&n,&s);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  sort(a,a+n);
  for(i=0;i<n-1;i++){
    l=i+1;
    r=n-1;
    while(l<=r){
      m=(l+r)>>1;
      if(a[m]+a[i]<=s)
	l=m+1;
      else
	r=m-1;
    }
    sum+=(l+r)/2-i;
  }
  cout<<sum<<endl;
}