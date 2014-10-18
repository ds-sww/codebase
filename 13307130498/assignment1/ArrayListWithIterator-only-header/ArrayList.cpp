
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include <string>
#include "List.h"
#include <stdexcept>

using namespace std;

template <typename T>
class ArrayList : public List<T> {
    class Iter:public Iterator<T> {
        int Next;
	int last_times;
	ArrayList * outer;
    public:
        Iter(ArrayList * out){
            Next = 0;
	    outer = out;
            last_times = outer->times;
        }
        bool hasNext();
        T next();
    };
    T *Arraylist;
    int Size;
    int max;
    int times;
public:
    ArrayList(){
        Arraylist = new T[1];
        max = 1;
        Size = 0;
	times = 0;
    }
    ~ArrayList(){
        delete[] Arraylist;
    }
    void copy(int p[],int p_size){
        Size = p_size;
        for(int i=0;i<Size;i++)
        {
            Arraylist[i]=p[i];
        }
    }
    void ifisfull(){
        T *p;
        int p_size = Size;
        p = Arraylist;
        Arraylist=new T[2*p_size];
        max = 2*p_size;
        copy(p,p_size);
        delete[] p;
    }
    void ifislessthan20per()
    {
        T *p;
        int p_size = Size;
        p = Arraylist;
        Arraylist=new T[2*p_size];
        max = 2*p_size;
        copy(p,p_size);
        delete[] p;
    }
    Iterator<T>* iterator();
    int size() const;
    bool isEmpty() const;
    T get(int index) const;
    void add(T element);
    T remove(int index);
};

template<typename T>
int ArrayList<T> :: size() const{
    return Size;
}

template<typename T>
bool ArrayList<T> :: isEmpty() const{
    return (Size == 0);
}

template <typename T>
T ArrayList<T> :: get(int index) const{
    if(index<0||index>=Size)
    {
        cout<<"Not Correct Index"<<endl;
        return -1;
    }
    /*for(i=0;i<Size;i++)
	cout<<Arraylist[i]<<"  ";
    cout<<endl;*/
    return Arraylist[index];
}

template<typename T>
void ArrayList<T> :: add(T element){
    if(Size == max)
        ifisfull();
    Arraylist[Size] = element;
    Size++;
    times++;
}

template<typename T>
T ArrayList<T> :: remove(int index){
    if(Size == 0){
        cout<<"No Element Left!"<<endl;
        return -1;
    }
    T aa;
    aa = Arraylist[index];
    for(int i=index+1;i<Size;i++)
        Arraylist[i-1] = Arraylist[i];
    Size--;
    times++;
    if(Size == 0)
    {
        return aa;
    }
    else if(Size*5 <= max)
        ifislessthan20per();
    return aa;
}



template<typename T>
bool ArrayList<T>::Iter::hasNext()
{
    if(last_times!=outer->times)
        throw logic_error("The ArrayList has been changed!");
    else return (Next < outer->Size);
}

template <typename T>
T ArrayList<T>::Iter::next(){
    if(!hasNext())
    {
        cout<<"Error:This is the last!"<<endl;
        return -1;
    }
    return outer->Arraylist[Next++];
}

template<typename T>
Iterator<T> * ArrayList<T>::iterator()
{
    Iter *n = new Iter(this);
    return n;
}



















