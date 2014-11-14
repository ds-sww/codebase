
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <exception>
#include "List.h"

using namespace std;

template <typename T>
class ArrayListIterator ;

template <typename T>
class ArrayList : public List<T> {
        private:
                int Size ;
                int UsedSize ;
                T* arr ;
                long long ArrayChanged ;

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
                        ArrayChanged = 0;
                }
                long long getArrayStatus() const { return ArrayChanged ; }
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
                        ArrayChanged ++ ;
                }
                T remove( int index )
                {
                        T temp ;
						if( index >= UsedSize ) { cerr << "No such element." << endl ; return temp ;}
						ArrayChanged ++ ;
                        temp = arr[index];
                        for(int i = index ; i < UsedSize ; i ++)
                                arr[i] = arr[i + 1] ;
                        UsedSize -- ;
                        checkSize();
                        return temp ;
                }
                //----------function of iterator----------
                Iterator<T>* iterator()
                {
			ArrayListIterator<T>* itr ;
			itr = new ArrayListIterator<T>(this) ;
			return (Iterator<T>*)itr ;
                }
};

template <typename T>
class ArrayListIterator: protected Iterator<T>
{
    protected:
	ArrayList<T>* arrlist ;
	int NowPos ;
	long long ArrStatus ;
   public :
	ArrayListIterator(ArrayList<T>* ait)
	{
		arrlist = ait ;
		NowPos = 0 ;
		ArrStatus = ait -> getArrayStatus() ;
	}
	T next()
	{
                if( arrlist->getArrayStatus() != ArrStatus ) { throw logic_error("Array has changed!") ; return T(); }
                return arrlist->get( NowPos ++ ) ;
        }
        bool hasNext()
        {
                if( arrlist->getArrayStatus() != ArrStatus ) { throw logic_error("Array has changed!") ; return false ;}
                if( NowPos < arrlist -> size() ) return true ;
                return false ;
        }
};

