#include<iostream>
#define N 90000
using namespace std;
int main(){
    int sizee,tail;
    long long sum=0,temp;
    long long a[N],b[N],c[N];
    cin>>sizee;
    for(int i=0;i<sizee;i++)
        cin>>a[i];
    tail=0,b[0]=a[sizee-1],c[0]=1;
    for(int i=1;i<sizee;i++){
        temp=1;
        while(a[sizee-i-1]>b[tail]){
            temp+=c[tail];
            tail--;
        }
        tail++;
        b[tail]=a[sizee-i-1];
        c[tail]=temp;
        temp--;
        sum+=temp;
    }
    cout<<sum<<endl;
}