#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 10100
using namespace std;
int sortt(int *a,int l,int m){
    int i=l-1,j=m,r=a[m],temp;
    for(;;){
        while(a[++i]<r);
        while(a[--j]>r) if(j<=l) break;
        if(j<=i) break;
        temp=a[i];a[i]=a[j];a[j]=temp;
    }
    a[m]=a[i];a[i]=r;
    return i;
}
void qsort(int *a,int l,int m){
    if(m<=l) return;
    int i=sortt(a,l,m);
    qsort(a,l,i-1);
    qsort(a,i+1,m);
}
int main()
{
    int sce,st,fr;
    int num;
    int a[N];
    bool z;
    cin>>sce;
    for(int countt=0;countt<sce;countt++){
        cin>>st>>fr;
        for(int i=0;i<N;i++)
            a[i]=0;
        for(int i=0;i<fr;i++)
            cin>>a[i];
        qsort(a,0,fr-1);
        z=false;
        cout<<"Scenario #"<<(countt+1)<<":"<<endl;
        for(num=0;num<fr;num++)
            if(a[fr-num-1]<st)
                st-=a[fr-num-1];
            else{
                num++;
                cout<<num<<endl;
                z=true;
                break;
            }
        if(!z)
            cout<<"impossible"<<endl;
        cout<<endl;
    }
    return 0;
}