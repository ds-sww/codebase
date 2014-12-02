#include <iostream>
#include<stdio.h>
#include<cstdlib>

using namespace std;

void inverted_parity_by_quicksort(int a[],int l,int r,int &parity){
    if(l+1>=r)  return;
    int i=l;
    int j=r;
    int pole=a[(l+r)/2];
    while(i<j){
        while (i<r&&a[i]<pole)      i++;
        while(j>l&&a[j-1]>pole)    j--;
        if(i<j){
            swap(a[i],a[j-1]);
            if((j-i)!=1)
                parity=1-parity;
            i++;
            j--;
        }
    }
    inverted_parity_by_quicksort(a,i,r,parity);
    inverted_parity_by_quicksort(a,l,j,parity);
}

int main()
{
    int m,n;
    int *puzzle=new int[m*n];
    int parity;
    int zero_lct;
    int zero_line;
    cin>>m>>n;
    while(m!=0&&n!=0){
        for (int i=0;i <m;i++)
            for(int j=0;j<n;j++){
                scanf("%d",&puzzle[i*n+j]);
//                cin>>puzzle[i*n+j];
                if(puzzle[i*n+j]==0){
                    zero_lct=i*n+j;
                    zero_line=i+1;
                    }
            }
        parity=0;
        inverted_parity_by_quicksort(puzzle,0,m*n,parity);
        int ori_parity=zero_lct-parity+2;
        if (n%2){
            if (ori_parity%2==0)     cout<<"YES"<<endl;
            else if(ori_parity%2)    cout<<"NO"<<endl;
        }
       else if(n%2==0){
            if((m-zero_line)%2){
                if (ori_parity%2==0)    cout<<"NO"<<endl;
                else if(ori_parity%2)   cout<<"YES"<<endl;
                }
            else if((m-zero_line)%2==0){
                if(ori_parity%2==0)     cout<<"YES"<<endl;
                else if(ori_parity%2)   cout<<"NO"<<endl;
            }
        }
    cin>>m>>n;
    }
    int x;
    cin>>x;
  return 0;
}
