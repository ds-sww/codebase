
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"

#define LL long long

using namespace std;

template <typename T>
class ArrayList : public List<T>
{
        private:
                int Size ;
                int UsedSize ;
                T* arr ;

                void checkSize()
                {
                        if( UsedSize >= Size )
                        {
                                T* temparr = new T[ Size << 1 ];
                                for(int i = 0 ; i < Size ; i ++)
                                        temparr[i] = arr[i] ;
                                Size <<= 1 ;
                                delete arr ;
                                arr = temparr ;
                        }
                        else if( UsedSize < ( Size >> 2 ) )
                        {
                                T* temparr = new T[ Size >> 1] ;
                                for(int i = 0 ; i < (Size>>1) ; i ++)
                                        temparr[i] = arr[i] ;
                                Size >>= 1 ;
                                delete arr ;
                                arr = temparr ;
                        }
                }
        public:
                ArrayList()
                {
                        Size = 2 ;
                        UsedSize = 0;
                        arr = new T[2] ;
                }
                int size() const
                {
                        return UsedSize ;
                }
                bool isEmpty() const
                {
                        return !((bool)UsedSize);
                }
                T get( int index ) const
                {
                        return arr[index];
                }
                void add( const T& element )
                {
                        checkSize() ;
                        arr[ UsedSize ++ ] = element ;
                }
                T remove( int index )
                {
                        T temp ;
			if( index >= UsedSize ) { cerr << "No such element." << endl ; return temp ;}
                        temp = arr[index];
                        for(int i = index ; i < UsedSize ; i ++)
                                arr[i] = arr[i + 1] ;
                        UsedSize -- ;
                        checkSize();
                        return temp ;
                }
};
