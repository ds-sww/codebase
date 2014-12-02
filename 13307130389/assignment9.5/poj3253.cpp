#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std ;

int n ;
priority_queue< long long , vector<long long> , greater<long long> > q ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); ;
    long long ans = 0 ;
    cin >> n ;
    for( int i = 0 ; i < n ; i ++)
    {
         long long temp = 0 ;
         cin >> temp ;
         q.push( temp ) ;
    }
    while( -- n )
    {
           int top1 , top2 ;
           top1 = q.top() ; q.pop() ;
           top2 = q.top() ; q.pop() ;
           ans += top1 + top2 ;
           q.push( top1 + top2 ) ;
    }
    cout << ans ;
    return 0;
}
