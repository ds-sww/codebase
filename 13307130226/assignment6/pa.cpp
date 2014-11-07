#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int abs(int a){
  return a>0?a:-a;
}
int K,N;
int q[111000];
int i,j,g,h;

void qs(int q[],int l,int r){
int x,i,j;
  //cout << "qq " << l << ' ' << r << endl;
  i = l;
  j = r;
  x = abs(q[(i+j)>>1]);
  do{
    while(abs(q[i])<x)++i;
    while(abs(q[j])>x)--j;
    if(i<=j){
      if(i!=j){
	int tmp;
	tmp = q[i];
	q[i] = q[j];
	q[j] = tmp;
      }
      ++i;--j;
    }
  }while(i<j);
  if(i<r)qs(q,i,r);
  if(j>l)qs(q,l,j);

}

int main(){
string a;
  cin >> N;
  for(i=0;i<N;i++)
    cin >> q[i];
  qs(q,0,N-1);
  cin >> a;
  cin >> K;
  for(i=0;i<K;++i){
  cin >> j;
  cout << q[j-1] << endl;
}
return 0;
}

