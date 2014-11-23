#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int s(char arr[][21],int l,int r){
    char x[21];
    strcpy(x,arr[l]);
    int i=l,j=r;
    while(1){
        while(j>=l&&strcmp(arr[j],x)>=0)j--;
        if(i>=j){
            strcpy(arr[i],x);
            return i;
        }
        strcpy(arr[i],arr[j]);
        while(i<=r&&strcmp(arr[i],x)<=0)i++;
        if(i>=j){
            strcpy(arr[j],x);
            return j;
        }
        strcpy(arr[j],arr[i]);
    }
}

void qs(char arr[][21],int l,int r){
    if(l>=r)return;
    int i=s(arr,l,r);
    qs(arr,l,i-1);
    qs(arr,i+1,r);
}

int main(){
    int N,M;
    while(1){
        scanf("%d%d",&M,&N);
        if(M==0)break;
        char DNA[20002][21];
        int i,j;
        for(i=0;i<M;i++){
            scanf("%s",&DNA[i][0]);
        }
        qs(DNA,0,M-1);
        char x[21];
        int k;
        int num[M+1],cou[M+1];
        for(i=0;i<M+1;i++){
            cou[i]=num[i]=0;
        }
        strcpy(x,DNA[0]);
        for(i=0,k=0;i<M;i++){
            if(strcmp(x,DNA[i])==0)cou[k]++;
            else{
                strcpy(x,DNA[i]);
                k++;
                cou[k]=1;
            }
        }
        for(i=0;i<=k;i++){
            num[cou[i]]++;
        }
        for(i=1;i<=M;i++)
            cout<<num[i]<<endl;
    }

    return 0;
}


