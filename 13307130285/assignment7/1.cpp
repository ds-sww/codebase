#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(char *a,char *b)
{
   if(strcmp(a,b)>0) return true;
   return false;
}
int main()
{
   int n,m;
   char **a;
   int *b;
   while(1)
   {
     cin>>n>>m;
     if(n==0||m==0) break;
     a=new char*[n];
     b=new int[n];
     for(int i=0;i<n;i++)
     {
         a[i]=new char[21];
         scanf("%s",a[i]);
     }
    sort(a,a+n,cmp);
    int count=0;
    for(int i=1;i<n;i++)
    {
       if(strcmp(a[i],a[i-1])==0)
       {
           count++;
           if(i==(n-1)) b[count]++;
       }
       else
       {
           if(i==(n-1))
          {
             b[0]++;
             b[count]++;
          }
          else
          {
             b[count]++;
             count=0;
          }
       }
    }
     for(int i=0;i<n;i++)
       cout<<b[i]<<endl;
   }
    return 0;
}
