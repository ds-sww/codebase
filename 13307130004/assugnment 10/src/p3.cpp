#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	long long T,l,h,mid,ans,n,m,sum,temp,i;
   	scanf("%lld",&T);
   	for(long long t=0;t<T;t++){
      scanf("%lld%lld",&n,&m);
      l=-9999999999 ;
      h=9999999999;
      while(l<=h){
        mid=(l+h)/2;
        sum=0;
        for(i=1;i<=n;i++){
      		temp=ceil((sqrt((long double)((100000+i)*(100000+i)-4*(i*i-100000*i-mid)))-100000-i)/2.0);
      		if(temp>n)
      			temp=n+1;
      		else if(temp<1)
      			temp=1;
      		sum+=n+1-temp;
   		}
        if(sum>n*n-m){
           ans=mid;
           l=mid+1;
        }
        else
           h=mid-1;
    }
    cout<<ans<<endl;
    }
    return 0;
}