#include <iostream>
#define N 100
using namespace std;
int counter,n;
struct t{
  int data;
  t *left,*right;
};
t *build(int i){
  t *t0=new t;
  t0->data=i;
  if(2*i<=N)
    t0->left=build(2*i);
  else
    t0->left=NULL;
  if(2*i+1<=N)
    t0->right=build(2*i+1);
  else
    t0->right=NULL;
  return t0;
}
void p(t *tree){
  if(tree!=NULL&&tree->data<=n){
    cout<<tree->data;
    if(counter<n) cout<<" ";
    counter++;
    p(tree->left);
    p(tree->right);
  }
}
int main(){
  t *tree=build(1);
  while(1){
    cin>>n;
    if(!n) break;
    counter=1;
    p(tree);
    cout<<endl;
  }
  return 0;
}