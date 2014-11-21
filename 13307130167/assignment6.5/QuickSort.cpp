#include <iostream>

using namespace std;

void quick_sort(int a[],int l ,int r){
    if(l+1>=r)      return;
    int i=l;
    int j=r;
    int pole=a[(l+r)/2];
    while(i<j){
        while (i<r&&a[i]<pole)      i++;
        while (j>l&&a[j-1]>pole)    j--;
        if(i<j){
            swap(a[i],a[j-1]);
            i++;
            j--;
        }
        quick_sort(a,i,r);
        quick_sort(a,l,j);
    }
}

int main()
{
    int a[5];
    for(int i=0;i<5;i++)
        cin>>a[i];
        quick_sort(a,0,5);
        for (int i=0;i<5;i++)
            cout<<a[i]<<"\t";
    return 0;
}
