#include <iostream>
#define N 30
using namespace std;
char preorder[N],inorder[N];
int l;
long long s;
long long com(int m,int n){
  if(n==0) return 1;
  long long temp=1;
  for(int i=0;i<n;i++)
    temp*=(m-i);
  for(int i=1;i<=n;i++)
    temp/=i;
  return temp;
}
void out(int pre,int in, int length){
  if(length==1) return;
  int i,j,k,counter=0;
  char temp=preorder[pre+1];
  for(i=0,j=0,k=1;i<length-1;i++,j++){
    if(inorder[in+i]==temp){
      out(pre+k,in+k-1,j+1);
      j=-1;
      k=i+2;
      temp=preorder[pre+k];
      counter++;
    }
  }
  s=s*com(l,counter);
}
int main(){
  int length;
  while(1){
    cin>>l;
    if(!l) break;
    s=1;
    for(int i=0;i<N;i++){
      preorder[i]='\0';inorder[i]='\0';
    }
    cin>>preorder>>inorder;
    for(length=0;preorder[length]!='\0';length++);
    out(0,0,length);
    cout<<s<<endl;
  }
}
