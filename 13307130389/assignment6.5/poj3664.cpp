#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std ;

class Cow
{
	public:
		int first , second , index ;
		Cow() {} ;
		friend bool operator < ( const Cow& a , const Cow& b )
		{
			if( a.first == b.first )
				return a.second > b.second ;
			return a.first > b.first ;
		}
};

int N , K ;

int main()
{
	cin >> N >> K ;
	Cow* cow = new Cow[N+1] ;
	for( int i = 1 ; i <= N ; i ++)
	{
		int a , b ;
		scanf("%d %d",&cow[i].first , &cow[i].second ) ;
		cow[i].index = i ;
	}
	sort( cow + 1 , cow + N + 1 ) ;
	for( int i = 1 ; i <= K ; i ++)
	{
		cow[i].first = cow[i].second ;
	}
	sort( cow + 1 , cow + K + 1 ) ;
	cout << cow[1].index << endl ;
	return 0 ;
}
