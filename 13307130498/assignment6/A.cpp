#include <iostream>
#include <string>
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
    int N,K;
    cin>>N;
    int * ori;
    ori=new int [N];
    int i;
    for(i=0;i<N;i++)
        cin>>ori[i];
    quicksort(ori,0,N-1);
    char a,b,c;
    cin>>a>>b>>c;
    cin>>K;
    int *ord;
    ord=new int [K];
    for(i=0;i<K;i++)
        cin>>ord[i];
    for(i=0;i<K;i++)
        cout<<ori[ord[i]-1]<<endl;


    return 0;
}
