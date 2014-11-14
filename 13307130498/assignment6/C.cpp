#include<iostream>

using namespace std;

int sort(int arr[],int l,int r){
    if(l>=r)return l;
    int x=arr[l];
    int i=l,j=r;
    while(i<j){
        while(j>=l&&arr[j]>=x)j--;
        if(i>=j){
            arr[i]=x;
            return i;
        }
        arr[i]=arr[j];
        while(i<=r&&arr[i]<=x)i++;
        if(i>=j){
            arr[j]=x;
            return j;
        }
        arr[j]=arr[i];
    }
}

void quicksort(int arr[],int l,int r){
    if(l>=r)return;
    int i=sort(arr,l,r);
    quicksort(arr,l,i-1);
    quicksort(arr,i+1,r);
}

int main(){
    while(1){
        int n,m;
        cin>>n>>m;
        if(n==0&&m==0)break;
        int *heads,*knights;
        heads=new int [n];
        knights=new int [m];
        int i,j,gold;
        for(i=0;i<n;i++)
            cin>>heads[i];
        for(i=0;i<m;i++)
            cin>>knights[i];
        quicksort(heads,0,n-1);
        quicksort(knights,0,m-1);
        for(i=j=gold=0;i<m;i++){
            if(knights[i]>=heads[j]){
                gold+=knights[i];
                if(j==n-1)break;
                j++;
            }
        }
        if(i!=m)cout<<gold<<endl;
        else cout<<"Loowater is doomed!"<<endl;
    }
    return 0;
}

