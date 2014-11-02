/*Data Structure and Algorithm Analysis in C++
 Mark Allen Weiss
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Type>
void insertionSort(vector <Type> &a,int left,int right)
{
    int j;
    for(int p=left;p<=right;p++)
    {
        Type tmp=a[p];
        for(j=p;j>left&&tmp<a[j-1];j--)
        {
            a[j]=a[j-1];
        }
        a[j]=tmp;
    }
}

template <typename Type>
const Type& median3(vector<Type>&a,int left,int right)//right is  index
{
    int center=(left+right)/2;
    if(a[center]<a[left])
        swap(a[left],a[center]);
    if(a[right]<a[left])
        swap(a[left],a[right]);
    if(a[right]<a[center])
        swap(a[center],a[right]);
        swap(a[center],a[right-1]);
}

template <typename Type>
void quicksort(vector<Type>&a,int left, int right )
{
            if(right-left>=10)
            {
                Type pivot=median3(a,left,right);//index
                int i=left, j=right-1;
                for(;;)
                {
                    while(a[++i]<pivot){}
                    while(pivot<a[--j]){}
                    if(i<j)
                        swap(a[i],a[j]);
                    else
                        break;
                }
                swap(a[i],a[right-1]);
                quicksort(a,left,i-1);
                quicksort(a,i+1,right);
            }
            else
            insertionSort(a,left,right);
}

template <typename Type>
void quicksort(vector<Type>&a)
{
    quicksort(a,0,a.size()-1);
}

int main()
{
    vector<int>a;
    int c,m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>c;
        a.push_back(c);
    }
    quicksort(a);
  for(int i=0;i<m;i++)
    cout<<a[i]<<" ";
    return 0;
}
