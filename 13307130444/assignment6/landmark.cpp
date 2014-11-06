#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct landmark{
	long long distance;
	bool direction;


};

bool operator <(landmark a,landmark b){
	if (a.distance<b.distance)
		return true;
	else return false;
}

void siftdown(vector<landmark> &a,long i,long long n){
    landmark t=a[i];
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

void heapsort(vector<landmark>& a, long long  n){
    landmark tmp;
    for (long long  j=(n-2)/2;j>=0;j--)siftdown(a,j,n);
    for  (long long i=n-1;i>0;i--){
    tmp=a[0];
    a[0]=a[i];
    a[i]=tmp;
    siftdown(a,0,i);
    }
}

long long work( long long T,  vector<landmark> &a)
{
	long long n=a.size(),sum=0,i;
	for( i=0;i<n&&T>sum;i++){

		if(i==0){
			sum+=a[i].distance;
		}
		else{
			int s=-1;
			if(a[i].direction!=a[i-1].direction)s=1;
			sum+=a[i].distance+s*a[i-1].distance;
		}
	}
	if(T<sum)return i-1;
	 return i;
}



int main()
{
    vector <landmark> a;
    landmark lm;
    long long X,T,N;
    cin>>T;
	cin>>N;
    for(long long i=0;i<N;i++){
		cin>>X;
		if(X>0){
			lm.distance=X;
			lm.direction=true;
		}
		else{
			lm.distance=-X;
			lm.direction=false;
		}
		a.push_back(lm);
    }
//input completed

    heapsort(a,N);
	cout<<work(T,a);
	return 0;
}


