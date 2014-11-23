#include <iostream>

using namespace std;

void merge_sort(int a[], int l, int r){
    if(l+1>=r)      return;
    int mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid,r);
    int lp=l;
    int rp=mid;
    static int aux[100];
    for (int i=l;i<r;i++){
        if (lp==mid)
            aux[i]=a[rp++];
        else if(rp==r)
            aux[i]=a[lp++];
        else if(a[lp]<a[rp])
            aux[i]=a[lp++];
        else
            aux[i]=a[rp++];
    }
    for (int i=l;i<r;i++)
        a[i]=aux[i];
}

int main()
{
    int a[5];
    for (int i=0;i<5;i++)
        cin>>a[i];
    merge_sort(a,0,5);
    for (int i=0;i<5;i++)
        cout <<a[i]<<"\t";
    return 0;
}
