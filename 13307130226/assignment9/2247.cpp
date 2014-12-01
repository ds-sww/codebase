#include<iostream>
#include<fstream>
#include<string>
#define minnN 2000000001
using namespace std;
long long ans[10000];
int ansn;
int base[4]={2,3,5,7};
long long tmp,minn;
int main(){
	ansn=1;
	ans[0]=1;
	while(ansn<5842){
		minn=minnN;
		for(int i=0;i<ansn;i++)
			for(int j=0;j<4;j++)
				if((tmp=(ans[i]*base[j]))>ans[ansn-1]&&tmp<minn)
					minn=tmp;
		ans[ansn++]=minn;
	}
	
  int i;string f;
  while(cin >> i){
    if(i==0)return 0;
    cout <<"The " << i;    switch(i%10){
      case 1:f = "st";break;
      case 2:f = "nd";break;
      case 3:f = "rd";break;
      default:f = "th";break;
    }
    if(i%100 < 20 && i%100 > 10)
      f = "th";
	  cout << f << " humble number is " << ans[i-1] << '.'<< endl;
  }
	
return 0;
}