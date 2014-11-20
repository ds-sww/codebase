#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int s(int arr[],int l,int r){
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

void qs(int arr[],int l,int r){
    if(l>=r)return;
    int i=s(arr,l,r);
    qs(arr,l,i-1);
    qs(arr,i+1,r);
}

int main(){
    int N,i;
    cin>>N;
    for(i=0;i<N;i++){
    int x,m;
        scanf("%d%d",&x,&m);
        int all[m];
        int j,k;
        for(j=0;j<m;j++){
            scanf("%d",&all[j]);
        }
        qs(all,0,m-1);
        for(j=m-1;j>=0;j--){
            x=x-all[j];
            if(x<=0)break;
        }
        printf("Scenario #%d:\n",i+1);
        if(j<0)
            printf("impossible\n\n");
        else
            printf("%d\n\n",m-j);
    }

    return 0;
}
