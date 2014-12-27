#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

#define LL __int64

using namespace std ;
int n ;

class Point
{
public:
       int x , y ;
       int hash ;

       Point() {}
       Point( int _ , int __ ) 
       {
              x = _ ; y = __ ;
              int tx , ty ;
              if( x < 0 ) tx = (-x) + 20000 ;
              else tx = x ;
              if( y < 0) ty = (-y) + 20000 ;
              else ty = y ;
              hash = ((LL)tx * 100000 + (LL)ty) % 1000000 ;
       }
       friend bool operator == ( const Point& a , const Point& b)
       {
              return (a.x==b.x)&&(a.y==b.y);
       }
}point[1005] ;
class HashTable
{
      struct Node
      {
             Point pt ;
             Node* next;
             Node() { next = NULL ; }
      };
      public:
             Node* head ;
             HashTable() { head = NULL ; }
             void insert(Point x)
             {
                  Node* temp = new Node;
                  temp->pt = x ;
                  temp->next = head ;
                  head = temp ;
             }
             bool find(Point x)
             {
                  Node* temp = head ;
                  while( temp != NULL )
                  {
                         if( temp->pt == x ) return true ;
                         temp = temp -> next ;
                  }
                  return false ;
             }                    
}hash[1000005] ;

inline bool exist(Point x )
{
     return hash[x.hash].find(x) ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while( scanf("%d",&n) == 1 )
    {
           memset(hash , 0 , sizeof(hash)) ;
           if( n == 0 ) break ;
           
           LL ans = 0 ;
           for( int i = 1 ; i <= n ; i ++)
           {
                int x , y ;
                scanf("%d %d",&x,&y);
                point[i] = Point( x , y ) ;
                hash[ point[i].hash ].insert(point[i]) ;
           }
           for( int i = 1 ; i <= n ; i ++)
                for( int j = i + 1 ; j <= n ; j ++)
                {
                     int c1x , c1y , d1x , d1y ;
                     int c2x , c2y , d2x , d2y ;

                     c1y = point[i].y + point[i].x - point[j].x ;
                     d1y = point[j].y + point[i].x - point[j].x ;
                     c2y = point[i].y - point[i].x + point[j].x ;
                     d2y = point[j].y - point[i].x + point[j].x ;
                     
                     c1x = point[i].x + point[j].y - point[i].y ;
                     d1x = point[j].x + point[j].y - point[i].y ;
                     c2x = point[i].x - point[j].y + point[i].y ;
                     d2x = point[j].x - point[j].y + point[i].y ;
                     
                     Point c1(c1x,c1y),d1(d1x,d1y),c2(c2x,c2y),d2(d2x,d2y) ;
                     if( exist(c1) && exist(d1) )
                         ans ++ ;
                     if( exist(c2) && exist(d2) )
                         ans ++ ;
                }
           cout << (ans >> 2) << endl ;       
    }
    
    return 0;
}
