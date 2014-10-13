#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

#define LL long long

using namespace std ;

priority_queue<LL , vector<int> ,greater<int> > q ;
LL sum = 0 ;
int n ;
int main()
{
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
       
       scanf("%d",&n);
       int x , y ;
       for( int i = 1 ; i <= n ; i ++)
       {
            scanf("%d",&x);
            q.push(x) ;
       }
       
       for( int i = 1 ; i <= n-1 ; i ++)
       {
              x = q.top() ; q.pop() ;
              y = q.top() ; q.pop() ;
              sum += x + y ;
              q.push( x + y ) ;
       }
       
       printf("%lld",sum);
       
       return 0;
}
