#include<iostream>
#include<cstdio>
using namespace std;
int abs(int a){
  return a>0?a:-a;
}
int T,N,n;
int q[51000];
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
  cin >> T >> N;
  for(i=0;i<N;i++)
    cin >> q[i];
  qs(q,0,N-1);
/*
  for(i=0;i<N;i++)
    cout << q[i] << ' ';
  cout << endl;*/
  int now = 0;
  n = 0;
  for(i=0;i<N;i++){
    //cout << now << ' ' << abs(now-q[i]) << ' ' << T << endl;
    if(abs(now - q[i])>T)
      break;
    T -= abs(now - q[i]);
    now = q[i];
    n++;
  }
  cout << n << endl;return 0;
}

