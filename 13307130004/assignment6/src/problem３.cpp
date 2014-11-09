#include <iostream>
#include <cstdio>
#define N 1000000

using namespace std;

int merge(int a[],int l,int m){
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
}
void qsort(int a[],int l,int m ){
  if(m<=l) return;
  int i=merge(a,l,m);
  qsort(a,l,i-1);
  qsort(a,i+1,m);
}
int main(){
  int m,n;
  int a[N],b[N];
  int sum,j;
  bool z=false;
  while(1){
  	scanf("%d%d",&m,&n);
    if((!m)and(!n)) break;
  	for(int i=0;i<m;i++)
  		cin>>a[i];
  	for(int i=0;i<n;i++)
  		cin>>b[i];  	
  	if(n<m){
  		cout<<"Loowater is doomed!"<<endl;
  		continue;
  	}
  	sum=0,j=0,z=false;
  	qsort(a,0,m-1);
  	qsort(b,0,n-1);
  	for(int i=0;i<m;i++){
  		while(a[i]>b[j]&&j<n)
  			j++;
  		if(j>=n)
  			break;
  		if(a[i]<=b[j]){
  			sum+=b[j];
        j++;
        if(i==m-1)
          z=true;
      }
  	}
  	if(!z)
  		cout<<"Loowater is doomed!"<<endl;
  	else
  		cout<<sum<<endl;
  }
  return 0;
}