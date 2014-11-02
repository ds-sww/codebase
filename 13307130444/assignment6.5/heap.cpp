#include <iostream>

using namespace std;

void siftdown ( int a[], int i, int n ){
        int j, t;
        t = a[i];
        while( ( j=2*i+1)<n){
            if( j < n-1&&a[j] < a [j+1] )j++;
            if( t < a[j]){
                a[i] = a[j];
                i=j;
            }
            else break;
        }
        a[i]=t;
}

void heap_sort ( int a[], int n ){
        int i, t;
        for( i = ( n - 2) / 2 ; i >= 0 ; i -- ) siftdown( a, i, n) ; for(int i=0;i<7;i++)
        cout<<a[i]<<" ";cout<<endl;
        for( i = n - 1; i > 0; i -- )
        {
            t = a[0];
            a[0] = a[i];
            a[i] = t;
            siftdown( a, 0, i ) ;
        }
}

int main()
{
    int a[100]={200, 50, 500, 20, 30 , 40, 67};
    int m=7;
    heap_sort(a , m);
    for(int i=0;i<m;i++)
        cout<<a[i]<<" ";
cin>>m;
    return 0;
}
