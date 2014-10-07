#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std ;

class Student
{
      public:
             int total , chinese , math , english , id ;
             
             Student() {} ;
             Student( int _chinese , int _math , int _english , int _id )
             {
                      chinese = _chinese ;
                      math = _math ;
                      english = _english ;
                      id = _id ;
                      total = chinese + math + english ;
             }
             
             friend bool operator < (const Student& a , const Student& b)
             {
                  if( a.total == b.total)
                      if( a.chinese == b.chinese )
                          return a.id < b.id ;
                      else return a.chinese > b.chinese ;
                  return a.total > b.total ;
             }
};

int n ;
Student stu[500] ;

int main()
{
#ifdef LOCAL
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
#endif
    scanf("%d",&n);
    int chn , math , eng , id ;
    for( id = 1 ; id <= n ; id ++)
    {
            scanf("%d %d %d",&chn ,&math ,&eng );
            stu[id] = Student( chn , math , eng , id );
    }
    sort( stu + 1 , stu + 1 + n );
    for( int i = 1 ; i <= 5 ; i ++)
         printf("%d %d\n",stu[i].id , stu[i].total);
    return 0;
}
