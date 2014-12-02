#include <iostream>
#include <vector>

using namespace std;


void siftdown(vector<int> &a,long i,long long n){
    int t=a[i];
	long long j;
    while((j=i*2+1)<n){
    if(j<n-1&&a[j]<a[j+1])j++;
    if(t<a[j])
        {
         a[i]=a[j];
        i=j;
        }
        else break;
    }
    a[i]=t;

}

void heapsort(vector<int>& a, long long  n){
    int tmp;
    for (long long  j=(n-2)/2;j>=0;j--)siftdown(a,j,n);

    for  (long long i=n-1;i>0;i--){
    tmp=a[0];
    a[0]=a[i];
    a[i]=tmp;
    siftdown(a,0,i);
    }
}


int main()
{
    vector <int> a;
    int k;
    long long m,n;
    char ch;
    cin>>m;
    for(int i=0;i<m;i++){
    cin>>k;
    a.push_back(k);
    }
//input completed

    heapsort(a,m);

    cin>>ch;cin>>ch;cin>>ch;
    cin>>m;
	while(m--){
		cin>>n;
    cout<<a[n-1]<<endl;
    }
    return 0;
}



