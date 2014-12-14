#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>

#define LL __int64
#define ULL unsigned __int64

using namespace std ;

const int MAXN = 128 * 128 + 200;

int s[MAXN];
int c[MAXN],t[MAXN],t2[MAXN],sa[MAXN];
void buildSA( int m , int n )
{
     int i , *x = t , *y = t2 ;
     for( i = 0 ; i < m ; i ++ ) c[i] = 0 ;
     for( i = 0 ; i < n ; i ++ ) c[ x[i] = s[i] ] ++ ;
     for( i = 1 ; i < m ; i ++ ) c[i] += c[i - 1] ;
     for( i = n - 1 ; i >= 0 ; i -- ) sa[--c[x[i]]] = i ;
     for(int k = 1 ; k <= n ; k <<= 1 )
     {
             int p = 0 ;
             for(i = n - k ; i < n ; i ++) y[p++] = i ;
             for(i = 0 ; i < n ; i ++ ) if( sa[i] >= k ) y[p++] = sa[i] - k ;
             for(i = 0 ; i < m ; i ++ ) c[i] = 0 ;
             for(i = 0 ; i < n ; i ++ ) c[x[y[i]]] ++ ;
             for(i = 1 ; i < m ; i ++ ) c[i] += c[i - 1] ;
             for(i = n - 1 ; i >= 0 ; i -- ) sa[--c[x[y[i]]]] = y[i] ;
             swap(x , y) ;
             p = 1 ; x[sa[0]] = 0 ;
             for(i = 1 ; i < n ; i ++)
                   x[sa[i]] = y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k] ? p-1:p++;
             if(p >= n) break ;
             m = p ;
     }
}

int rank[MAXN] , height[MAXN] ;
void getHeight(int n)
{
     int i , j , k = 0 ;
     for(i = 0 ; i < n ; i ++) rank[sa[i]] = i ;
     for(i = 0 ; i < n ; i ++)
     {
           if( k ) k -- ;
           if(!rank[i]) continue ;
           j = sa[rank[i]-1] ;
           while( s[i+k] == s[j+k] ) k ++ ;
           height[rank[i]] = k ;
     }
}

const ULL modp = 26 ;
const ULL modq = 2000007 ;
int sorted[128*128] = {} ;

char mat[128][128] = {} ;
ULL hash[128][128] = {} ;
ULL str[128*128] = {} ;
ULL sorted_str[128*128] = {} ;

int ans = 0 ;
int cas , T ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    cas = 0 ;
    scanf("%d",&T);
    while( ++ cas <= T )
    {
           int r , c ;
           memset(hash , 0 , sizeof(hash) ) ;
           scanf("%d %d\n",&r,&c) ;
           ans = r*(r+1)/2 ; ans *= c*(c+1)/2 ;
           for(int i = 0 ; i < r ; i ++)
           {
                   for(int j = 0 ; j < c ; j ++)
                           scanf("%c",&mat[i][j]);
                   getchar() ;
           }
           
           for(int w = 1 ; w <= r ; w ++ )
           {
                   int t = 0 , tt = 0 ;
                   memset(str,0,sizeof(str));
                   for(int i = 0 ; i <= r - w ; i ++ )
                           for(int j = 0 ; j < c ; j ++)
                           {
                                   hash[i][j] = (hash[i][j] * modp + (mat[i+w-1][j]-'A'+1)) ;
                                   str[t ++] = hash[i][j] ;
                           }
                   sort(str , str + t) ;
                   for(int i = 0 ; i < t ; i ++)
                           if( str[i] != str[i + 1] )
                               sorted_str[tt ++] = str[i] ;
                   t = tt ; tt = 0 ;
                   int comma = t ;
                   memset(s,0,sizeof(s)) ;
                   for(int i = 0 ; i <= r - w ; i ++)
                   {
                           for(int j = 0 ; j < c ; j ++)
                           {
                                   int left = 0 , right = t - 1 , mid ;
                                   while( left < right )
                                   {
                                          mid = (left + right) >> 1 ;
                                          if( sorted_str[mid] > hash[i][j] )
                                              right = mid - 1 ;
                                          else if( sorted_str[mid] < hash[i][j] )
                                              left = mid + 1 ;
                                          else
                                              break ;
                                   }
                                   if(left == right) mid = left ;
                                   s[tt ++] = mid + 1;
                           }
                           s[tt ++] = ++ comma ;
                   }
                   
                   buildSA( ++ comma , tt ) ;
                   memset(height,0,sizeof(height));
                   getHeight( tt ) ;
                   
                   for(int i = 0 ; i < tt ; i ++)
                   {
                           ans -= height[i] ;
                   }
           }
           
           cout << "Case #" << cas << ": " << ans << endl ;
    }
    
    return 0;
}
