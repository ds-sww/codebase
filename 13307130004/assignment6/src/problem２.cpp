#include <iostream>
#define N 50000
using namespace std;
static int a[N],b[N],size;
int abs(int a){
  if(a>=0) return a;
  else return (-a);
};
int merge(int l,int m){
  int i=l,j=m,temp=b[m],temp0;
  for(;;){
    while(b[i]<temp)i++;
    while(b[j]>temp){
	j--;
	if(j==l) break;
	}
    if(i>=j) break;
    temp0=b[j];b[j]=b[i];b[i]=temp0;
    temp0=a[j];a[j]=a[i];a[i]=temp0;
  }
  return i;
};
void qsort(int l,int m ){
  int i=merge(l,m);
  if(l<i-1)
    qsort(l,i-1);
  if(i+1<m)
    qsort(i+1,m);
};
int main(){
  int T,answer=0,temp=0;
  cin>>T>>size;
  for(int i=0;i<size;i++){
    cin>>a[i];
    b[i]=abs(a[i]);
  }
  qsort(0,size-1);
  while(T-abs(temp-a[answer])>=0){
	T-=abs(temp-a[answer]);
	temp=a[answer];
	answer++;
} 
	cout<<answer<<endl;
  return 0;
}