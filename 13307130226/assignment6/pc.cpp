#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int abs(int a){
  return a;
}
int k,n;
int he[111000],ki[111000];
int i,j,g,h;
int gold;

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
  while(1){
  cin >> n >> k;
  if(n == 0 && k == 0)
	return 0;
  for(i=0;i<n;i++)
	cin >> he[i];
  for(i=0;i<k;i++)
	cin >> ki[i];
  qs(he,0,n-1);
  qs(ki,0,k-1);/*
  for(i=0;i<n;i++)
    cout << he[i] << ' ';
  cout << endl;
  for(i=0;i<k;i++)
    cout << ki[i] << ' ';
  cout << endl;
*/
  he[n]=0;
  ki[k]=0;
  i = 0;
  j = 0;
  bool can;
  gold = 0;
  can  = true;
  for(i=0;i<n;i++){
    while(he[i]>ki[j] && j<k)
      j++;
    if(j == k){
      can = false;
      break;
    }
    //cout << i << ' '<<he[i]<< " e " << j <<' '<<ki[j-1]<< endl;
    gold += ki[j];
    ++j;
    
  }
  if(can)
    cout << gold << endl;
  else 
    cout << "Loowater is doomed!" << endl;


  }
}
