#include <iostream>

using namespace std;

int partition(int a[] ,int l, int r){
    int i =l-1,j=r;
    int t=a[r];
    for(;;){
        while (a[++i]<t);
        while (t<a[--j]) if (j==l) break;
        if(i>=j)    break;
        swap (a[i],a[j]);
    }
    swap(a[i],a[r]);
    return i;
}

void quicksort(int a[], int l , int r){
    int i;
    if (r<=l)   return ;
    i = partition(a,l,r);
    quicksort(a,l,i-1);
    quicksort(a,i+1,r);
}

int main()
{
    int db_num;
    cin>>db_num;
    int *db=new int[db_num];
    for (int i=0; i<db_num; i++)
        cin >> db[i];
    quicksort(db,0,db_num-1);
    string sym;
    cin >> sym;
    int que_num;
    cin >>  que_num;
    int query;
    for (int i=0; i < que_num ; i++){
        cin >> query;
        cout << db[query-1]<<endl;
    }
    return 0;
}
