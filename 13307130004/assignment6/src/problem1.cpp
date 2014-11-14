#include <iostream>
#include <cstdio>
#include <cstring>
#define N 5000000
using namespace std;
static int a[N],b[N],size;
int merge(int l,int m){
  int i=l-1,j=m,temp=a[m],temp0;
  for(;;){
    while(a[++i]<temp);
    while(temp<a[--j])
      if(j==l) break;
    if(i>=j) break;
    temp0=a[j];a[j]=a[i];a[i]=temp0;
  }
  temp0=a[m];a[m]=a[i];a[i]=temp0;
  return i;
};
void qsort(int l,int m ){
  if(m<=l) return;
  int i=merge(l,m);
  qsort(l,i-1);
  qsort(i+1,m);
};
int main(){
  int T;
  string c;
  cin>>size;
  for(int i=0;i<size;i++)
    scanf("%d",&a[i]);
  qsort(0,size-1);
cin>>c;
cin>>size;
for(int i=0;i<size;i++)
    scanf("%d",&b[i]);
for(int i=0;i<size;i++)
    printf("%d\n",a[b[i]-1]);
  return 0;
}