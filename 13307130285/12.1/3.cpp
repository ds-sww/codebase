#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

long long X;
long long  a;
long long l,h,mid,ans;
long long b;

bool tru()
{  
   long long xxx;
   long long sum=0;
   for(long long i=1;i<=a;i++)
   {
      xxx=ceil((sqrt((100000+i)*(100000+i)-4*(i*i-100000*i-mid))-100000-i)/2.0);
      if(xxx>a) xxx=a+1;
      else
          if(xxx<1) xxx=1;
      sum+=a+1-xxx;
   }
   if(sum>a*a-b)
     return true;
   return false;
}
int main()
{
   scanf("%lld",&X);
   for(long long  aa=0;aa<X;aa++)
   {
      scanf("%lld%lld",&a,&b);
      l=-9999999999 ;
      h=9999999999;
      while(l<=h)
      {
         mid=(l+h)/2;
         if(tru())
         {
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
