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

int main(){
        int n,m;
        int cost,knt_num,check_knt;
        while (cin>>n>>m){
            if (n==0&&m==0)     break;
        int *head=new int[n];
        int *knt=new int[m];
        for (int i=0 ; i<n ; i++)
            cin >> head[i];
        for (int j=0; j<m; j++)
            cin >> knt[j];
        quicksort(head,0,n-1);
        quicksort(knt,0,m-1);
        cost=0;
        knt_num=0;
        check_knt=0;
        for (int i=0; i<n; i++){
                for (int j=check_knt;j<m ;j++){
                    check_knt++;
                    if (knt[j]>=head[i]) {
                        cost+=knt[j];
                       knt_num++;
                       break;
                    }
                }
            }
        if (knt_num!=n)
            cout << "Loowater is doomed!"<<endl;
        else if (knt_num==n)
            cout << cost<<endl;
        }
        return 0;
}
