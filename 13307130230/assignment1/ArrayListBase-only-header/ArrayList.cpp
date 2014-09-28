
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"
using namespace std;

template <typename T>
class ArrayList : public List<T> 
{
    private:
        const static int defoultcap = 16;
        int cnt,cap;
         T* array;
    public:
        ArrayList()
        {
            cnt=0; cap=defoultcap;
            array=new T[cap];
        }
        ~ArrayList()
        {
            delete [] array;
        }
        int size() const
        {
            return cnt;
        }
        bool isEmpty() const
        {
            return cnt==0;
        }
        T get(int index) const
        {
            return *(array+index);
        }
        void add(T element)
        {
            if (cnt+1>cap)
            {
                cap*=2;
                T *newarr=new T[cap];
                for (int i=0;i<cnt;i++) newarr[i]=array[i];
                delete [] array;
                array=newarr;
            }
            *(array+cnt)=element;
            cnt++;
        }
        T remove(int index)
        {
            int tmp=array[index];
            for (int i=index;i<cnt-1;i++) array[i]=array[i+1];
            cnt--;
            if (cnt<cap/4&&cap>defoultcap)
            {
                cap/=4;
                T *newarr=new T[cap];
                for (int i=0;i<cnt;i++) newarr[i]=array[i];
                delete [] array;
                array=newarr;
            }
            return tmp;
        }
};
