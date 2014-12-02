#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
   int n;
   long int x;
   int y;
   int *a;
   int pp;
   int num;
   cin >>n;
   for(int i=1;i<=n;i++)
  {
    pp=0;
    cin >> x>>y;
     a=new int[2000];
     for(int j=0;j<y;j++)
     scanf("%d",a+j);
     sort(a,a+y);
     for(long int s=0, z=y-1;z>=0;z--)
     {
     s+=a[z];
     if(s>=x)
     {
        pp=1;
        num=y-z;
        break;
     }
     }




  cout << "Scenario #" << i <<":" <<endl;
  if(pp==1)
   cout << num <<endl<<endl;
  else
    cout<<"impossible"<<endl<<endl;


  }


}
