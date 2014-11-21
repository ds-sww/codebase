#include <iostream>

using namespace std;
/*
void restoreUp(in a[], int k){
    while(k>1&&a[k]>a[(k-1)/2]){
        swap(a[k],a[(k-1)/2]);
        k=(k-1)/2;
    }
}
*/

void restoreDown(int a[], int k, int N){
    while(N>=k*2){
        int j=k*2;
        if(j<N&&a[j]<a[j+1])    j++;
        if(!(a[k]<a[j]))       break;
        swap(a[k],a[j]);
        k=j;
    }
}

void heap_sort(int a[], int l , int r ){
    int k, N=r-l+1;
    int  *pHeap=a+l-1;
    for (k=N/2;k>=1;k--)
        restoreDown(pHeap,k,N);
    while(N>1){
        swap(pHeap[1],pHeap[N]);
        restoreDown(pHeap,1,--N);
    }
}

int main()
{
    int a[5];
    for (int i=0;i<5;i++)
        cin>>a[i];
    heap_sort(a,0,5);
    for(int i=0;i<5;i++)
        cout <<a[i]<<"\t";
    return 0;
}
